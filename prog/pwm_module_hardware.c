/* a=target variable, b=bit number to act upon 0-n */
//#define BIT_SET(a,b) ((a) |= (1<<(b)))
//#define BIT_CLEAR(a,b) ((a) &= ~(1<<(b)))
//#define BIT_FLIP(a,b) ((a) ^= (1<<(b)))
//#define BIT_CHECK(a,b) ((a) & (1<<(b)))

#define BUTTON_PLUS PINA.0
#define BUTTON_MINUS PINA.1
#define BUTTON_CHANNEL PINB.7

#define BUTTON_PLUS_PRESSED BUTTON_PLUS == 0
#define BUTTON_MINUS_PRESSSED BUTTON_MINUS == 0
#define BUTTON_CHANNEL_PRESSED BUTTON_CHANNEL == 0

#define LED_CHANNEL_1 PORTB.5
#define LED_CHANNEL_2 PORTB.6

#define DIGIT_0 PORTB.1
#define DIGIT_1 PORTB.2
#define SHOW_DIGIT_0 DIGIT_0 = 0; DIGIT_1 = 1
#define SHOW_DIGIT_1 DIGIT_1 = 0; DIGIT_0 = 1


#define DISPLAY_A PORTD0
#define DISPLAY_B PORTD1
#define DISPLAY_C PORTD2
#define DISPLAY_D PORTD3
#define DISPLAY_E PORTD4
#define DISPLAY_F PORTD5
#define DISPLAY_G PORTD6
#define DISPLAY_DP PORTB.0

#define SHOW_DISPLAY_DP DISPLAY_DP = 0
#define CLEAR_DISPLAY_DP DISPLAY_DP = 1

// DIGITS
// Clear
#define DISPLAY_CLEAR PORTD = 0xFF

// 0
#define DISPLAY_0 PORTD = ~((1<<DISPLAY_A) | (1<<DISPLAY_B) | (1<<DISPLAY_C)| (1<<DISPLAY_D)| (1<<DISPLAY_E)| (1<<DISPLAY_F))

// 1
#define DISPLAY_1 PORTD = ~((1<<DISPLAY_B) | (1<<DISPLAY_C))

// 2
#define DISPLAY_2 PORTD = ~((1<<DISPLAY_A) | (1<<DISPLAY_B) | (1<<DISPLAY_G)| (1<<DISPLAY_E)| (1<<DISPLAY_D))

// 3
#define DISPLAY_3 PORTD = ~((1<<DISPLAY_A) | (1<<DISPLAY_B) | (1<<DISPLAY_C)| (1<<DISPLAY_D)| (1<<DISPLAY_G))

// 4
#define DISPLAY_4 PORTD = ~((1<<DISPLAY_B) | (1<<DISPLAY_C) | (1<<DISPLAY_G)| (1<<DISPLAY_F))

// 5
#define DISPLAY_5 PORTD = ~((1<<DISPLAY_A) | (1<<DISPLAY_C)| (1<<DISPLAY_D) | (1<<DISPLAY_F) | (1<<DISPLAY_G))

// 6
#define DISPLAY_6 PORTD = ~((1<<DISPLAY_A) | (1<<DISPLAY_C)| (1<<DISPLAY_D) | (1<<DISPLAY_E) | (1<<DISPLAY_F) | (1<<DISPLAY_G))

// 7
#define DISPLAY_7 PORTD = ~((1<<DISPLAY_A) | (1<<DISPLAY_B)| (1<<DISPLAY_C))


// 8
#define DISPLAY_8 PORTD = ~((1<<DISPLAY_A) | (1<<DISPLAY_B) | (1<<DISPLAY_C)| (1<<DISPLAY_D) | (1<<DISPLAY_E) | (1<<DISPLAY_F) | (1<<DISPLAY_G))


// 9
#define DISPLAY_9 PORTD = ~((1<<DISPLAY_A) | (1<<DISPLAY_B) | (1<<DISPLAY_C)| (1<<DISPLAY_D) | (1<<DISPLAY_F) | (1<<DISPLAY_G))


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