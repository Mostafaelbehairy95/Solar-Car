 #include <SPI.h>
 #include <nRF24L01.h>
 #include <RF24.h>
 
 #define LEFTA1 0
 #define LEFTA2 1
 #define LEFTB1 2
 #define LEFTB2 3

 #define RIGHTA1 4
 #define RIGHTA2 5
 #define RIGHTB1 6 
 #define RIGHTB2 7


RF24 radio(9, 10);

const byte rxAddr[6] = "00001";
char message[4];
float speedv = 0;
float speedh = 0;

void setup()
{
   for(int i = 0; i < 8; i ++){
    pinMode(i, OUTPUT);
   }
   radio.begin();
   radio.openReadingPipe(0, rxAddr);
  
   radio.startListening();
}

void loop()
{
   if (radio.available())
   {
    
         radio.read(&message, sizeof(message));

        if(message[0] > '5' && message[2] != '5'&& message[2] != '2' ){
            digitalWrite(LEFTA2, HIGH);
            digitalWrite(LEFTB2, HIGH);
            digitalWrite(LEFTA1, LOW);
            digitalWrite(LEFTB1, LOW);

            digitalWrite(RIGHTA1, HIGH);
            digitalWrite(RIGHTB1, HIGH);
            digitalWrite(RIGHTA2, LOW);
            digitalWrite(RIGHTB2, LOW);

        }else if(message[0] > '5' && message[2] == '2' ){
          
            digitalWrite(LEFTA1, HIGH);
            digitalWrite(LEFTB1, HIGH);
            digitalWrite(LEFTA2, LOW);
            digitalWrite(LEFTB2, LOW);

            digitalWrite(RIGHTA2, LOW);
            digitalWrite(RIGHTB2, LOW);
            digitalWrite(RIGHTA1, HIGH);
            digitalWrite(RIGHTB1, HIGH);

        }else if(message[0] >'5' && message[2] == '5' ){
          
            digitalWrite(LEFTA1, LOW);
            digitalWrite(LEFTB1, LOW);
            digitalWrite(LEFTA2, HIGH);
            digitalWrite(LEFTB2, HIGH);

            digitalWrite(RIGHTA1, LOW);
            digitalWrite(RIGHTB1, LOW);
            digitalWrite(RIGHTA2, HIGH);
            digitalWrite(RIGHTB2, HIGH);
        }else if(message[0] < '5' && message[2] != '5'&& message[2] != '2' ){
            digitalWrite(LEFTA2, LOW);
            digitalWrite(LEFTB2, LOW);
            digitalWrite(LEFTA1, HIGH);
            digitalWrite(LEFTB1, HIGH);

            digitalWrite(RIGHTA1, LOW);
            digitalWrite(RIGHTB1, LOW);
            digitalWrite(RIGHTA2, HIGH);
            digitalWrite(RIGHTB2, HIGH);

        }
    }
  }

// High will make wheel move Backword
// LOW will make whell move forward
