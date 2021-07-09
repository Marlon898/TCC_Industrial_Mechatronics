#include <16f877A.h> // Biblioteca microcontrolador;
#device adc=10       // Configura o ADC para 10 bits (0 à 1024);
#include <mod_lcd.c> // Biblioteca do display lcd;
#fuses  RC, NOWDT, NOBROWNOUT, NOPUT // Diretivas de compilação;
#fuses  NOPROTECT, NODEBUG // Diretivas de compilação;
#use    delay (clock=3M) //Configuracão de clock para 3MHz; 


Float A0, L2, L3, P1; // Define variável;
int16 A1, A11, L4;
int i=0;

void main() 
{
   lcd_ini();  // Inicialização do display;
   lcd_pos_xy(1,1);   
   setup_adc_ports(AN0_AN1_AN3);  //Canal 0 analógico;
   setup_adc(ADC_CLOCK_INTERNAL); //Ajuste do clock;
   set_adc_channel(0);           //Habilita o canal (0) para leitura;
   delay_ms(20);                 // Tempo de espera para conversão;
   
   set_tris_d (0b00000000);
   
   while (TRUE) 
   {         
      If(P1>60)
      {
       output_d(0b00000010);
       delay_ms(100);
       
      //#################################_LEITURA_TENSÃO_#######################################################
      set_adc_channel(1);           //Habilita o canal (0) para leitura;
      delay_ms(300);
      
      A0 = read_adc();      //Lectura canal0
      Delay_ms(100);
      L2 = ((A0*123.5)/156);   // Calibração do instrumento (12v = 153bits) Utilizar essa relação calibrando com um instrumento real; 
      
      //#################################_LEITURA_DA_CORRENTE_######################################################
  
      set_adc_channel(0);           //Habilita o canal (0) para leitura;
      delay_ms(300);
 
      A1=0;
      A11=0;
 
      for(i=0;i<32;i++)
      {
      A1 = read_adc();                  //Leitura canal0 
      delay_ms(100);
      A11 = A11+A1;
      delay_ms(100);
      }
               
      L4 = (A11/32);
      delay_ms(30);
     // L3= (((L4-511)*1.41)/3);
      //delay_ms(30);
      L3=L4;  
      
      //###############################_CÁLCULO_DA_POTÊNCIA_########################################################
      P1 = ((L2*L3)/10);
      
      lcd_pos_xy(1,1);
      printf(lcd_escreve,"\f       Pmed:%2.0fw \n U:%2.0fv I:%2.1fA  ", P1, L2, L3, ); // Função para escrever o resultado no display.
      delay_ms (1500);
      
      i=0;
      }
      else
      {
       output_d(0b00000000);
       delay_ms(100);
       
      //#################################_LEITURA_TENSÃO_#######################################################
      
      set_adc_channel(1);           //Habilita o canal (0) para leitura;
      delay_ms(300);
      
      A0 = read_adc();      //Lectura canal0
      Delay_ms(100);
      L2 = ((A0*123.5)/156);   // Calibração do instrumento (12v = 153bits) Utilizar essa relação calibrando com um instrumento real; 
      
      //#################################_LEITURA_DA_CORRENTE_######################################################
  
      set_adc_channel(0);           //Habilita o canal (0) para leitura;
      delay_ms(300);
 
      A1=0;
      A11=0;
 
      for(i=0;i<32;i++)
      {
      A1 = read_adc();                  //Leitura canal0 
      delay_ms(100);
      A11 = A11+A1;
      delay_ms(100);
      }
               
      L4 = (A11/32);
      delay_ms(30);
     // L3= (((L4-511)*1.41)/3);
      //delay_ms(30);
      L3=L4;  
      
      //###############################_CÁLCULO_DA_POTÊNCIA_########################################################
      P1 = ((L2*L3)/10);
      
      lcd_pos_xy(1,1);
      printf(lcd_escreve,"\f       Pmed:%2.0fw \n U:%2.0fv I:%2.1fA  ", P1, L2, L3, ); // Função para escrever o resultado no display.
      delay_ms (1500);
      
      i=0;
      }
     
   }
}

