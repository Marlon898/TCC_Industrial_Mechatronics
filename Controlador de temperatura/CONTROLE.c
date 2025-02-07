/*###############_PROGRAMA MEDIDOR DE TENS�O AC_#################
#                                                               #
#  AUTOR: MARLON HLATCHUK TAVARES                               #
#  FORMA��O: T�CNOLOGO EM MECATR�NICA INDUSTRIAL                #
#  DATA: 06/12/2013                                             #
#                                                               #
#################################################################

COMANDOS DO LCD:
lcd_ini()                        // Inicializa LCD;
lcd_pos_xy( byte x, byte y)      // Posi��o de texto (x, y);
lcd_escreve( char c)             // Fun��o de escrita no LCD;
*/

#include <16f877A.h> // Biblioteca microcontrolador;
#device ADC=10;      // Configura Adc para 10 bits;
#include <mod_lcd.c> // Biblioteca do display lcd;
#fuses  RC, NOWDT, NOBROWNOUT, NOPUT // Diretivas de compila��o;
#fuses  NOPROTECT, NODEBUG // Diretivas de compila��o;
#use    delay (clock=3M) //Configuracao de clock 3MHz para funcao delay
             
int temp_in;
int temp_set;
int histerese;
int A0;
int A1;
int A3;

void main() 
{
   lcd_ini();  // Inicializa��o do display;
   lcd_pos_xy(2,1); 
   delay_ms(20);
   set_tris_d(0b00000000);
   setup_adc_ports(AN0_AN1_AN3);  //Canal 0 anal�gico;
   setup_adc(ADC_CLOCK_INTERNAL); //Ajuste do clock;
   set_adc_channel(0);           //Habilita o canal (0) para leitura;
   delay_ms(20); 
   
   while (TRUE) 
   {                          
      set_adc_channel(0);           //Habilita o canal (0) para leitura;
      delay_ms(20);                 
      A0 =  read_adc(); //Lectura canal0
      temp_in = (A0/6.35); // Converte o valor em bits para graus (linear - Ajustar depois para curva)
      delay_ms(20); 
      
      set_adc_channel(1);           //Habilita o canal (0) para leitura;
      delay_ms(20);                 
      A1 =  read_adc(); //Lectura canal0
      temp_set = ((A1/23.18) +36); // Ajusta o setup para 37 � 47
      delay_ms(20); 
      
      set_adc_channel(3);    //Habilita o canal (0) para leitura;
      delay_ms(20);                 
      A3 =  read_adc(); //Leitura canal0
      histerese = A3/51; // Ajusta histerese para 0 a 11 �C
      delay_ms(20); 
      
       if (temp_in<temp_set)
          {
           output_d(0b10000000);
           delay_ms(20);
          
           set_adc_channel(0);    //Habilita o canal (0) para leitura;
           delay_ms(20);                 
           A0 =  read_adc(); //Lectura canal0
           temp_in = (A0/6.35); // Converte o valor em bits para graus (linear - Ajustar depois para curva)
           delay_ms(20);   
           
           set_adc_channel(1);   //Habilita o canal (1) para leitura;
           delay_ms(20);                 
           A1 =  read_adc(); //Leitura canal 1
           temp_set = (A1/23.18) +36; // Ajusta o setup para 37 � 47
           delay_ms(20); 
           
           printf(lcd_escreve,"\f Tin:%2u   H:%2u\n Tset: %2u ", temp_in, histerese, temp_set);
           delay_ms(20);
           break;
           }
        else 
           {
           output_d(0b00000000);
           delay_ms(20);
           
           set_adc_channel(0);    //Habilita o canal (0) para leitura;
           delay_ms(20);                 
           A0 =  read_adc(); //Lectura canal0
           temp_in = (A0/6.35); // Converte o valor em bits para graus (linear - Ajustar depois para curva)
           delay_ms(20); 
           
           set_adc_channel(1);   //Habilita o canal (1) para leitura;
           delay_ms(20);                 
           A1 =  read_adc(); //Leitura canal 1
           temp_set = (A1/23.18) +36; // Ajusta o setup para 37 � 47
           delay_ms(20); 
           
           set_adc_channel(3);    //Habilita o canal (0) para leitura;
           delay_ms(20);                 
           A3 =  read_adc(); //Leitura canal0
           histerese = A3/51; // Ajusta histerese para 0 a 11 �C
           delay_ms(20); 
           
           printf(lcd_escreve,"\f Tin:%2u   H:%2u\n Tset: %2u ", temp_in, histerese, temp_set);
           delay_ms(20);
           break;
           
           if ((temp_set-histerese)>temp_in)
               {
                output_d(0b10000000);
                delay_ms(20);
                
                printf(lcd_escreve,"\f Tin:%2u   H:%2u\n  Tset: %2u ", temp_in, histerese, temp_set);
                delay_ms(20);
                break;
               }
           }
     }
}
