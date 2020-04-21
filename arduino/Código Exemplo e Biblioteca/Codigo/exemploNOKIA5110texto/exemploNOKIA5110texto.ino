#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// pin 12 - Serial clock out (SCLK)
// pin 11 - Serial data out (DIN)
// pin 10 - Data/Command select (D/C)
// pin 9 - LCD chip select (CS/CE)
// pin 8 - LCD reset (RST)

//aqui os pinos ficaram invertido na biblioteca em relação a montagem
//por isso mudei de
//Adafruit_PCD8544 display = Adafruit_PCD8544(12, 11, 10, 9, 8);
//para
Adafruit_PCD8544 display = Adafruit_PCD8544(12, 11, 10, 9, 8);


void setup()   
{
  Serial.begin(9600);
  display.begin();

}

void loop()
{
  display.setContrast(50); //Ajusta o contraste do display
  display.clearDisplay();   //Apaga o buffer e o display
  display.setTextSize(1);  //Seta o tamanho do texto
  display.setTextColor(BLACK); //Seta a cor do texto
  display.setCursor(0,0);  //Seta a posição do cursor
  
  display.setTextColor(BLACK, WHITE);//Texto invertido - Branco com fundo preto
  display.println("Arduino &     Android!");//Escreve no display  


  display.setCursor(0,20);  //Seta a posição do cursor
  display.setTextSize(2);  //Altera o tamanho do texto
 
  display.print("Arduino"); //Escreve no display
  display.display(); //exibe no display
  delay(3000); 
  display.clearDisplay(); //limpa o display
  
  
  display.setTextSize(1); //Seta tamanho 1 para a fonte
  display.print("Teste         de            Display");
  display.display(); //Exibe no display
  delay(3000);
  display.clearDisplay();//limpa o display
}
