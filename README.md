# Grafische Datenverarbeitung 1 - Snake
#### Projekt von [Dirk Hofmann](https://git.ai.fh-erfurt.de/di1846ho)

[Demo-Video GDV1-Snake](https://technischeunivers049-my.sharepoint.com/:v:/g/personal/dirk_hofmann_fhe_technischeunivers049_onmicrosoft_com/EV6PrlxXWthLiX2Co_mA9lcBVB8g6PDa43KTXEBpmKIfGQ?e=26edkX)

[Ausführbare Debug-Exe-Variante](https://technischeunivers049-my.sharepoint.com/:f:/g/personal/dirk_hofmann_fhe_technischeunivers049_onmicrosoft_com/Eq7JBuR3n4VCuponG4sIbFYBoqrg8OL6AOPycBXv6e7-sA?e=t3EsGq)

## Allgemein
Im Rahmen des Moduls Grafische Datenverarbeitung 1 habe ich mich als Abschlussprojekt für das Spiel Snake entschieden. Ich habe das "klassische" Snake mittels C++ programmiert und mit der YoshiX-Bibliothek anzeigen lassen.

## Spielziel
So viel Nahrung wie möglich aufsammeln ohne sich selbst oder die Wand zu berühren.

## Funktionen
- Steuerung der Richtung der Schlange mittels W A S D
- Anzeige der Richtung der Schlange mittels Texturen
- Die Schlange wird mit jeder zweiten aufgenommenen Nahrung schneller
- Kollisionen mit der Wand und Schlange werden erkannt und führen zum Spielende
- Die Nahrung wird zufällig im Spielfeld platziert
- Neustart des Spiels durch drücken beliebiger Taste möglich
- Score System (Nur über Console verfügbar)
- Eigene Texturen (Schlange, Melone und Game Over Screen)
- Coole Sonnenbrille

## Verwendete Bibliotheken

- time.h
- iostream
- vector
- random
- yoshix_fix_function

## Installation

### Anforderungen

- Visual Studio 2022
- Git

### Installtionsschritte

- Repository klonen (https://www.youtube.com/watch?v=dQw4w9WgXcQ)
- In Visual Studio 2022 öffnen und Debug ausführen

### Struktur

Im Ordner /project befindet sich die .sln

Die Codedateien befinden sich unter /project/app

## Herausforderungen

Insgesamt kam es bei den verschiedenen Phaser der Entwicklung zu verschiedenen Herausforderungen, für die aber immer eine Lösung gefunden wurde.

Die größte Hürde zu Beginn war es, eine geeignete Projektstruktur anzulegen bei der auch YoshiX funktioniert. Ich habe deshalb die Projektstruktur der Übungen übernommen.

Weiter war dies das erste Projekt in dem ich mit Vectoren gearbeitet habe, jedoch haben sich diese als sehr nützlich und leicht zu bedienen herausgestellt. 

Während des Projekts war ich manchmal ratlos, warum meine angedachte Logik nicht funktioniert. Meistens war die Logik richtig und der Fehler lag in bei mir selbst geschriebenen Klassen in Form eines einfaches Tippfehlers. Diese Fehler waren sehr ärgerlich.

Eine weitere Herausforderung war die Beschaffung von geeignetes Texturen. Ich habe mich daher entschlossen diese selbst mit GIMP anzufertigen oder für Wand und Boden eine Textur aus der einer Übung  zu verwenden.

Als letztes habe ich mich mit der Anzeige der gefressenen Nahrung beschäftigt. Als ich nach langen probieren aber keine gute Möglichkeit gefunden habe und ich bereits die erforderliche Zeit in das Projekt gesteckt habe, wird der Score über die Console ausgegeben.
