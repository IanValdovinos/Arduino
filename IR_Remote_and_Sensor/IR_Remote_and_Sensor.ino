#include <IRremote.h>

#define Nothing 0xFFFFFFFF
#define Power_Button 0xFFA25D

int receiver = 8; // Initlialize IR receiver pin
IRrecv irrecv(receiver); // Crete new instance of IR receiver 
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();

}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    int hex_value = results.value;
    if (hex_value != Nothing) {
      Serial.print(hex_value, HEX);
      Serial.print("\n");
    }
    irrecv.resume();
  }

}
