#include <16f877a.h>
#fuses RC, NOWDT, NOBROWNOUT, NODEBUG, NOPUT, NOPROTECT, PUT
#USE delay(clock=3M)
#include <mod_lcd.c>

void main()
{   
   while (true)  
   {
   lcd_ini(); // Inicializa o LCD
   lcd_escreve ('\f'); // limpa o display
   lcd_pos_xy (1, 2); // Posiciona cursor no LCD
   printf (lcd_escreve, " Hello World!! "); //Escreve mensagem no LCD
   delay_ms(500);   
   }
}  
