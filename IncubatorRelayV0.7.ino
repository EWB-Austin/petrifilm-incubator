


// Copyright Robert L. Read, <read.robert@gmail.com>, Andrew Wong, Ryan Syed, and Michelle Tate.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <EEPROM.h>

#include <TimerOne.h>

#include <stdint.h>  // CAN ARDUINO USE STDINT.h?


#include <LiquidCrystal.h>
#include <Keypad.h>

//Pin assignments for DFRobot LCD Keypad Shield
LiquidCrystal lcd(8, 9, 4, 5, 6, 7); 
//---------------------------------------------
// Keypad keypad;


 const float MAX_TEMP = 38.0;  //normally 38.0
 const float MIN_TEMP = 36.0;
 const float ALARM_MAX = 37.0;
 const float ALARM_MIN = 20.0; //very low for testing
 
 const int MOSFET_PIN = 3; 
 const int ALARM_PIN = 7;
 
 const int DEBUG_LEVEL = 1;
 
int ledDigitalOne[] = {9, 10, 11}; //the three digital pins of the digital LED 
                                   //9 = redPin, 10 = greenPin, 11 = bluePin

const boolean ON = LOW;     //Define on as LOW (this is because we use a common 
                            //Anode RGB LED (common pin is connected to +5 volts)
const boolean OFF = HIGH;   //Define off as HIGH

//TMP36 Pin Variables
// int temperaturePin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                        //the resolution is 10 mV / degree centigrade 
                        //(500 mV offset) to make negative temperatures an option
                        
int speakerPin = 7;

int length = 4; // high notes for high-temp alarm, low notes for low-temp alarm
char highnotes[] = "cga "; 
int beats[] = { 1, 1, 2, 1};

char lownotes[] = "bac "; 

int tempo = 300;


int numData = 0;  // number of data entries in EEPROM
int dataAddr = sizeof(numData); 
int time_5s = 0;
// <global temperature variable definition goes here>
int ledState = LOW;

volatile unsigned long blinkCount = 0; // use volatile for shared variables


void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}


void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
  
  // play the tone corresponding to the note name
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}

                        
void sound_hot_alarm()
{
       if (DEBUG_LEVEL > 0) 
         Serial.println("Temperature WAY Too Hot, ALARMING_HOT!"); 
       for (int i = 0; i < length; i++) {
         if (highnotes[i] == ' ') {
           delay(beats[i] * tempo);
         } else {
           playNote(highnotes[i], beats[i] * tempo);
         }
       }
}

void sound_cold_alarm()
{
        if (DEBUG_LEVEL > 0) 
          Serial.println("Temperature WAY Too Cool, ALARMING_COLD!"); 
        for (int i = 0; i < length; i++) {
         if (highnotes[i] == ' ') {
           delay(beats[i] * tempo);
         } else {
           playNote(lownotes[i], beats[i] * tempo);
         }
       };
}
                        
void alarm_if_needed(float temp) {
     if (temp < ALARM_MIN) {
     sound_cold_alarm();
   } else if (temp > ALARM_MAX) {
     sound_hot_alarm();
   }
}

void process_input() {
  if (Serial.available()) {
    bool terminator_not_found = true;
    char inChar = Serial.read();
    Serial.println(inChar);
    if (inChar == 'd') {
      Serial.println("dumping");
      print_dump();
    }
    
    if (inChar == 'x') {
          Serial.println("clearing");
      clear_EEPROM();
    }
    

      char terminator = Serial.read();
      if (terminator != '\n') {
        Serial.print(terminator);
        Serial.println(" : Didn't read terminator successfully.");
      }
  }
}

float get_average_temperature(long vcc) {
   float t5 = getVoltage(A5,vcc); 
   float tc5 = (t5 - .5) * 100.0; 
   float t4 = getVoltage(A4,vcc); 
   float tc4 = (t4 - .5) * 100.0; 
   float t3 = getVoltage(A3,vcc); 
   float tc3 = (t3 - .5) * 100.0;    
   float t2 = getVoltage(A2,vcc); 
   float tc2 = (t2 - .5) * 100.0;
   Serial.print("t5 = ");
   Serial.println(t5);
   Serial.println(tc5);
   int rawRead;
   rawRead = analogRead(A5);
   Serial.println(rawRead);
   Serial.print("t4 = ");
   Serial.println(t4);
   Serial.println(tc4);
   rawRead = analogRead(A4);
   Serial.println(rawRead);
   Serial.print("t3 = ");
   Serial.println(t3);
   Serial.println(tc3);
   rawRead = analogRead(A3);
   Serial.println(rawRead);
   Serial.print("t2 = ");
   Serial.println(t2);
   Serial.println(tc2);
   rawRead = analogRead(A2);
   Serial.println(rawRead);

          
   float avg = (tc2+tc3+tc4+tc5)/ 4.0;
   return avg;
                                                  
}
 
