#include <16f877A.h> // Biblioteca microcontrolador;
#device ADC=8;      // Configura Adc para 8bits;
#include <mod_lcd.c> // Biblioteca do display lcd;
#fuses  RC, NOWDT, NOBROWNOUT, NOPUT // Diretivas de compilação;
#fuses  NOPROTECT, NODEBUG // Diretivas de compilação;
#use    delay (clock=3M) //Configuracao de clock 3MHz para funcao delay

// Saídas.
#define IN1 PIN_C3 // Comutação das cargas.
#define IN2 PIN_C2 // Ativa o inversor +.
#define IN3 PIN_C1 // Desliga o neutro da rede e ativa o neutro do inversor.
#define IN4 PIN_C0 // Desativa o + da rede.

// Entradas.
#define TB  PIN_D3 // Tensão suficiente na bateria.

long min=0;
long horas=17;


void main() 
{
   lcd_ini();  // Inicialização do display;
   lcd_pos_xy(1,2); 
   delay_ms(100);
   set_tris_c(0b00000000);
   set_tris_d(0b00001010);
   
   output_c(0b00000000);
   delay_ms(20);
   
while (TRUE) 
   {            
// ##################_CONTA_MINUTOS_###################################   

         min ++;  // incrementa minutos.
         delay_ms(999);
     if (min>59)
         {
            min=0;
            horas++; // incrementa hora.
            delay_ms(20);
         }
                  
// ##################_ZERA_AS_HORAS_###################################

         if(horas==23)  // zera ás horas em 24.
         {        
         horas=17;
         }
         
// ##################_ESCREVE_NO_LCD_###################################

         printf(lcd_escreve,"\f___ \n HORA:%2lu:%02lu", horas, min);
         delay_ms(100); 

                      
// #################_HORÁRIO_DE_PICO_##########################

      if((horas>17)&&(horas<21))  // define tomada de decisão das 21 ás 17.
       {
                      
           output_c(0b00001000);
           delay_us(20);
            
            if(input(pin_D3)==0)
            {
            output_c(0b00001001);
            delay_ms(100);
            printf(lcd_escreve,"\f___ \n HORA:%2lu:%02lu", horas, min);
            delay_ms(100);
            }      
       }    
       
      if((horas<18)||(horas>20))
      {
            output_c(0b00000000);
            delay_us(20);
            
             if(input(pin_D3)==0)
            {
            if(!input(pin_D1)==0)
            {
            output_c(0b00001001);
            delay_ms(50);
            printf(lcd_escreve,"\f___ \n HORA:%2lu:%02lu", horas, min);
            delay_ms(100);
            }
            }
      }


      
    }
}

