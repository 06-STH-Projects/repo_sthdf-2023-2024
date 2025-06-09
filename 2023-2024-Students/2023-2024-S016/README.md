# 04.PROJECTS OUTCOMES (2023-2024-S016)

* * *

![Papercraft head](main_head.png)

# Low-poly Music Ambient Visualiser

While enjoying music, we usually focus on the sounds. But imagine adding a visual twist to the beats, especially during parties or family gatherings.

This device doubles as a cool party decoration and a stylish room accessory. It brings a lively visual element to your music experience, making it a versatile addition to any setting.

![Concept](concept.png)

# Description

The system comprises a primary docking base featuring a backlight control mechanism, a bezel equipped with LEDs, and a swappable low-poly head component. Additionally, it offers a versatile and user-friendly design, seamlessly integrating these elements for enhanced functionality and ease of use.

# Analysis

There's no need to reinvent the wheel; practical visualisation solutions, including those compatible with the Arduino platform, are already available. Utilising these existing solutions can not only streamline the development process but also help in minimising unnecessary financial expenditures and saving valuable time.

As for the heads, drawing inspiration from the world of Papercraft, which inherently involves low-poly 3D models, opens up a treasure trove of possibilities. The internet hosts a vast database of freely available 3D models, ready to be employed for various purposes. Leveraging this extensive collection not only ensures a cost-effective approach but also provides a rich resource for diverse and creative head designs, enhancing the overall appeal of your project without breaking the bank.

# Decision

For the main controller will be used already fine documented solution based on Arduino ([Link](https://alexgyver.ru/colormusic/)).

For the swappable heads, we will need a custom design and probably 3D printer.

# Design

Beyond being a mere toy, the device is designed with practical utility in mind. Recognising that switchable heads may accumulate dust during daily use, a solution has been implemented to make them easily detachable and washable, ensuring a hygienic and user-friendly experience.

Furthermore, the universal connector is a key element, intended to not only support current functionalities but also accommodate future improvements seamlessly. In the initial design phase, a magnetic connector was conceived for its convenience. However, after encountering various complications during development, a decision was made to transition to the more conventional pin-based connector, prioritising reliability and ease of use in the final design.

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.16.36.png?version=1&modificationDate=1702289800341&cacheVersion=1&api=v2&width=506&height=478)

:

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.30.06.png?version=1&modificationDate=1702290610022&cacheVersion=1&api=v2&width=515&height=337)![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.30.22.png?version=1&modificationDate=1702290625416&cacheVersion=1&api=v2&width=431&height=283)

Now it is time to document the design. First of all, business diagram tells us a about the design from the business view. Then component diagram will show what components will be used in the solution to achieve defined goals. The last one will provide information about physical components will be used in the solution.

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-10%20at%2021.21.25.png?version=1&modificationDate=1702847368549&cacheVersion=1&api=v2&width=515&height=672)![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-10%20at%2019.47.10.png?version=1&modificationDate=1702847368573&cacheVersion=1&api=v2&width=507&height=386)![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-10%20at%2021.21.01.png?version=1&modificationDate=1702847368581&cacheVersion=1&api=v2&width=515&height=334)

After creating a documented sketch and finalising list of features to be implemented, design was digitalised in the[https://www.tinkercad.com/](https://www.tinkercad.com/).

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.34.54.png?version=1&modificationDate=1702290900341&cacheVersion=1&api=v2&width=597&height=424)

After some design iterations, a need of the **LED holder** was confirmed - switchable head, containing a lot of plastic, should be washable (as mentioned before), so it must not contain any electronics.

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.37.23.png?version=1&modificationDate=1702291046927&cacheVersion=1&api=v2&width=489&height=471)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.38.04.png?version=1&modificationDate=1702291088019&cacheVersion=1&api=v2&width=472&height=418)

After designing a base model and some heads, there is also a need to design an electronical part. It was done with help of the EasyEDA tool ([https://easyeda.com/](https://easyeda.com/) ).

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-11-25%20at%2014.48.49.png?version=1&modificationDate=1702291238336&cacheVersion=1&api=v2&width=594&height=337)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-11-25%20at%2016.35.59.png?version=1&modificationDate=1702291268084&cacheVersion=1&api=v2&width=593&height=424)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-11-25%20at%2018.09.02.png?version=2&modificationDate=1702291586001&cacheVersion=1&api=v2&width=760&height=577)

After the first round of schematics, when we assumed, that 7V power is enough (2x 18650 batteries), we found that our LED strip need a stable 5V input with at least 600 mA power. Arduino can hold up to 500 mA of output power, so we needed a better solution for converting voltage - adding a step-down converter is a common solution.

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.49.01.png?version=1&modificationDate=1702291744845&cacheVersion=1&api=v2&width=400&height=164)![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-11-28%20at%2022.09.07.png?version=1&modificationDate=1702291768368&cacheVersion=1&api=v2&width=760&height=432)![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.49.53.png?version=1&modificationDate=1702291798158&cacheVersion=1&api=v2&width=760&height=368)

# Implementation

Now its time to 3D print heads, buy and solder an electronical part.

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.50.47.png?version=1&modificationDate=1702291851334&cacheVersion=1&api=v2&width=760&height=441)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.52.49.png?version=1&modificationDate=1702291973107&cacheVersion=1&api=v2&width=344&height=182)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.57.34.png?version=1&modificationDate=1702292262969&cacheVersion=1&api=v2&width=760&height=547)

After 3D printing, we needed to remove supports, produced during slicing process in order to prepare 3D model to print. Some of them are easy removable, but sometimes it is hard to remove them clearly.

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2011.59.12.png?version=1&modificationDate=1702292356914&cacheVersion=1&api=v2&width=760&height=544)![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.01.41.png?version=1&modificationDate=1702292505388&cacheVersion=1&api=v2&width=633&height=624)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.02.58.png?version=1&modificationDate=1702292583211&cacheVersion=1&api=v2&width=633&height=320)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.04.02.png?version=1&modificationDate=1702292645983&cacheVersion=1&api=v2&width=633&height=370)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.04.34.png?version=1&modificationDate=1702292679758&cacheVersion=1&api=v2&width=633&height=570)![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.05.15.png?version=1&modificationDate=1702292719310&cacheVersion=1&api=v2&width=633&height=586)

_Soldering process:_

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.08.38.png?version=1&modificationDate=1702292922820&cacheVersion=1&api=v2&width=507&height=456)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.09.05.png?version=1&modificationDate=1702292949749&cacheVersion=1&api=v2&width=314&height=214)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.09.14.png?version=1&modificationDate=1702292958853&cacheVersion=1&api=v2&width=314&height=149)

![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.09.36.png?version=1&modificationDate=1702292981476&cacheVersion=1&api=v2&width=760&height=764)![](https://systemthinking-in-it-student-2023-2024-s016.atlassian.net/wiki/download/thumbnails/2918127/Screenshot%202023-12-11%20at%2012.10.10.png?version=1&modificationDate=1702293015206&cacheVersion=1&api=v2&width=760&height=477)

Now prototype is ready, we can test it.

# Validation, Verification

[Verification.mp4](Verification.mp4)

# Lessons Learned

* Some 3D printed models can have artefacts
* Generated supports sometimes hard to remove
* Soldering can be complicated, then it is useful to fabricate a PCB
* Schematics and simulation is very helpful when dealing with electronics
* Do not reinvent a wheel
* Good documentation = Good project
* Device design some times need to go through cycles to be good enough