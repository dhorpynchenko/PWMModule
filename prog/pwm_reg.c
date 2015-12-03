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
#include "pwm_module_hardware.c"

#define DISPLAY_FRAMES_PER_DIGIT 4
#define SETTING_MIN_VALUE 0
#define SETTING_MAX_VALUE 99
#define SETTING_MAX_VALUE_HEX 0x63

#define AUTOINCREMENT_FIRST_STEP 800
#define AUTOINCREMENT_STEP 300

eeprom unsigned char channel_1_setting;
eeprom unsigned char channel_2_setting;

volatile unsigned char channel_1_setting_buffer;
volatile unsigned char channel_2_setting_buffer;

//
volatile unsigned char current_digit = 0;
volatile unsigned char display_frames = 0;
volatile unsigned char current_channel = 0;
volatile unsigned int button_pressed_frames = 0;

volatile bit is_button_plus_was_pressed = 0;
volatile bit is_button_minus_was_pressed = 0;
volatile bit is_button_channel_was_pressed = 0;

volatile bit do_save_channel_1_setting = 0;
volatile bit do_save_channel_2_setting = 0;

void apply_channel_1_value(){
    OCR1AH = 0x00;
  OCR1AL = channel_1_setting_buffer;
}

void apply_channel_2_value(){
    OCR1BH = 0x00;
  OCR1BL = channel_2_setting_buffer;
}  

