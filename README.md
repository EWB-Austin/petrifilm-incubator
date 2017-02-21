# petrifilm-incubator
A low-cost, portable Petrifilm(TM) Incubator for doing in-country bacterial analysis of water quality for EWB.

<p>
<iframe width="560" height="315" src="https://www.youtube.com/embed/0SzoYT8wLo0" frameborder="0" allowfullscreen>
</iframe>
</p>


Watch a 3-minute introductory [video](https://youtu.be/oRjXajOAyl0)!


## Problem

Engineers Without Borders does wonderful work providing better-quality water to under-developed communities. Essential
to this is water quality analysis. The 3M Petrifilm(TM) is a widely used way of assessing bacteria load. It requires that
inocultated films be incubated at precise temperatures. Generally, EWB works in communities that have no electrical grid.
The problem then is to reliably incubate the Petrifilm with battery power.

EWB has discoverd that by doing this locally rather than sending the films to a lab, we build trust with the local communities.

An EWB Austin member, Anjan Contractor, led the creation of an initial prototype.  However, it is fragile and undocumented.
This project intends to build a robust, cheap, easy-to-make, easy-to-use, well-documented extension of this prototype.

![incubatordiagram](https://cloud.githubusercontent.com/assets/5296671/9851514/a24c005c-5abe-11e5-8877-42f4bad16fff.png)

## Commercial Solutions

<p> Eric found the following potential commercial solutions:
[Compact Incubator](http://nelsonjameson.com/Compact-Incubator-p1298.html)  This is $94. We are trying to determine if this can be used with a 12 Volt battery. We may buy one for experimentation.
</p>

<p>
[Bigger Incubators](http://www.darwinchambers.com/Portable-Incubators.html)  These don't have prices listed.
</p>

## Notes from November 14th

After purchasing Compact Incubator mentioned above, we find it completely inadequate to our purposes.

We have, however, made signifcant progress in the design of an improved system.

Our basic approach was to purchase a smaller cooler: [http://www.amazon.com/gp/product/B000IBWI42?psc=1&redirect=true&ref_=oh_aui_detailpage_o03_s00](http://www.amazon.com/gp/product/B000IBWI42?psc=1&redirect=true&ref_=oh_aui_detailpage_o03_s00)
and place our Arduino-based system inside it, with the battery on the outside.

![Image of Yaktocat](https://github.com/EWB-Austin/petrifilm-incubator/blob/master/Petrifilm%20Incubator%20Design.png)

## Research Notes

(Thanks to Alice Zhao.)

1-5.
An evaluation of 5 different coliform detection techniques used on-site, including the 3 I talked about in Monday's presentation (Petrifilm, waterworks EZ(which they refer to as just MUG), lacotte multi-tube). They address some of the same issues I brought up, among other useful information.
http://www.ewb-usa.org/files/EWB-USA-TP-104-Fecal-Coliform-Contamination-of-Drinking-Water-an-Evaluation-of-World-Field-Techniques-revc.pdf

6. A 6th method of coliform detection similar to petrifilm but that can be stored at room temperature:
http://www.ewb-usa.org/files/2015/05/AssessmentWaterTestingTechniquesEColi.pdf
Product: http://www.emdmillipore.com/US/en/product/Coli-Count%E2%84%A2-Sampler,MM_NF-MC0010025?bd=1
evaluation of product robustness (for food. full disclaimer I have not read this paper)

7. Colilert is apparently also used by some EWB groups. I thought it was way too expensive when I was initially researching but I may have been wrong. I'll have to do more research on this.

7. A nice blog post of an EWB trip. They used actual petri dishes plates. According to Jen, this is what they use in her workforce when testing for coliform. I don't think this is a top candidate method for us but I like the blog and think we should do something similar for our trip.
http://www.ewbny.org/june_trip_update_part_2_quality_control

8. You asked about "presumative" coliform test and I don't feel like I gave a clear answer. 
Page 2 of this lab manual has a much better explanation.

9. An easy-to-read presentation on water testing in developing countries. Not as informative as it looks at first glance to me, but worth a glance. They seem to advocate using Petrifilm and the human body as an incubator. http://www.ewb-usa.org/files/2015/05/MicrobialTestingOfWater.pdf

10. I was very wrong about the lack of people using Petrifilm for water testing in developed countries. Another advocate of using Petrifilm, among some other techniques:
https://aguainroatan.wordpress.com/2015/07/31/water-testing-in-a-development-context/


Note: here is a different attempt to create that:

http://www.ewb-usa.org/files/2015/05/PortableIncubator.pdf

# Packaging Notes

I now believe it might be both possible and a good idea for us to package the temperature stand into an enclosure that contains the Arduino and the LCD shield.  This would allow the wires to be far better contained and the whole system to be neater. This will really make a big difference in the ruggedness. However, I want to get the EEPROM stuff improved so that we can test the timing.

# Update as of 12/30/2015

I've posted the results of an overnight experiment, in which we used the new EEPROM logging code to record the temperature vs time:
https://github.com/EWB-Austin/petrifilm-incubator/blob/master/TemperatureVsTime1.csv

In summary, it took a long time to warm up, and the battery died after 13 hours.  We really want to stay at 37C for 12 hours on one battery charge, so I consider this a partially successful experiment.

## The Second Prototype

This is our second prototype, based on an Arduino and an LCD shield.  It has now been potentially obsoleted by the third prototype (described below):

![dsc_0597](https://cloud.githubusercontent.com/assets/5296671/13639954/ac2b03d4-e5d8-11e5-8df0-c852a07695bb.jpg)

# Update as of 3/9/2016

Thanks largely due to the work of Evan Bartilson, we now have a third prototpye, which has currently demonstrated a battery life of 35 hours, and which we expect to acheive our goal of 48 hours.

Below are some photos of our team working and the current incubator.

![dsc_0603](https://cloud.githubusercontent.com/assets/5296671/13639945/a0db95ac-e5d8-11e5-8160-d91fef5d147e.jpg)
![dsc_0601](https://cloud.githubusercontent.com/assets/5296671/13639947/a2bc97e0-e5d8-11e5-92d1-4ff7614ec616.jpg)
![dsc_0595](https://cloud.githubusercontent.com/assets/5296671/13639949/a6aaad10-e5d8-11e5-8eeb-9636c5153b34.jpg)

# Our submission to the Rice NEWT Challenge

We have applied to the [Rice University NEWT Global Water Technology Challenge](http://ricenewt.rice.edu/competition/). We have made a short video, which we will post on April 15th after the competition.  Here is the Abstract we submitted:

## Abstract: Engineers Without Borders (EWB-USA), Austin, Petrifilm Incubator 

Providing potable water to the world requires an ability to tell when water is potable. Our experience has been that to be effective, the means of measuring bacteria and explaining it to people in the developing world must be visible, understandable, quantitative enough to support meaningful comparisons, cheap, and be done completely in the field far away from electrical power grids. Petrifilms(™) provided by 3M corporation are a standard way of accomplishing this. They must be incubated at approximately 37C for 48 hours.  This is traditionally done in the field by keeping the films in plastic bags against the skin of engineers in the field. This is uncomfortable, may not provide the correct temperature, and the films are meant to be kept flat and horizontal during incubation.

In US laboratories, commercial incubators cost hundreds or thousands of dollars. These require 110V power. We are building a portable, battery powered incubator that is rugged and reliable enough to use in the third world. This will allows trustworthy in-the-field analysis and comparison of water sources. Because the analysis is done completely locally and results in visible, comparable films, local people will appreciate and trust the result. Although in the US the growth of a single colony is considered a sign of danger, many of the communities that Engineers Without Borders works with cannot afford this level of quality and must have a quantitative tool that lets them compare water sources and water improvements solutions.

Our first prototype used an Arduino microcontroller in a hand-insulated box. Battery life was 18 hours. The operator changed the batteries before they ran out. This was shown to be effective in a remote community in Peru. However, it was fragile. In a second trip a wire broke and could not be repaired by our staff in the field, highlighting to us the importance of documentation and training.

Our second prototype is completely open-source, described at [GitHub. ](https://github.com/EWB-Austin/petrifilm-incubator) This prototype has developed into a third prototype which has held temperature at 37C for 35 hours. We have hopes of extending battery life to 48 hours with small improvements to this basic design. Our overriding goal is to produce a set of open-source instructions that allows anyone in the world to construct and reliably use the portable petrifilm incubator with modest skill and readily available tools at a total cost of $200.


