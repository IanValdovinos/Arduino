#include <IRremote.h>
#include <Servo.h>

#define Nothing 0xFFFFFFFF
#define Power_Button 0xFFA25D
#define Button_0 0x6897
#define Button_1 0x30CF
#define Button_2 0x18E7
#define Button_3 0x7A85
#define Button_4 0x10EF
#define Button_5 0x38C7
#define Button_6 0x5AA5
#define Button_7 0x42BD
#define Button_8 0x4AB5
#define Button_9 0x52AD
#define Volume_Up 0x629D
#define Volume_Down 0xFFFFA857
#define Func_Stop 0xFFFFE21D
#define Button_Down 0xFFFFE01F
#define Button_Up 0xFFFF906F

int receiver = 8; // Initlialize IR receiver pin
IRrecv irrecv(receiver); // Crete new instance of IR receiver 
decode_results results;

Servo my_servo;
int my_servo_pos = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();

  my_servo.attach(6);
  my_servo.write(my_servo_pos);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    int hex_value = results.value;
    if (hex_value != Nothing) {
      switch (hex_value) {
        case Button_Down:
          Serial.print("Button Down pressed\n");
          if (my_servo_pos >= 10){
            my_servo_pos = my_servo_pos - 10;
            my_servo.write(my_servo_pos);
          }
          break;
         case Button_Up:
          Serial.print("Button Up pressed\n");
          if (my_servo_pos <= 170){
            my_servo_pos = my_servo_pos + 10;
            my_servo.write(my_servo_pos);
          }
          break;
         default:
          Serial.print("Unknown button pressed.\n");
      }
    }
    irrecv.resume();
  }

}
