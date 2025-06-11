# Kamerový Systém
## Autori: Filip Vida, Roland Pinke

## Motivácia

Mnoho ľudí má záujem zvýšiť bezpečnosť svojho domova kamerovým systémom, ale existujúce kamerové systémy sú často krát príliš drahé a ponúkajú funkcionality, ktoré bežný používateľ nemá šancu využiť. Pre takýchto ľudí môže byť atraktívnou alternatívou si podobný, jednoduchší a hlavne lacnejší kamerový systém vytvoriť vlastnoručne. Hlavnou časťou nášho systému je mikropočítač Rapsberri Pi, vďaka čomu, ak potenciálny záujemca už časom nebude potrebovať naďalej systém využívať, môže mnohé časti ktoré pri jeho zostrojovaní zakúpil znovupoužiť pri iných projektoch.

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/FaceDetection.png " a title")

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/MotionDetection.png " a title")

## Osobné ciele

Takýto projekt sme si vybrali z niekoľkých dôvodov. Prácou na projekte vo skupine si zvýšime naše schopnosti kolaborácie, a prehĺbime profesíjne vzťahy. Štúdium na FIIT nám neprinieslo mnoho pŕiležitostí venovať sa aj harvérovej časti systémov, pohľad na túto časť pre nás bude prínosný a zaujímavý. Projekt sme tiež vytvorili z už dostupných komponentov, čo bolo výzva pre našu víziju a kreativitu. 

## Náklady na Projekt

Raspberry Pi 3: 43,64 €

Breadboard: 5,96 € (Set spolu s Breadboard)

Servo Motor: 7,14 €

Raspberry Pi Kamera: 16,18 €

Rôzne Káble: 5,96 € (Set spolu s Breadboard)

Raspberry Pi Skrinka: 7,20 €

---------------------------------------------
Spolu: 80.12 €

Aj keď sa môže zdať že boli náklady na projekt z finančnej stránky vysoké, projekt bol koncipovaný a navrhnutý z už dostupných komponentov.

## Potencionálny Biznisový Prínos

- **Bezpečnosť** : Výstup projektu môže slúžiť na bezpečnostné účely. Kamerový systém umiestnený na správnom mieste dokáže zachytiť a reagovať na pohyb.
- **Monitorovanie** : Výstup projektu je vhodný na monitorovacie účely, napríklad zvierat.
- **Automatizácia** : Kamerový systém je jednoducho rozšíriteľný. Dá sa jednoducho naprogramovať reakcie na zachytenie pohybu či tváre.
- **Vzdelávanie a Sebarozvoj** : Pre nás tento projekt slúžil ako mále ponorenie do svetu hardvéru a návrhu hardvérového sýstému, nie len softvéru. Pre budúcich čitateľov projekt poslúži ako pomôcka pri podobných projektoch.

## Biznisová Perspektíva

Kamerový systém je určený pre dva typy používateľov. Prvým je používateľ, ktorého zaujíma biznisová stránka projektu a jej vecný prínos ako je napríklad monitorovanie pozemkov a zvýšenie zabezpečenia priestorov, po prípade môže takýto používateľ hľadať lacnejšie alternatívy vočí existujúcim systémom, ktoré poskytujú funkcionality, ktoré používateľ nevyužije a takýto komplikovaný systém je pre neho zbytočná investícia. Druhým typom používateľa je začiatočník programátor, ktorý sa chce zlepšíť v programovaní a niečo nové sa naučiť. 

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/concept.png " a title")

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/Business.png " a title")

Pri navrhovaný riešenia sme si stanovili tiež požiadavky, ktoré museli byť po skončení projektu splnené.

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/One%20Level%20Requirement%20Hierarchy.png " a title")

Tok programu je opísaný na diagrame nižšie. Po zapnutí programu kamera zaznamenáva obraz. Používateľ môže pomocou šípok ovládať servo a teda aj kameru alebo môže nahrávanie videa vypnúť. Po vypnutí nahrávania je video uložené na SD kartu v zariadení Raspberry PI.

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/activity_updated.png " a title")

## Návrh Zariadenia

Na nižšie uvedenom diagrame komponentov vidíme základný návrh zariadenia. Najdôležitejšími komponentamy. ktoré sú potrebné pre základné správanie sú zariadenie Raspberry Pi a modul Kamery. Servo motor funguje ako dodatočný komponent, ktorý dodáva potencionálnu mobilitu riešieniu. 

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/image.png "a title")

Na obrázku uvedenom nižšie vidíme návrh zapojenia zariadenia. Batérie sú nutné pre funkčnosť servo motora. Servo motor je ovládaný pomocou Raspberry Pi Pinov, konkrétne Pin 12, ktorý je jedným z GPIO portov. Porty je možné vidieť na obrázku nižšie. Uvedené porty sú ekvivalentné k diagramu zapojenia.

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/project_fritz.png "a title")

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/GPIO.png "a title")

## Využité Technológie, Koncepty a Zariadenia

**Raspberry Pi**

Raspberry Pi je séria jednodoskových počítačov vyrobených firmou Raspberry Pi Foundation s cieľom podporiť vzdelávanie v oblasti počítačových vied. Vyšlo niekoľko verzií , aktuálne sú to rady Raspberry Pi 1, Raspberry Pi 2 a  Raspberry Pi 3 , verzia sa líšia výkonnosťou, počtom periférií na doske a počtom dostupných rozšírení. Prvá generácia týchto počítačov bola vydaná v roku 2012 , vývoj pokračuje dodnes.

