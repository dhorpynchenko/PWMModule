/*******************************************************
This program was created by the
CodeWizardAVR V3.12 Advanced
Automatic Program Generator
© Copyright 1998-2014 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 28.11.2015
Author  : 
Company : 
Comments: 


Chip type               : ATtiny2313A
AVR Core Clock frequency: 4,000000 MHz
Memory model            : Tiny
External RAM size       : 0
Data Stack size         : 32
*******************************************************/

#include <tiny2313a.h>

#define BUTTON_PLUS PINA.0
#define BUTTON_MINUS PINA.1
#define BUTTON_CHANNEL PIND.1

#define LED_CHANNEL_1 PORTB.5
#define LED_CHANNEL_2 PORTB.6

#define DIGIT_0 PORTB.7
#define DIGIT_1 PORTD.0
#define SHOW_DIGIT_0 DIGIT_0 = 1; DIGIT_1 = 0
#define SHOW_DIGIT_1 DIGIT_1 = 1; DIGIT_0 = 0

// On port B
#define DISPLAY_A PORTB.0
#define DISPLAY_B PORTB.1
#define DISPLAY_C PORTB.2

// On port D
#define DISPLAY_D PORTD.2
#define DISPLAY_E PORTD.3
#define DISPLAY_F PORTD.4
#define DISPLAY_G PORTD.5
#define DISPLAY_DP PORTD.6

// DIGITS
// Clear
#define DISPLAY_CLEAR_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_CLEAR_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_CLEAR DISPLAY_CLEAR_ON_PORTB; DISPLAY_CLEAR_ON_PORTD

// 0
#define DISPLAY_0_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_0_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_0 DISPLAY_0_ON_PORTB; DISPLAY_0_ON_PORTD

// 1
#define DISPLAY_1_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_1_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_1 DISPLAY_1_ON_PORTB; DISPLAY_1_ON_PORTD

// 2
#define DISPLAY_2_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_2_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_2 DISPLAY_2_ON_PORTB; DISPLAY_2_ON_PORTD

// 3
#define DISPLAY_3_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_3_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_3 DISPLAY_3_ON_PORTB; DISPLAY_3_ON_PORTD

// 4
#define DISPLAY_4_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_4_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_4 DISPLAY_4_ON_PORTB; DISPLAY_4_ON_PORTD

// 5
#define DISPLAY_5_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_5_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_5 DISPLAY_5_ON_PORTB; DISPLAY_5_ON_PORTD

// 6
#define DISPLAY_6_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_6_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_6 DISPLAY_6_ON_PORTB; DISPLAY_6_ON_PORTD

// 7
#define DISPLAY_7_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_7_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_7 DISPLAY_7_ON_PORTB; DISPLAY_7_ON_PORTD

// 8
#define DISPLAY_8_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_8_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_8 DISPLAY_8_ON_PORTB; DISPLAY_8_ON_PORTD

// 9
#define DISPLAY_9_ON_PORTB PORTB &= 0xFF & (0 << DISPLAY_A) & (0 << DISPLAY_B) & (0 << DISPLAY_C)
#define DISPLAY_9_ON_PORTD PORTD &= 0xFF & (0 << DISPLAY_D) & (0 << DISPLAY_E) & (0 << DISPLAY_F) & (0 << DISPLAY_G)& (0 << DISPLAY_DP)
#define DISPLAY_9 DISPLAY_9_ON_PORTB; DISPLAY_9_ON_PORTD

// Declare your global variables here
char current_digit = 0;

void main(void)
{
// Declare your local variables here

// Crystal Oscillator division factor: 1
#pragma optsize-
CLKPR=(1<<CLKPCE);
CLKPR=(0<<CLKPCE) | (0<<CLKPS3) | (0<<CLKPS2) | (0<<CLKPS1) | (0<<CLKPS0);
#ifdef _OPTIMIZE_SIZE_
#pragma optsize+
#endif

// Input/Output Ports initialization
// Port A initialization
// Function: Bit2=In Bit1=In Bit0=In 
DDRA=(0<<DDA2) | (0<<DDA1) | (0<<DDA0);
// State: Bit2=P Bit1=P Bit0=P 
PORTA=(1<<PORTA2) | (1<<PORTA1) | (1<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRB=(0<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=P Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTB=(1<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port D initialization
// Function: Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=In Bit0=In 
DDRD=(1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=P Bit0=P 
PORTD=(0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (1<<PORTD1) | (1<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0A output: Disconnected
// OC0B output: Disconnected
TCCR0A=(0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
TCCR0B=(0<<WGM02) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0A=0x00;
OCR0B=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: 4000,000 kHz
// Mode: Fast PWM top=0x00FF
// OC1A output: Non-Inverted PWM
// OC1B output: Non-Inverted PWM
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer Period: 0,064 ms
// Output Pulse(s):
// OC1A Period: 0,064 ms Width: 0 us// OC1B Period: 0,064 ms Width: 0 us
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (1<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (1<<WGM12) | (0<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<TOIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<ICIE1) | (0<<OCIE0B) | (0<<TOIE0) | (0<<OCIE0A);

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// Interrupt on any change on pins PCINT0-7: Off
// Interrupt on any change on pins PCINT8-10: Off
// Interrupt on any change on pins PCINT11-17: Off
MCUCR=(0<<ISC11) | (0<<ISC10) | (0<<ISC01) | (0<<ISC00);
GIMSK=(0<<INT1) | (0<<INT0) | (0<<PCIE0) | (0<<PCIE2) | (0<<PCIE1);

// USI initialization
// Mode: Disabled
// Clock source: Register & Counter=no clk.
// USI Counter Overflow Interrupt: Off
USICR=(0<<USISIE) | (0<<USIOIE) | (0<<USIWM1) | (0<<USIWM0) | (0<<USICS1) | (0<<USICS0) | (0<<USICLK) | (0<<USITC);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
// The Analog Comparator's positive input is
// connected to the AIN0 pin
// The Analog Comparator's negative input is
// connected to the AIN1 pin
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
// Digital input buffer on AIN0: On
// Digital input buffer on AIN1: On
DIDR=(0<<AIN0D) | (0<<AIN1D);


while (1)
      {   
      }
}

// TIMER0 interrupt service routine
interrupt [TIM0_OVF] void timer0_int(void)
{

}

void show_digit_value(char value){
   switch(value){
      case 0:
            DISPLAY_0;
      return;
      
      case 1:
            DISPLAY_1;
      return;
      
      case 2:
            DISPLAY_2;
      return;
      
      case 3:
            DISPLAY_3;
      return;
      
      case 4:
            DISPLAY_4;
      return;
      
      case 5:
            DISPLAY_5;
      return;
      
      case 6:
            DISPLAY_6;
      return;
      
      case 7:
            DISPLAY_7;
      return;
      
      case 8:
            DISPLAY_8;
      return;
      
      case 9:
            DISPLAY_9;
      return;
   }
}

void show_digit (char digit){
    
    switch(digit){   
        case 0:
             SHOW_DIGIT_0;
        return;
        
        case 1:
              SHOW_DIGIT_1;
        return;
    }
}
