#include <LCD5110_Graph.h>
 
LCD5110 tela(8,9,10,12,11);
 
//O arranjo gerado pelo programa terá o mesmo nome da imagem
extern uint8_t img[]; //Obtendo o arranjo
 
void setup()
{
 tela.InitLCD();
}
 
void loop()
{
 for (int i=0; i<=160; i++) //laço necessário para o carrinho percorrer a tela toda
 {
 tela.clrScr(); //limpando a tela e o buffer
 tela.drawBitmap(i-63, 0, img, 63, 48); //desenhando a imagem na tela
 tela.update(); //atualizando a tela com as informações armazenadas no buffer
 delay(100); //Aumentando esse tempo a velocidade diminuirá,
 //diminuindo-o a velocidade aumentará
 }
}
