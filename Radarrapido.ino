 #include <Servo.h>
int angle = 0;
bool sweepUp = true;

const int trigPin = 10;
const int echoPin = 11;
long duration;
int distance;
Servo myServo;

void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  myServo.attach(9);  // ← CAMBIADO de 10 a 9
}

void loop() {
  sweepServo();
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

int calculateDistance(){
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration * 0.034 / 2;
  return distance;
}
