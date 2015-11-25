# petrifilm-incubator
A low-cost, portable Petrifilm(TM) Incubator for doing in-country bacterial analysis of water quality for EWB.

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



