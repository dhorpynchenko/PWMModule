
#define BUTTON_PLUS PINA.0
#define BUTTON_MINUS PINA.1
#define BUTTON_CHANNEL PIND.1

#define BUTTON_PLUS_PRESSED PINA.0 = 0
#define BUTTON_MINUS_PRESSSED PINA.1 = 0
#define BUTTON_CHANNEL_PRESSED PIND.1 = 0

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

void show_digit_value(unsigned char value){
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

void show_digit (unsigned char digit){
    
    switch(digit){   
        case 0:
             SHOW_DIGIT_0;
        return;
        
        case 1:
              SHOW_DIGIT_1;
        return;
    }
}