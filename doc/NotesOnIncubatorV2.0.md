# Notes on Incubator V 2.0

I'm assigning the Petrifilm Incubator that we received from Peru the version number 2.0.

## Notes from Conversation with Anjan

The existing incubator control box is set up to drive two incubators. However, we only have one heat-controlled box.
This is why there are so many wires -- one pack of wires is for the second insulated box.

Round battery packs are 12V battery packs.  They drive the Arduinio itself, not the heater.  They are charged using
the aligator clips and the Tenergy charger. They exist to try to keep the Arduino alive through an 18 hour cycle.

An 18 hour cycle is much better for the user, as it allows them a full day away or a full night of sleep before changing
the battery.

These batteries are meant to be connected to the Arduino in parallel to allow a long lifetime.

At present, the connectors that are named the "black" connectors, marked with a piece of tape with the letter "B", 
is broken off.  This needs to be repaird.  These connectors exist to connect the battery packs in parallel to extend
the lifetime of the system.

The blue, 9.8 Amp-hour LiPo batteries are used to drive the heaters.  They may provide 16 hours of heat based on the 
outside temperature.  The green connector with the white female connector is the one to use.  The white connector must
be connected to the red mail connector from the heater box.

When the heater element is on, the green led is on.

The cooper foil was used as a construction material to spread heat evenly within the insulated box.

As far as we know, the petrifilms can be stacked inside the heat-box.  As far as we know, you cannot over-incubate a
petrifilm.  This needs to be tested.

