#include <IRremote.h>
#include <Servo.h>

/*Definisani dugmici sa daljinskog u HEXa kodovima*/
#define btn1 0xFFA25D
#define btn2 0xFF629D
#define btn3 0xFFE21D
#define btn4 0xFF22DD
#define btn5 0xFF02FD
#define btn6 0xFFC23D
#define btn7 0xFFE01F
#define btn8 0xFFA857
#define btn9 0xFF906F
#define btn0 0xFF9867
#define btntaraba 0xFFB04F
#define btnzvezdica 0xFF6897
#define btngore 0xFF18E7
#define btndole 0xFF4AB5
#define btndesno 0xFF5AA5
#define btnlevo 0xFF10EF
#define btnok 0xFF38C7

int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

//uint32_t Previous;

bool servo1oznacen = 0;
bool servo2oznacen = 0;
bool servo3oznacen = 0;
bool servo4oznacen = 0;
bool servo5oznacen = 0;
bool servo6oznacen = 0;

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // previous position

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();

  /*Konektovanje servo motora*/
  servo01.attach(3);
  servo02.attach(4);
  servo03.attach(5);
  servo04.attach(6);
  servo05.attach(7);
  servo06.attach(8);

  /*Postavlja pocetne pozicija servo motra na zadate vrednosti*/
  servo1PPos = 0;   //Min 0 Max 180
  servo01.write(servo1PPos);
  servo2PPos = 180;  //Min 80 Max 180
  servo02.write(servo2PPos);
  servo3PPos = 100;
  servo03.write(servo3PPos);
  servo4PPos = 180;
  servo04.write(servo4PPos);
  servo5PPos = 90;
  servo05.write(servo5PPos);
  servo6PPos = 90;
  servo06.write(servo6PPos);
}
void loop() {
  if (irrecv.decode(&results)) { //if we have received an IR signal
    /*if (results.value == 0xFFFFFFFF) {
      results.value = Previous;
    }*/
    switch (results.value) {
      case btn1: //Ukoliko je pritisnuto dugme 1 uradi sledece:
        servo1oznacen = 1; //Servo motor 1 oznacen sve
        servo2oznacen = 0;
        servo3oznacen = 0;
        servo4oznacen = 0;
        servo5oznacen = 0;
        servo6oznacen = 0;
        Serial.println("SERVO 1 OZNACEN");
    }
    switch (results.value) {
      case btn2: //Ukoliko je pritisnuto dugme 2 uradi sledece:
        servo1oznacen = 0;
        servo2oznacen = 1;
        servo3oznacen = 0;
        servo4oznacen = 0;
        servo5oznacen = 0;
        servo6oznacen = 0;
        Serial.println("SERVO 2 OZNACEN");
    }
    switch (results.value) {
      case btn3: //Ukoliko je pritisnuto dugme 3 uradi sledece:
        servo1oznacen = 0;
        servo2oznacen = 0;
        servo3oznacen = 1;
        servo4oznacen = 0;
        servo5oznacen = 0;
        servo6oznacen = 0;
        Serial.println("SERVO 3 OZNACEN");
    }
    switch (results.value) {
      case btn4: //Ukoliko je pritisnuto dugme 4 uradi sledece:
        servo1oznacen = 0;
        servo2oznacen = 0;
        servo3oznacen = 0;
        servo4oznacen = 1;
        servo5oznacen = 0;
        servo6oznacen = 0;
        Serial.println("SERVO 4 OZNACEN");
    }
    switch (results.value) {
      case btn5: //Ukoliko je pritisnuto dugme 5 uradi sledece:
        servo1oznacen = 0;
        servo2oznacen = 0;
        servo3oznacen = 0;
        servo4oznacen = 0;
        servo5oznacen = 1;
        servo6oznacen = 0;
        Serial.println("SERVO 5 OZNACEN");
    }
    switch (results.value) {
      case btn6: //Ukoliko je pritisnuto dugme 6 uradi sledece:
        servo1oznacen = 0;
        servo2oznacen = 0;
        servo3oznacen = 0;
        servo4oznacen = 0;
        servo5oznacen = 0;
        servo6oznacen = 1;
        Serial.println("SERVO 6 OZNACEN");
    }
    switch (results.value) {
      case btndesno: //Ukoliko je pritisnuto dugme 'strelica na desno' uradi sledece:
        if ( servo1oznacen == 1 ) {  //Ukoliko je oznacen servo motor 1:
          int servo1pos = servo1PPos += 10; //Uzmi trenutnu poziciju servo motora i dodaj mu 10
          servo01.write(servo1pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo1pos
          Serial.println(servo1pos);
          delay(100);
        } else if ( servo2oznacen == 1 ) { //Ukoliko je oznacen servo motor 2:
          int servo2pos = servo2PPos += 10; //Uzmi trenutnu poziciju servo motora i dodaj mu 10
          servo02.write(servo2pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo2pos
          Serial.println(servo2pos);
          delay(100);
        } else if ( servo3oznacen == 1 ) { //Ukoliko je oznacen servo motor 3:
          int servo3pos = servo3PPos += 10; //Uzmi trenutnu poziciju servo motora i dodaj mu 10
          servo03.write(servo3pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo3pos
          Serial.println(servo3pos);
          delay(100);
        } else if ( servo4oznacen == 1 ) { //Ukoliko je oznacen servo motor 4:
          int servo4pos = servo4PPos += 10; //Uzmi trenutnu poziciju servo motora i dodaj mu 10
          servo04.write(servo4pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo4pos
          Serial.println(servo4pos); 
          delay(100);
        } else if ( servo5oznacen == 1 ) { //Ukoliko je oznacen servo motor 5:
          int servo5pos = servo5PPos += 10; //Uzmi trenutnu poziciju servo motora i dodaj mu 10
          servo05.write(servo5pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo5pos
          Serial.println(servo5pos);
          delay(100);
        } else if ( servo6oznacen == 1 ) { //Ukoliko je oznacen servo motor 6:
          int servo6pos = servo6PPos += 10; //Uzmi trenutnu poziciju servo motora i dodaj mu 10
          servo06.write(servo6pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo6pos
          Serial.println(servo6pos);
          delay(100);
        }
    }
    switch (results.value) {
      case btnlevo: //Ukoliko je pritisnuto dugme 'strelica na levo' uradi sledece:
        if ( servo1oznacen == 1 ) { //Ukoliko je oznacen servo motor 1:
          int servo1pos = servo1PPos -= 10; //Uzmi trenutnu poziciju servo motora i oduzmi mu 10
          servo01.write(servo1pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo1pos
          Serial.println(servo1pos);
          delay(100);
        } else if ( servo2oznacen == 1 ) { //Ukoliko je oznacen servo motor 2:
          int servo2pos = servo2PPos -= 10; //Uzmi trenutnu poziciju servo motora i oduzmi mu 10
          servo02.write(servo2pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo2pos
          Serial.println(servo2pos);
          delay(100);
        } else if ( servo3oznacen == 1 ) { //Ukoliko je oznacen servo motor 3:
          int servo3pos = servo3PPos -= 10; //Uzmi trenutnu poziciju servo motora i oduzmi mu 10
          servo03.write(servo3pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo3pos
          Serial.println(servo3pos);
          delay(100);
        } else if ( servo4oznacen == 1 ) { //Ukoliko je oznacen servo motor 4:
          int servo4pos = servo4PPos -= 10; //Uzmi trenutnu poziciju servo motora i oduzmi mu 10
          servo04.write(servo4pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo4pos
          Serial.println(servo4pos);
          delay(100);
        } else if ( servo5oznacen == 1 ) { //Ukoliko je oznacen servo motor 5:
          int servo5pos = servo5PPos -= 10; //Uzmi trenutnu poziciju servo motora i oduzmi mu 10
          servo05.write(servo5pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo5pos
          Serial.println(servo5pos);
          delay(100);
        } else if ( servo6oznacen == 1 ) { //Ukoliko je oznacen servo motor 6:
          int servo6pos = servo6PPos -= 10; //Uzmi trenutnu poziciju servo motora i oduzmi mu 10
          servo06.write(servo6pos); //Postavi poziciju servo motora na vrednost sacuvanu u servo6pos
          Serial.println(servo6pos);
          delay(100);
        }
    }
    irrecv.resume();
  }
  //Previous = results.value;


  /*if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.
    {
    int readResults = results.value;// Results of decoding are stored in result.value
    Serial.println(" ");
    Serial.print("Code: ");
    Serial.println(readResults); //prints the value a a button press
    Serial.println(" ");
    irrecv.resume(); // Restart the ISR state machine and Receive the next value
    }*/
}
