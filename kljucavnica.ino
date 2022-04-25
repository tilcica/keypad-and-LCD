#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>

// keypad = 7, 6, 5, 4, 3, 2, 8 (od leve proti desni ko je normalno obrjen keypad)
// LED = rdeča: A2, zelena: A1
// lcd = 9, 10, 11, 12, 13, A0

LiquidCrystal lcd(9, A0, 10, 11, 12, 13); // rs, en, d4, d5, d6, d7

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = { // Priprava tipk tipkovnice
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'R','0','S'}
};
byte rowPins[ROWS] = {7, 6, 5, 4};
byte colPins[COLS] = {3, 2, 8};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS); // Priprava tipkovnice

char key;
String koda = "1234";
String stevilke = "";
bool saving = false;
bool saving2 = false;
String kodaTemp = "";
bool unlocked = false;

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2); // LCD
  pinMode(A1, OUTPUT); // Zelena LED dioda
  pinMode(A2, OUTPUT); // Rdeča LED dioda
}
                    
 void loop(){
  key = keypad.getKey(); // Preveri katero tipko smo pritisnili
  switch (key){
    case 'R': // Resetira LCD zaslon in kljucavnico zaklene
      stevilke = "";
      saving = false;
      saving2 = false;
      unlocked = false;
      
      delay(50);
      lcd.clear();
      delay(50);
      lcd.setCursor(0,0);
      lcd.print("RESET");
      break;
    case 'S': // Nastavi novo geslo
      if(!saving){
        stevilke = "";
        delay(50);
        lcd.clear();
        delay(50);
        lcd.setCursor(0,0);
        lcd.print("Nova koda:");
        lcd.setCursor(0,1);
        saving = true;
      }
      else if(saving2){ // Nastavitev gesla je v drugi fazi - vpisati je treba staro geslo
        if(stevilke.length() == 4 && stevilke == koda){ // Preveri če je vtipkano geslo pravilno in shrani novo geslo
          delay(50);
          lcd.clear();
          delay(50);
          lcd.setCursor(0,0);
          lcd.print("Koda zamenjana");
          koda = kodaTemp;
          saving = false;
          saving2 = false;
          unlocked = false;
        }
        else{ // Konča zamenjavo gesla če je vtipkano geslo napačno
          saving = false;
          saving2 = false;
          delay(50);
          lcd.clear();
          delay(50);
          lcd.setCursor(0,0);
          lcd.print("Napacna koda!");
        }
        stevilke = "";
      }
      else if(saving){ // Nastavitev gesla je v prvi fazi - vpisati je treba novo geslo
        kodaTemp = stevilke;
        if(stevilke.length() != 4){ // Konča zamenjavo gesla če je nepravilna dolžina gesla
          saving = false;
          saving2 = false;
          delay(50);
          lcd.clear();
          delay(50);
          lcd.setCursor(0,0);
          lcd.print("ERROR");
        }
        else{ // Nastavi novo geslo
          saving2 = true;
          delay(50);
          lcd.clear();
          delay(50);
          lcd.setCursor(0,0);
          lcd.print("Stara koda: ");
          lcd.setCursor(0,1);
        }
        stevilke = "";
      }
      break;
    case NO_KEY:
      break;
    default:
      if(stevilke.length() == 0 && !saving && !saving2){ // Preveri če želimo odpreti ključavnico
        delay(50);
        lcd.clear();
      }
      delay(50);
      lcd.setCursor(stevilke.length(),1);
      lcd.print(key);
      stevilke += key;
      if(stevilke.length() == 4 && !saving && !saving2){ // Preveri če je pravilna dolžina vtipkanega gesla
        if(koda.equals(stevilke)){ // Preveri če je vtipkano geslo pravilno in odpre ključavnico
          delay(50);
          lcd.clear();
          delay(50);
          lcd.setCursor(0,0);
          lcd.print("Pravilna koda");
          stevilke = "";
          unlocked = true;
        }
        else{ // Če je vtipkano geslo napačno se ključavnica ne odpre
          delay(50);
          lcd.clear();
          delay(50);
          lcd.setCursor(0,0);
          lcd.print("Napacna koda!");
          stevilke = "";
          saving = false;
          saving2 = false;
        }
      }
  }
  if(unlocked == true){ // Spreminjanje zelene in rdeče LED diode
    digitalWrite(A1, 1);
    digitalWrite(A2, 0);
  }
  else{
    digitalWrite(A1, 0);
    digitalWrite(A2, 1);
  }
}
