#include <16f877A.h> // Biblioteca microcontrolador;
#device adc=10       // Configura o ADC para 10 bits (0 � 1024);
#include <mod_lcd.c> // Biblioteca do display lcd;
#fuses  RC, NOWDT, NOBROWNOUT, NOPUT // Diretivas de compila��o;
#fuses  NOPROTECT, NODEBUG // Diretivas de compila��o;
#use    delay (clock=3M) //Configurac�o de clock para 3MHz; 

#define Tensao PIN_D0

Float A0, A1, L2, L3, P1; // Define vari�vel;

void main() 
{
   lcd_ini();  // Inicializa��o do display;
   lcd_pos_xy(1,2);   
   setup_adc_ports(AN0_AN1_AN3);  //Canal 0 anal�gico;
   setup_adc(ADC_CLOCK_INTERNAL); //Ajuste do clock;
   set_adc_channel(0);           //Habilita o canal (0) para leitura;
   delay_ms(20);                 // Tempo de espera para convers�o;
   
   set_tris_d (0b00000000);
   
   while (TRUE) 
   {      
      //#################################_LEITURA_TENS�O_#######################################################
      
      set_adc_channel(0);           //Habilita o canal (0) para leitura;
      delay_ms(20);
      
      A0 = read_adc();                  //Lectura canal0
         
      L2 = ((A0*12)/614);   // Calibra��o do instrumento (12v = 153bits) Utilizar essa rela��o calibrando com um instrumento real;
      Delay_ms(100);
      
      If (L2>11)
      {
      //#################################_LEITURA_TENS�O_#######################################################
      output_d(0b00000001);
      delay_ms(20);
      set_adc_channel(0);           //Habilita o canal (0) para leitura;
      delay_ms(20);
      
      A0 = read_adc();                  //Lectura canal0
      
      L2 = ((A0*12)/614);   // Calibra��o do instrumento (12v = 153bits) Utilizar essa rela��o calibrando com um instrumento real;
      Delay_ms(20);
      
      //#################################_LEITURA_DA_CORRENTE_######################################################
      
      set_adc_channel(1);           //Habilita o canal (0) para leitura;
      delay_ms(1000);
      A1 = read_adc();                  //Leitura canal0
      L3 = ((10.9*(A1-511))/223);
      Delay_ms(100);
            
      //###############################_C�LCULO_DA_POT�NCIA_########################################################
      
      P1 = (L2*L3); 
      lcd_pos_xy(1,1);
      printf(lcd_escreve,"\f    U:%2.1fv I:%2.1fA \n Potencia:%2.0fw ", L2, L3, P1); // Fun��o para escrever o resultado no display.
      delay_ms (1000);
      }
      else
      {
      output_d(0b00000000);
      delay_ms(20);
      //#################################_LEITURA_TENS�O_#######################################################
      
      set_adc_channel(0);           //Habilita o canal (0) para leitura;
      delay_ms(20);
      
      A0 = read_adc();                  //Lectura canal0
      
      L2 = ((A0*12)/614);   // Calibra��o do instrumento (12v = 153bits) Utilizar essa rela��o calibrando com um instrumento real;
      Delay_ms(100);
      
      //#################################_LEITURA_DA_CORRENTE_######################################################
      
      set_adc_channel(1);           //Habilita o canal (0) para leitura;
      delay_ms(1000);
      A1 = read_adc();                  //Leitura canal0
      L3 = ((10.9*(A1-511))/223);
      Delay_ms(100);
            
      //###############################_C�LCULO_DA_POT�NCIA_########################################################
      
      P1 = (L2*L3); 
      lcd_pos_xy(1,1);
      printf(lcd_escreve,"\f    U:%2.1fv I:%2.1fA \n Potencia:%2.0fw ", L2, L3, P1); // Fun��o para escrever o resultado no display.
      delay_ms (1000);
      
      }
   }
}

