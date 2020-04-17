#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x3F
#define BLACKLIGHT_PIN 3
#define En 2
#define Rw 1
#define Rs 0
#define D4 4
#define D5 5
#define D6 6
#define D7 7

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(I2C_ADDR,En,Rw,Rs,D4,D5,D6,D7);

const int btnp = 2;  
const int btna = 3;  
int pag = 0;
int ebtna = 0;
int ebtnp = 0;
int menu = 1;
void setup()
{
 lcd.begin (16,2);
 pinMode(btna, INPUT_PULLUP);
 pinMode(btnp, INPUT_PULLUP);
 Serial.begin(9600);
}
 
void loop()
{
  if(menu == 1){
    delay(2000); 
    ebtna = digitalRead(btna);
    ebtnp = digitalRead(btnp);
    if (ebtnp == LOW) {
      if(ebtna == LOW){
        menu = 2;
      }
    }
    
  }
  if(menu == 2){
    lcd.setBacklightPin(BLACKLIGHT_PIN,POSITIVE);
    lcd.setBacklight(HIGH);
    ebtna = digitalRead(btna);
    ebtnp = digitalRead(btnp);
    if (ebtnp == LOW) {
      pag = pag + 1;
    }
    if (ebtna == LOW) {
      pag = pag - 1;
    }
    if(pag == 0){
      lcd.setCursor(0,0);
      lcd.print("Arduino e Cia !!");
      lcd.setCursor(0,1);
      lcd.print("LCD e modulo I2C");
    }
    if(pag == 1){
      lcd.setCursor(0,0);
      lcd.print("pagina1!        ");
      lcd.setCursor(0,1);
      lcd.print("                ");
    }
    if(pag == 2){
      lcd.setCursor(0,0);
      lcd.print("pagina2!        ");
      lcd.setCursor(0,1);
      lcd.print("                ");
    }
    if(pag == 3){
      lcd.setCursor(0,0);
      lcd.print("pagina3!        ");
      lcd.setCursor(0,1);
      lcd.print("                ");
    }
    if(pag == 4){
      lcd.setCursor(0,0);
      lcd.print("pagina4!        ");
      lcd.setCursor(0,1);
      lcd.print("                ");
    }
    if(pag == 5){
      lcd.setCursor(0,0);
      lcd.print("pagina5!        ");
      lcd.setCursor(0,1);
      lcd.print("                ");
    }
    //Serial.println("prox: " + ebtnp);
    //Serial.println("ante: " + ebtna);
    Serial.println(pag);
    delay(200); 
  }
  /*for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(1000);
  }*/
  //delay(1000);
  //lcd.setBacklight(LOW);
  //delay(1000);
}