void loop()                     // run over and over again
{
 Serial.println("VCC = ");
  long vcc = readVcc();
   Serial.println(vcc);
   lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("VCC: ");
 lcd.print(vcc);
 delay(2000);
  
  process_input();
  
 float temperature = getVoltage(A5,vcc);  //getting the voltage reading from the temperature sensor
 temperature = (temperature - .5) * 100;          //converting from 10 mv per degree wit 500 mV offset
                                                  //to degrees ((volatge - 500mV) times 100)
 int rawRead = analogRead(A5);
// Serial.println(rawRead);
 
temperature = get_average_temperature(vcc);
 Serial.print("temp:");
 Serial.println(temperature);                     //printing the result


 // print to LCD screen
 lcd.clear();
 lcd.setCursor(0, 0);
 lcd.print("Temp: ");
 lcd.print (temperature);
   if (temperature < MIN_TEMP) {
       if (DEBUG_LEVEL > 0) 
         Serial.println("Temperature Too Cool, turning On!"); 
         lcd.setCursor(0,1);
         lcd.print("2 Cool - Pad ON");
     digitalWrite(MOSFET_PIN, HIGH);
//     turn_MOSFET_ON(100.0);
   } else if (temperature > MAX_TEMP) {
       if (DEBUG_LEVEL > 0) 
         Serial.println("Temperature Too Hot, turning Off!"); 
         lcd.setCursor(0,1);
         lcd.print("2 Hot - Pad OFF");
     digitalWrite(MOSFET_PIN, LOW);
//     turn_MOSFET_ON(0.0);

   } else {
     // do nothing!
     if (DEBUG_LEVEL > 0) 
         Serial.println("Temperature OK, turning Off!"); 
        digitalWrite(MOSFET_PIN, LOW);
   }
   alarm_if_needed(temperature);
   
 //  record_temp(temperature);
   delay(5000);
}

void turn_MOSFET_ON(float percent){
  int pwm = (percent * 256) / 100;
  pwm = (pwm > 255) ? 255 : pwm;
  if (DEBUG_LEVEL > 0) 
    Serial.println(pwm);
  analogWrite(MOSFET_PIN, pwm);
}

long readVcc() {
  // Read 1.1V reference against AVcc
  // set the reference to Vcc and the measurement to the internal 1.1V reference
  #if defined(__AVR_ATmega32U4__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    ADMUX = _BV(REFS0) | _BV(MUX4) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  #elif defined (__AVR_ATtiny24__) || defined(__AVR_ATtiny44__) || defined(__AVR_ATtiny84__)
    ADMUX = _BV(MUX5) | _BV(MUX0);
  #elif defined (__AVR_ATtiny25__) || defined(__AVR_ATtiny45__) || defined(__AVR_ATtiny85__)
    ADMUX = _BV(MUX3) | _BV(MUX2);
  #else
    ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);
  #endif  

  delay(2); // Wait for Vref to settle
  ADCSRA |= _BV(ADSC); // Start conversion
  while (bit_is_set(ADCSRA,ADSC)); // measuring

  uint8_t low  = ADCL; // must read ADCL first - it then locks ADCH  
  uint8_t high = ADCH; // unlocks both

  long result = (high<<8) | low;

  result = 1125300L / result; // Calculate Vcc (in mV); 1125300 = 1.1*1023*1000
  return result; // Vcc in millivolts
}

// this code copied from ARDX (thanks!)

/*
 * getVoltage() - returns the voltage in millivutoes.on the analog input defined by
 * pin
 */
