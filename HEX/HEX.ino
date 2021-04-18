#include <IRremote.h>
int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}
void loop() {

  if (irrecv.decode(&results))
  {
    int readResults = results.value;
    Serial.println(" ");
    Serial.print("Code: ");
    Serial.println(results.value, HEX);
    Serial.println(" ");
    irrecv.resume();
  }
}