void init()  {

    #asm("cli");

    // reed from eeprom
  channel_1_setting_buffer = channel_1_setting;
  channel_2_setting_buffer = channel_2_setting;
  
  // do limits check. if eeprom has wrong value 
  // usually triggers on first start
  if(channel_1_setting_buffer > SETTING_MAX_VALUE){
    channel_1_setting_buffer = 0; 
    do_save_channel_1_setting = 1;
  }
  
  if(channel_2_setting_buffer > SETTING_MAX_VALUE){
    channel_2_setting_buffer = 0; 
    do_save_channel_2_setting = 1;
  }
  
  // init timer1 TOP to max value
  ICR1H=0x00;
  ICR1L=SETTING_MAX_VALUE_HEX;
  
  // apply settings for channels
  apply_channel_1_value();
  apply_channel_1_value();
  
  // show channel 1 led
  LED_CHANNEL_1 = 1;
  LED_CHANNEL_2 = 0;
  
  // hide dot
  CLEAR_DISPLAY_DP;
  
  #asm("sei");
}

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
// State: Bit2=T Bit1=P Bit0=P 
PORTA=(0<<PORTA2) | (1<<PORTA1) | (1<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRB=(0<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=P Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTB=(1<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (1<<PORTB2) | (1<<PORTB1) | (0<<PORTB0);

// Port D initialization
// Function: Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRD=(1<<DDD6) | (1<<DDD5) | (1<<DDD4) | (1<<DDD3) | (1<<DDD2) | (1<<DDD1) | (1<<DDD0);
// State: Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTD=(0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 62,500 kHz
// Mode: Normal top=0xFF
// OC0A output: Disconnected
// OC0B output: Disconnected
// Timer Period: 4,096 ms
TCCR0A=(0<<COM0A1) | (0<<COM0A0) | (0<<COM0B1) | (0<<COM0B0) | (0<<WGM01) | (0<<WGM00);
TCCR0B=(0<<WGM02) | (0<<CS02) | (1<<CS01) | (0<<CS00);
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
// OC1A Period: 0,064 ms Width: 0 us
// OC1B Period: 0,064 ms Width: 0 us
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(1<<COM1A1) | (0<<COM1A0) | (1<<COM1B1) | (0<<COM1B0) | (1<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (1<<WGM13) | (1<<WGM12) | (0<<CS12) | (0<<CS11) | (1<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
//ICR1H=0x00;
//ICR1L=0x00;
//OCR1AH=0x00;
//OCR1AL=0x00;
//OCR1BH=0x00;
//OCR1BL=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<TOIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<ICIE1) | (0<<OCIE0B) | (1<<TOIE0) | (0<<OCIE0A);

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

init();
while (1)
      {
      // save to eeprom
          if(do_save_channel_1_setting){ 
               do_save_channel_1_setting = 0;
               channel_1_setting = channel_1_setting_buffer;
          } else if(do_save_channel_2_setting) {
               do_save_channel_2_setting = 0;
               channel_2_setting = channel_2_setting_buffer;
          }

      }
}

void increase_current_channel_setting_buffer(){
      if(current_channel == 0){
         if(channel_1_setting_buffer < SETTING_MAX_VALUE) {
           channel_1_setting_buffer++;
           apply_channel_1_value(); 
         }
      } else {
        if(channel_2_setting_buffer < SETTING_MAX_VALUE) {
           channel_2_setting_buffer++;
           apply_channel_2_value();
        }
      }
}

void decrease_current_channel_setting_buffer(){
    if(current_channel == 0){
        if(channel_1_setting_buffer > SETTING_MIN_VALUE) {
           channel_1_setting_buffer--;
           apply_channel_1_value();
        }
      } else {
        if(channel_2_setting_buffer > SETTING_MIN_VALUE) {
           channel_2_setting_buffer--;
           apply_channel_2_value();
        }
      }
}

void handle_buttons(){
   // plus
   if(BUTTON_PLUS_PRESSED && !is_button_plus_was_pressed) {
      is_button_plus_was_pressed = 1;
      increase_current_channel_setting_buffer();
      return;
      
   } else if (BUTTON_PLUS_PRESSED && is_button_plus_was_pressed){  
        button_pressed_frames++;
      if(button_pressed_frames == AUTOINCREMENT_FIRST_STEP) {
        increase_current_channel_setting_buffer();
      } else if(button_pressed_frames == AUTOINCREMENT_FIRST_STEP + AUTOINCREMENT_STEP) {  
        button_pressed_frames = AUTOINCREMENT_FIRST_STEP;
        increase_current_channel_setting_buffer();
      }
      
      return;
   
   } else if (!BUTTON_PLUS_PRESSED && is_button_plus_was_pressed){
      is_button_plus_was_pressed = 0;
      button_pressed_frames = 0;
      // save to eeprom
      if(current_channel == 0){
           do_save_channel_1_setting = 1;
      } else {
            do_save_channel_2_setting = 1;
      }
      
      return;
   }
   
   // minus  
   if(BUTTON_MINUS_PRESSSED && !is_button_minus_was_pressed) {
      is_button_minus_was_pressed = 1;
      decrease_current_channel_setting_buffer();
      return;
      
   } else if (BUTTON_MINUS_PRESSSED && is_button_minus_was_pressed){
      button_pressed_frames++;
      if(button_pressed_frames == AUTOINCREMENT_FIRST_STEP) {
           decrease_current_channel_setting_buffer();
      } else if(button_pressed_frames == AUTOINCREMENT_FIRST_STEP + AUTOINCREMENT_STEP) {  
        button_pressed_frames = AUTOINCREMENT_FIRST_STEP;
        decrease_current_channel_setting_buffer();
      }
      
      return;
   
   } else if (!BUTTON_MINUS_PRESSSED && is_button_minus_was_pressed){
      is_button_minus_was_pressed = 0; 
      button_pressed_frames = 0;
      // save to eeprom
      if(current_channel == 0){
           do_save_channel_1_setting = 1;
      } else {
            do_save_channel_2_setting = 1;
      }
      
      return;
   }
   
   // channel
   if(BUTTON_CHANNEL_PRESSED && !is_button_channel_was_pressed) {
      is_button_channel_was_pressed = 1;
      if(current_channel == 0){
         current_channel = 1;
         LED_CHANNEL_1 = 0;
         LED_CHANNEL_2 = 1;
      } else {
         current_channel = 0;
         LED_CHANNEL_1 = 1;
         LED_CHANNEL_2 = 0;
      }
      return;
      
   } else if (!BUTTON_CHANNEL_PRESSED && is_button_channel_was_pressed){
      is_button_channel_was_pressed = 0;
      return;
   }
}

void invalidate_display(){
   if(display_frames > DISPLAY_FRAMES_PER_DIGIT){
      display_frames = 1;
      if(current_digit == 0) {
            current_digit = 1;
            show_digit_value((current_channel == 0 ? channel_1_setting_buffer : channel_2_setting_buffer) / 10);
            
      } else {
           current_digit = 0;
           show_digit_value((current_channel == 0 ? channel_1_setting_buffer : channel_2_setting_buffer) % 10);
      }
      
      show_digit(current_digit);
      
   } else {
      display_frames++;
   }
}

/*
bool is_more_one_buttton_pressed(){
 return (BUTTON_PLUS_PRESSED && BUTTON_MINUS_PRESSSED) || (BUTTON_PLUS_PRESSED && BUTTON_CHANNEL_PRESSED) || (BUTTON_CHANNEL_PRESSED && BUTTON_MINUS_PRESSSED);
} */

// TIMER0 interrupt service routine
interrupt [TIM0_OVF] void timer0_int(void)
{
    // Interupts every 4ms
    invalidate_display();
    handle_buttons();
}


