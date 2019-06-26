  #include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10);

const byte rxAddr[6] = "00001";
char message[4];

void setup()
{
  Serial.begin(9600);
  for(uint8_t button = 2; button <= 5; button ++){
      pinMode(button, INPUT_PULLUP);
  }

  radio.begin();
  radio.setRetries(15, 15);
  radio.openWritingPipe(rxAddr);
  
  radio.stopListening();
  
}

void loop()
{
  message[2] = 0;
  uint8_t y = map(analogRead(A1), 0, 1023, 9, 0);
  uint8_t x = map(analogRead(A0), 0, 1023, 9, 0);
  message[0] = y + '0';
  message[1] = x + '0';
  for(int i = 2; i < 6; i ++){    
    if(!digitalRead(i)){
      message[2] = i+'0';
    }
  }
   Serial.println(message);
 
   radio.write(&message, sizeof(message));     
  delay(300);
}
