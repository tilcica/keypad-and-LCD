# keypad-and-LCD
keypad with LCD screen on arduino 

## navodila naloge
Elektronska ključavnica 1: Na voljo imate 9 tipk (številke 1 do 9 na tipkovnici 3x4 "keypad"). S pravilno kombinacijo 4 številk (npr. 6789) odpremo ključavnico (zelena LED). Vsaka napaka vrne krmilje v izhodiščni položaj. Vpis kombinacije je mogoč samo, če je vklopljeno stikalo na pozicijo 1. 

## navodila za uporabo:
- tipke 0-9: vpisovanje številk
- tipka #: (RESET) se uporabi za brisanje trenutno napisanih številk in "resetiranje" zaslona
- tipka \*: (SET) se uporabi za nastavljanje novega gesla. po pritisku vpišemo novo geslo, nato pa vpišemo še staro geslo

## kosovnica
- 1x LCD 16x2
- 1x trimmer (
- 1x LED (rdeča)
- 1x LED (zelena)
- 1x keypad 4x3
- 1x arduino uno
- 2x upor 220 Ω
- 1x breadboard

## predlagane izboljšave
- boljša organizacija žic
- boljši izpis na LCD ekranu
- možnost vpisov daljših gesel

## priredbeni seznam
### vhodi
| oznaka v nacrtu | naslov operanda | vrsta kontakta | pomen                          |
|-----------------|-----------------|----------------|--------------------------------|
| tipkovnica      | x0              | N.O.           | pritiskanje gumbov             |
| -> 1            | x1              | N.O.           | izpise 1                       |
| -> 2            | x2              | N.O.           | izpise 2                       |
| -> 3            | x3              | N.O.           | izpise 3                       |
| -> 4            | x4              | N.O.           | izpise 4                       |
| -> 5            | x5              | N.O.           | izpise 5                       |
| -> 6            | x6              | N.O.           | izpise 6                       |
| -> 7            | x7              | N.O.           | izpise 7                       |
| -> 8            | x8              | N.O.           | izpise 8                       |
| -> 9            | x9              | N.O.           | izpise 9                       |
| -> *            | x10             | N.O.           | izpise RESET + resetira zaslon |
| -> 0            | x11             | N.O.           | izpise 0                       |
| -> #            | x12             | N.O.           | izpise SET + spremeni geslo    |
| trimmer         | x13             | N.O.           | uravnavanje kontrasta LCD      |

### izhodi
| oznaka v nacrtu | naslov operanda | aktiven pri   | pomen                     |
|-----------------|-----------------|---------------|---------------------------|
| LCD             | Y0              | "lcd.begin()" | izpis informacij          |
| rdeča LED       | Y1              | "1"           | ključavnica je zaklenjena |
| zelena LED      | Y2              | "1"           | ključavnica je odklenjena |

## shema vezave
![schematic](/schematic.png "shema vezave")
## digitalna oblika vezja
![breadboard](/breadboard.png "breadboard vezava")
## slika vezja
![slika vezave](/slika.png)
## video uporabe vezja
https://user-images.githubusercontent.com/62448600/166870577-f9e1eafc-958f-413d-82eb-7c238101459e.mp4