float getVoltage(int pin, long vcc){
 int v = analogRead(pin);
 if (DEBUG_LEVEL > 0) {
   Serial.println("input voltage");
   Serial.println(v);
 }
 return (v * (vcc / 1000.0) / 1024.0); //converting from a 0 to 1023 digital range
                                        // to 0 to 5 volts (each 1 reading equals ~ 5 millivolts
}

void setup(){
  
  // make sure we survive a restart without losing our data!
  int numSamples = 0;  // store number of entries in address 0 - 1 (big endian)
  numSamples = EEPROM.get(0,numSamples);
  numData = numSamples;
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Inc Relay V0.5");
  delay(1500);
  pinMode(MOSFET_PIN,OUTPUT);
  pinMode(speakerPin, OUTPUT);
  pinMode(A5,INPUT);
  pinMode(A4,INPUT);
  pinMode(A3,INPUT);
  pinMode(A2,INPUT);
  

  Serial.begin(9600);  //Start the serial connection with the copmuter
                       //to view the result open the serial monitor 
                       //last button beneath the file bar (looks like a box with an antenae)
                       
  setup_interrupt();
                       
}

const int LED = 13;

// ========================EEPROM DATA DUMP FUNCTIONS==========================
// Authors: Andrew Wong, Ryan Syed, Michelle Tate
// Stores number of data entries in bytes 0 - 1 (needs 10 bits to address 1021 bytes), and temperature data in entries 2 - 1023
// Timer 1 library can be downloaded from: http://www.pjrc.com/teensy/td_libs_TimerOne.html







 // print out EEPROM contents
void print_dump(){
  int i = 0;
  float data = 0.0;
  int numSamples = 0;  // store number of entries in address 0 - 1 (big endian)
  numSamples = EEPROM.get(0,numSamples);
  Serial.print("numSamples = ");
  Serial.println(numSamples);
  while (i < numSamples) {
    EEPROM.get(sizeof(int) + i * sizeof(float),data);
    Serial.print(" i = ");
    Serial.println(i);
    Serial.print(data);
    i++;
  } 
}



void clear_EEPROM(){
  numData = 0;
  EEPROM.put(0,numData);

    // turn the LED on when we're done
  digitalWrite(13, HIGH);

}





 // test interrupt
void blinkLED(void)
{
  if (ledState == LOW) {
    ledState = HIGH;
    blinkCount = blinkCount + 1;  // increase when LED turns on
  } else {
    ledState = LOW;
  }

  digitalWrite(LED, ledState);
}





 // writes 1 byte of data to EEPROM every 360 x 5s = 30 minutes
 // toggles LED to indicate write finished 
 // Note: maximum time betw Timer1 interrupts is 8.3s
void data_dump(){
    Serial.println("RECORD_DATA");
  if (time_5s >= 12){
    
    // Let's get the temp...
     long vcc = readVcc();
    float temperature = get_average_temperature(vcc);
     // store number of entries in address 0x0 - 0x1 
    record_temp(temperature);
     time_5s = 0;
  }
  else{
    time_5s++;
  }
}
  
void record_temp(float temperature) {


     // most sig byte in 0x0, least sig byte in 0x1 (big endian)
//    uint8_t numD_LSB = 0;
//    uint8_t numD_MSB = 0;
//    numD_LSB = numData & 0x00FF;  // mask upper 8 bits
//    numD_MSB = numData & 0xFF00;  // mask lower 8 bits
//    EEPROM.write(0, numD_MSB);
//    EEPROM.write(1, numD_LSB);

        numData++;
    EEPROM.put(0,numData);

    dataAddr = sizeof(int) + numData * sizeof(float);
    
     // store data
    EEPROM.put(dataAddr, temperature);   //NOTE: tempData is a global variable that is the temp measurement

    
     // toggle LED to indicate write is done

    if (ledState == LOW) {
      ledState = HIGH;
      //blinkCount = blinkCount + 1;  // increase when LED turns on
    } else {
      ledState = LOW;
    }

    digitalWrite(LED, ledState);
    // This is a little weird....
 
}

void setup_interrupt() {
  Timer1.initialize(5000000);  // interrupt every 5 seconds
  Timer1.attachInterrupt(data_dump); // array dump to run every 5 seconds
  Serial.begin(9600);
  pinMode(13, OUTPUT);    // initialize the LED pin as an output.
}