**Raspbian**

Raspbian je oficiálne podporovaný operačný systém pre systémy Raspberry Pi vyvíjaný firmou Raspberry Pi Foundation. Je optimalizovaný pre ARM procesor ktorý sa nachádza v Raspberry Pi.

**Python**


Programovací jazyk pre bežné účely vydaný v roku 1991. Podporuje objektovo orientované , funkcionálne aj štruktúrované programovanie. Jednou z jeho hlavných výhod je jednoduché a robustné rozširovanie pomocou modulov , ktoré môžu byť dokonca napísané aj v C alebo C++.

**Picamera**

Oficiálna knižnica pre Raspberry Pi kamerový modul a programovací jazyk Python. Umožňuje jednoduchú manipuláciu s kamerou , ukladanie snímok do rôznych formátov pre ďalšie spracovanie alebo rýchle zobrazovanie snímok pre neustále video.

**OpenCV**

OpenCV (Open Source Computer Vision Library) je knižnica pre C, C++, a Python a podporuje operačné systémy Windows, Linux, Mac OS, iOS a Android. Je vydaná pod licenciou BSD a preto je dostupná zdarma pre akademické aj komerčné použitie. Bola vyvinutá z ohľadom na výpočtovú výkonnosť a prácu s aplikáciami v reálnom čase. OpenCV umožňuje spracovanie obrazov napríklad za účel rozpoznania tvárí , pohybu alebo napríklad na spočítanie určitých objektov v obraze či dokonca aj čítanie textu.

**Haar-like features**

Haar-like features sú vlastnosti digitálnych snímok pomocou ktorých vieme na daných snímkach vyhľadávať rôzne tvary, najčastejšie tváre. Táto metóda bola prvý krát navrhnutá v publikácii "Rapid Object Detection using a Boosted Cascade of Simple Features" od autora Paul Viola a Michael Jones v roku 2001. Základom tohto procesu je spracovanie mnohých snímok ktoré obsahujú predmet, ktorý chceme aby sa proces naučil hľadať, ale aj snímok kde sa tento predmet nenachádza. 

**Virtual Network Computing**

Vitrtual Network Computing (VNC) je systém ktorý dokáže graficky zdielať plochy. Na vzdialené ovládanie systému využíva Remote Frame Buffer Protocol (RFBP). Vysiela pokyny z myši a klávesnice z pripojeného počítača, na ten na ktorom beží server a periodicky updatuje grafický záznam z plochy zariadenie, na ktorom sme pripojení. VNC Server, je program na zariadení, ktoré obrazovku zdieľa. VNC viewer (alebo klient) je program ktorý používame na zariadení ktoré sa chce pripojiť na VNC Server.

**Pigpio**

Pigpio je knižnica pre Raspberry Pi ktorá umožňuje kontrolu General Purpose Input Outputs (GPIO). Je funkčná pre každú verziu Raspberry Pi.  Každý GPIO je fyzicky prístupný, niektoré sú rezervované pre využitie systémom. Originálne napísané v C, no bol vydaný oficiálny modul pre Python. Neoficiálne wrappery existujú aj pre jazyky ako Java, Erlang alebo Xojo. Medzi funkcie Pigpio patria napríklad hardvérovo časované PWM na všetkých GPIO portoch či hardvérovo časované servo pulzy.

**FEETECH FS90R Micro Continuous Rotation Servo**

FS90R je mikro servo navrhnuté špecificky na neustálu rotáciu, ponúka lacnú a ľahkú rotáciu pre rôzne prístroje , či už sú to roboty alebo kamery. Pre toto servo existujú aj špecificky vyrobené kolesá pre umožnenie pohybu pre robotov či autá na ovládanie

**Numpy**

Numpy je knižnica pre programovací jazyk Python, pridáva podporu pre veľké, multi-dimenzionálne rady (arrays) a matrice (matrices). Knižnica tiež pridáva vysoko-úrovňové matematické operácie ktoré s radami a matricami pracujú.

**Raspberry Pi Camera Board**

Kamera špecificky navrhnutá pre Raspberry Pi, na prepojenie k Raspberry Pi slúži plochý kábel so špeciálnym CSI rozhraním. Váži 3 gramy, natívne rozlíšenie až 5MPx , 1080p a dosahuje najviac 30fps. Pomer výkonu, veľkosti a ceny tejto kamera z nej robí atraktívnu možnosť pre takéto projekty.
 
## Projekt v Akcii

Na ukážkovom videu je vidno ako kamera zaznamenáva obraz a program dokáže rozpoznať ľudské tváre a označiť ich na videu. 

https://github.com/xvidaf/ImageRepoForSMVIT/raw/main/camera_demo_face_recognition.mkv

Na ukážkovom videu je vidno ako kamerový systém rozpoznal potenciálneho lupiča citlivých dát. Po takomto rozpoznaní môže napríklad poslať zaznamenaný obrázok na mailovú adresu vlastníka kamerového systému. 

https://github.com/xvidaf/ImageRepoForSMVIT/raw/main/security_feed.mkv

Ukážkové video na ktorom je zachytené ako je možné pomocou klávesnice ovládať servo.

https://github.com/xvidaf/ImageRepoForSMVIT/raw/main/camera_demo.mp4

Zostavený kamerový systém

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/project_pic.jpg "a title")

Špecifikácie serva

![Alt text](https://raw.githubusercontent.com/xvidaf/ImageRepoForSMVIT/main/servo_specs.png "a title")
