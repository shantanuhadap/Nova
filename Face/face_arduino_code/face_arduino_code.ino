#include <PID_v1.h>
#include <Servo.h>

Servo NovaServo_1; //Head Movement - Front and Back
Servo NovaServo_2; //Head Rotation - Clockwise and Anticlockwise
Servo NovaServo_3; //Head Rotation - Up and Down
Servo NovaServo_4; //Whole Body Rotation - Z axis
Servo NovaServo_5; //Head Movement - Up and Down

double Kp_1 = 0.145;//0.016
double Ki_1 = 0.145;//0.012
double Kd_1 = 0;

double Kp_2 = 0.140;//0.028
double Ki_2 = 0.140;//0.026
double Kd_2 = 0;

double Setpoint_1 = 90;
double Input_1;
double Output_1;

double Setpoint_2 = 90;
double Input_2;
double Output_2;

int serialCount = 0;
int serialInArray[2];

int posX = 90;
int posY = 90;

int errorX;
int errorY;

PID PID1(&Input_1, &Output_1, &Setpoint_1, Kp_1, Ki_1, Kd_1, DIRECT);
PID PID2(&Input_2, &Output_2, &Setpoint_2, Kp_2, Ki_2, Kd_2, DIRECT);

void setup() {

Serial.begin(9600);

// put your setup code here, to run once:
NovaServo_1.attach(32);
NovaServo_2.attach(34);
NovaServo_3.attach(36);
NovaServo_4.attach(38);
NovaServo_5.attach(40);

NovaServo_3.write(90);
NovaServo_4.write(90);

PID1.SetMode(AUTOMATIC);
PID1.SetSampleTime(1);
PID1.SetOutputLimits(-25, 25);

PID2.SetMode(AUTOMATIC);
PID2.SetSampleTime(1);
PID2.SetOutputLimits(-25,25);

}

void loop() {

  // put your main code here, to run repeatedly:
  while(Serial.available() == 0);
  serialInArray[serialCount] = Serial.read();
  serialCount++;

  if (serialCount > 1){

  Input_1 = serialInArray[1];
  Input_2 = serialInArray[0];

  PID1.Compute();
  PID2.Compute();

  posX = posX + Output_2;
  posY = posY + Output_1;

  NovaServo_4.write(posX);
  
  if(posY > 20 and posY < 160)
  {
    NovaServo_3.write(posY);
  }
  
  serialCount = 0;
  
  }
  
}
