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
 /*pinMode(4, OUTPUT);
 pinMode(5, OUTPUT);
 digitalWrite(4, HIGH);
 digitalWrite(5, HIGH);*/
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
      lcd.print("S2   TE AMO   S2");
      lcd.setCursor(0,1);
      lcd.print("S2   TE AMO   S2");
    }
    if(pag == 1){
      lcd.setCursor(0,0);
      lcd.print("OBRIGADO AMOR   ");
      lcd.setCursor(0,1);
      lcd.print("POR ESSES 3 ANOS");
    }
    if(pag == 2){
      lcd.setCursor(0,0);
      lcd.print("AO TODO SAO :   ");
      lcd.setCursor(0,1);
      lcd.print("36 MESES        ");
    }
    if(pag == 3){
      lcd.setCursor(0,0);
      lcd.print("1095 DIAS       ");
      lcd.setCursor(0,1);
      lcd.print("26280 HORAS     ");
    }
    if(pag == 4){
      lcd.setCursor(0,0);
      lcd.print("JUNTINHOS,      ");
      lcd.setCursor(0,1);
      lcd.print("OBRIGADO POR SER");
    }
    if(pag == 5){
      lcd.setCursor(0,0);
      lcd.print("QUEM VOCE EH,   ");
      lcd.setCursor(0,1);
      lcd.print("OBRIGADO POR    ");
    }
    if(pag == 6){
      lcd.setCursor(0,0);
      lcd.print("TER FEITO DESSES");
      lcd.setCursor(0,1);
      lcd.print("3 ANOS, OS 3ANOS");
    }
    if(pag == 7){
      lcd.setCursor(0,0);
      lcd.print("MAIS FELIZES DA ");
      lcd.setCursor(0,1);
      lcd.print("MINHA VIDA.     ");
    }
    if(pag == 8){
      lcd.setCursor(0,0);
      lcd.print("EMMYLINE VOCE EH");
      lcd.setCursor(0,1);
      lcd.print("TUDO PARA MIM,  ");
    }
    if(pag == 9){
      lcd.setCursor(0,0);
      lcd.print("NAO SEI O QUE   ");
      lcd.setCursor(0,1);
      lcd.print("SERIA DA MINHA  ");
    }
    if(pag == 10){
      lcd.setCursor(0,0);
      lcd.print("VIDA SEM VOCE.  ");
      lcd.setCursor(0,1);
      lcd.print("NAO PRECISO MAIS");
    }
    if(pag == 11){
      lcd.setCursor(0,0);
      lcd.print("TE DIZER O QUAO ");
      lcd.setCursor(0,1);
      lcd.print("IMENSO EH O MEU ");
    }
    if(pag == 12){
      lcd.setCursor(0,0);
      lcd.print("AMOR POR VOCE,  ");
      lcd.setCursor(0,1);
      lcd.print("VOCE SABE, EH   ");
    }
    if(pag == 13){
      lcd.setCursor(0,0);
      lcd.print("IMPOSSIVEL DIZER");
      lcd.setCursor(0,1);
      lcd.print("EM PALAVRAS, OU ");
    }
    if(pag == 14){
      lcd.setCursor(0,0);
      lcd.print("TENTAR          ");
      lcd.setCursor(0,1);
      lcd.print("QUANTIFICAR EM  ");
    }
    if(pag == 15){
      lcd.setCursor(0,0);
      lcd.print("NUMEROS , O QUE ");
      lcd.setCursor(0,1);
      lcd.print("ME RESTA EH TE  ");
    }
    if(pag == 16){
      lcd.setCursor(0,0);
      lcd.print("AGRADECER POR   ");
      lcd.setCursor(0,1);
      lcd.print("TUDO, POR SER   ");
    }
    if(pag == 17){
      lcd.setCursor(0,0);
      lcd.print("MINHA NAMORADA, ");
      lcd.setCursor(0,1);
      lcd.print("POR SER MINHA   ");
    }
    if(pag == 18){
      lcd.setCursor(0,0);
      lcd.print("COMPANHEIRA,    ");
      lcd.setCursor(0,1);
      lcd.print("POR SER MINHA   ");
    }
    if(pag == 19){
      lcd.setCursor(0,0);
      lcd.print("AMIGA, POR SER  ");
      lcd.setCursor(0,1);
      lcd.print("MINHA ANJINHA   ");
    }
    if(pag == 20){
      lcd.setCursor(0,0);
      lcd.print("LINDA, SIM VC EH");
      lcd.setCursor(0,1);
      lcd.print("LINDA, OBRIGADO ");
    }
    if(pag == 21){
      lcd.setCursor(0,0);
      lcd.print("POR MUDAR MINHA ");
      lcd.setCursor(0,1);
      lcd.print("VIDA, E FAZER DE");
    }
    if(pag == 22){
      lcd.setCursor(0,0);
      lcd.print("MIM,O HOMEM MAIS");
      lcd.setCursor(0,1);
      lcd.print("FELIZ DESSE     ");
    }
    if(pag == 23){
      lcd.setCursor(0,0);
      lcd.print("MUNDO, OBRIGADO ");
      lcd.setCursor(0,1);
      lcd.print("POR TUDO.       ");
    }
    if(pag == 24){
      lcd.setCursor(0,0);
      lcd.print("JA SAO 3 ANOS   ");
      lcd.setCursor(0,1);
      lcd.print("MAS MUITOS E    ");
    }
    if(pag == 25){
      lcd.setCursor(0,0);
      lcd.print("MUITOS ANOS     ");
      lcd.setCursor(0,1);
      lcd.print("AINDA VIRAO.    ");
    }
    if(pag == 26){
      lcd.setCursor(0,0);
      lcd.print("HOJE EH DIA 3 E ");
      lcd.setCursor(0,1);
      lcd.print("SAO 3 ANOS DE   ");
    }
    if(pag == 27){
      lcd.setCursor(0,0);
      lcd.print("NAMORO :)       ");
      lcd.setCursor(0,1);
      lcd.print("OBRIGADO S2 S2  ");
    }
    if(pag == 28){
      lcd.setCursor(0,0);
      lcd.print("EmmylineS2Perses");
      lcd.setCursor(0,1);
      lcd.print("DESDE 03/06/2015");
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
