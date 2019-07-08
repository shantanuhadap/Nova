#include <Servo.h>

Servo NovaServo_1;      //Head Movement - Front and Back
Servo NovaServo_2;      //Head Rotation - Clockwise and Anticlockwise
Servo NovaServo_3;      //Head Rotation - Up and Down
Servo NovaServo_4;      //Whole Body Rotation - Z axis
Servo NovaServo_5;      //Head Movement - Up and Down

int serialCount = 0;
int serialInArray[4];

void setup() {

// put your setup code here, to run once:
Serial.begin(9600);
Serial.setTimeout(10);
  
NovaServo_1.attach(32);
NovaServo_2.attach(34);
NovaServo_3.attach(36);
NovaServo_4.attach(38);
NovaServo_5.attach(40);

NovaServo_1.write(90);
NovaServo_2.write(90);
NovaServo_3.write(110);
NovaServo_4.write(90);
NovaServo_5.write(90);

}

void loop() {
// put your main code here, to run repeatedly:
while(Serial.available() == 0);

serialInArray[serialCount] = Serial.read();

serialCount++;

if (serialCount > 3){

NovaServo_4.write(serialInArray[0]);
NovaServo_3.write(serialInArray[1]);
NovaServo_2.write(serialInArray[2]);
NovaServo_1.write(serialInArray[3]);

serialCount = 0;

}

}
