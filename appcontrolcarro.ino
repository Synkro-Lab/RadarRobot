
  
#include <AFMotor.h>
  #include <Servo.h>  
//initial motors pin
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
int angle = 0;
bool sweepUp = true;

const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;
Servo myServo;
  
int val;
int Speeed = 100;



void setup()
{
 pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  myServo.attach(9);  // ← CAMBIADO de 10 a 9
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}
void loop(){

    sweepServo();


  if(Serial.available() > 0){
    val = Serial.read();
      
    Stop(); //initialize with motors stoped
      
          if (val == 'F'){
          forward();
          }
  
          if (val == 'B'){
          back();
          }
  
          if (val == 'L'){
          left();
          }
  
          if (val == 'R'){
          right();
          }
          if (val == 'I'){
          topright();
          }
  
          if (val == 'J'){
          topleft();
          }
  
          if (val == 'K'){
          bottomright();
          }
  
          if (val == 'M'){
          bottomleft();
          }
          if (val == 'T'){
          Stop();
          }
  }
}
           
  void sweepServo() {
  if (sweepUp) {
    angle++;
    if (angle >= 180) {
      angle = 180;
      sweepUp = false;

    }
  } else {
    angle--;
    if (angle <= 0) {
      angle = 0;
      sweepUp = true;  
    }
  }
  myServo.write(angle);
   distance = calculateDistance();
      Serial.print(angle);
      Serial.print(",");
      Serial.print(distance);
      Serial.print(".");
  delay(10);
}

int calculateDistance() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH, 30000); // 30ms timeout

  if (duration == 0) {
    return -1; // sin lectura
  }

  return duration * 0.034 / 2;
}


 
  
  
void forward()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed);//Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor clockwise
  motor4.setSpeed(Speeed);//Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor clockwise
}
  
void back()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(FORWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(FORWARD); //rotate the motor anti-clockwise
}
  
void left()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(BACKWARD);  //rotate the motor clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}
  
void right()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(FORWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}
  
void topleft(){
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed/3.1);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(Speeed/3.1);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}
  
void topright()
{
  motor1.setSpeed(Speeed/3.1); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(Speeed/3.1); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(Speeed);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(Speeed);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
}
  
void bottomleft()
{
  motor1.setSpeed(Speeed); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed/3.1); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed/3.1); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}
  
void bottomright()
{
  motor1.setSpeed(Speeed/3.1); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(Speeed/3.1); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(Speeed); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(Speeed); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}
  
  
void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}