#include<Servo.h>
#define ACTIVATED LOW

Servo NovaServo_1;//head movement front and back (45-135)(75-120)
Servo NovaServo_2;//head rotation clockwise, anticlockwise (15-165)
Servo NovaServo_3;//head rotation up and down (15-165)
Servo NovaServo_4;//whole body rotation z axis (15-165)
Servo NovaServo_5;//head movement up and down (45-135)(75-120)

int joystick1_x = A9;
int joystick1_y = A11;
int joystick2_x = A13;
int joystick2_y = A15;
int joystick1_sw = 43;
int joystick2_sw = 45;

int value1_x;
int value1_y;
int value2_x;
int value2_y;
int value1_sw;
int value2_sw;

int value1_xF = 90;
int value1_yF = 90;
int value2_xF = 90;
int value2_yF = 90;

int degree = 90;

float filter1_x = 0.05;
float filter1_y = 0.05;
float filter2_x = 0.08;
float filter2_y = 0.08;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(joystick1_sw, INPUT_PULLUP);
  pinMode(joystick2_sw, INPUT_PULLUP);
  
  NovaServo_1.attach(32);
  NovaServo_2.attach(34);
  NovaServo_3.attach(36);
  NovaServo_4.attach(38);
  NovaServo_5.attach(40);
  
  NovaServo_1.write(90);
  NovaServo_2.write(90);
  NovaServo_3.write(90);
  NovaServo_4.write(90);
  NovaServo_5.write(90);

}

void loop() {
  // put your main code here, to run repeatedly:

  value1_x = analogRead(joystick1_x);
  value1_y = analogRead(joystick1_y);
  value2_x = analogRead(joystick2_x);
  value2_y = analogRead(joystick2_y);
  value1_sw = digitalRead(joystick1_sw);
  value2_sw = digitalRead(joystick2_sw);
  
  value1_x = map(value1_x, 0, 1024, 170, 10);
  value1_y = map(value1_y, 0, 1024, 30, 140);
  value2_x = map(value2_x, 0, 1024, 30, 150);
  value2_y = map(value2_y, 0, 1024, 30, 140);
  

  value1_xF = value1_xF * (1 - filter1_x) + value1_x * filter1_x;
  value1_yF = value1_yF * (1 - filter1_y) + value1_y * filter1_y; 
  value2_xF = value2_xF * (1 - filter2_x) + value2_x * filter2_x;
  value2_yF = value2_yF * (1 - filter2_y) + value2_y * filter2_y;

  if (value1_sw == ACTIVATED) {
      if(degree < 141){
        degree = degree + 2;
      }
  }
  
  if (value2_sw == ACTIVATED) {
      if(degree > 89) 
      {
        degree = degree - 2;
      }
  } 

delay(30);

 if(value1_yF > 45){
    NovaServo_1.write(value1_yF);
 }
 if(value2_yF > 30){
  NovaServo_3.write(value2_yF);
 }
 NovaServo_2.write(value2_xF);
 NovaServo_4.write(value1_xF);
 NovaServo_5.write(degree);
  
}
