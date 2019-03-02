
#include<Servo.h>

Servo servo;


#define trigPin A11
#define echoPin A12

#define num_sensors 10
#define avgSpeed 70


long duration;
long cm;

int pwmA = 5;
int pwmB = 6;
int dirA1 = 35;
int dirA2 = 37;
int dirB1 = 45;
int dirB2 = 47;


//int lrdvalue=0;

void setup() {
  Serial.begin(9600);

 // readValues();
  
  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(dirA1, OUTPUT);
  pinMode(dirA2, OUTPUT);
  pinMode(dirB1, OUTPUT);
  pinMode(dirB2, OUTPUT);
  
  //pinMode(ldrPin, INPUT);

  servo.attach(9);
  servo.write(120);

  forward();
  
}

void loop() {
  sonar();
  if(cm <= 25){
    anticlockwise();
    delay(350);
    //Stop();
    //delay(1000);
    servo.write(40);
     Stop();
    delay(1000);
    sonar();
   while(cm<=50)
   { 
     servo.write(40);
     sonar();
     forward();
     delay(100);
   }
   //delay(200);
   if(cm>40){
     servo.write(120);
     clockwise();
     delay(350);
     //Stop();
     //delay(1000);
     forward();
    }
  }
  forward();
}


long TimetoDistance(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

  void sonar(){
    pinMode(trigPin, OUTPUT);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = TimetoDistance(duration);
    Serial.println(cm);
    //Serial.print(" ");
    //delay(10);
  }
  
  void Stop(){
    digitalWrite(dirA1, LOW);
    digitalWrite(dirA2, LOW);
    //analogWrite(pwmA, avgSpeed);
    digitalWrite(dirB1, LOW);
    digitalWrite(dirB2, LOW);
   // analogWrite(pwmB, avgSpeed);
  }
  void forward(){
    digitalWrite(dirA1, HIGH);
    digitalWrite(dirA2, LOW);
    analogWrite(pwmA, avgSpeed);
    digitalWrite(dirB1, HIGH);
    digitalWrite(dirB2, LOW);
    analogWrite(pwmB, avgSpeed);
  }
  void anticlockwise(){
    digitalWrite(dirA1, LOW);
    digitalWrite(dirA2, LOW);
    analogWrite(pwmA, 0);
    digitalWrite(dirB1, HIGH);
    digitalWrite(dirB2, LOW);
    analogWrite(pwmB, 175);
  }

  void clockwise(){
    digitalWrite(dirA1, HIGH);
    digitalWrite(dirA2, LOW);
    analogWrite(pwmA, 175);
    digitalWrite(dirB1, LOW);
    digitalWrite(dirB2, LOW);
    analogWrite(pwmB, 0);
  }

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     
