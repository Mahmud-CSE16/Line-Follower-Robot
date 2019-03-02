// connect motor controller pins to Arduino digital pins
// motor one
int enL = 5;
int L1 = 2;
int L2 = 3;
// motor two
int enR = 6;
int R1 = 4;
int R2 = 7;
void setup()
{
  // set all the motor control pins to outputs
  pinMode(enL, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(R1, OUTPUT);
  pinMode(R2, OUTPUT);
  Serial.begin(9600);
}
/*void demoOne()
{
  // this function will run the motors in both directions at a fixed speed
  // turn on motor A
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enA, 200);
  // turn on motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  // set speed to 200 out of possible range 0~255
  analogWrite(enB, 200);
  delay(2000);
  // now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  delay(2000);
  // now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}*/
/*void demoTwo()
{
  // this function will run the motors across the range of possible speeds
  // note that maximum speed is determined by the motor itself and the operating voltage
  // the PWM values sent by analogWrite() are fractions of the maximum speed possible 
  // by your hardware
  // turn on motors
  int  i=70;
  analogWrite(enA, i);
  analogWrite(enB, i);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH); 
  
  Serial.print("1st: ");
  Serial.println(i);
  delay(3000);
  i=100;
  analogWrite(enA,i);
  analogWrite(enB,i);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);  
  Serial.print("2nd: ");
  Serial.println(i);
  delay(3000);
  i=200;
  analogWrite(enA, i);
  analogWrite(enB, i);
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 
  Serial.print("3rd: ");
  Serial.println(i);
  delay(3000);
  // accelerate from zero to maximum speed
 for (int i = 0; i < 256; i++)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(200);
  } 
  // decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i)
  {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(200);
  } 
  // now turn off motors
  i=0;
  analogWrite(enA,i);
  analogWrite(enB,i);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);  
  Serial.print("4th :");
  Serial.println(i);
  delay(3000);
}*/
void loop()
{
 int l=70;
 int r=70;
 set_motors(l,r);
 Serial.println("Stright.");
 delay(700);
 set_motors(0,0);
 delay(1000);
 l=-70;
 r=70;
 set_motors(l,r);
 Serial.println("Right.");
 delay(350);
 set_motors(0,0);
 delay(1000);
  l=70;
  r=70;
 set_motors(l,r);
 Serial.println("Stright.");
 delay(700);
 set_motors(0,0);
 delay(1000);
 l=-70;
 r=70;
 set_motors(l,r);
 Serial.println("Right.");
 delay(350);
 set_motors(0,0);
 delay(1000);
}

int set_motors(int l,int r){   //motor setup
  Serial.println(r);
  Serial.println(l);
  
  if(l>=0 && r>=0){
    analogWrite(enL,mod(l)+3);
    analogWrite(enR,mod(r));
    
    digitalWrite(L1,HIGH);
    digitalWrite(L2,LOW);
    
    digitalWrite(R1,LOW);
    digitalWrite(R2,HIGH);
  }
  
  if(l<=0 && r>=0){
    analogWrite(enL,mod(l));
    analogWrite(enR,mod(r));
    
    digitalWrite(L1,LOW);
    digitalWrite(L2,HIGH);
    
    digitalWrite(R1,LOW);
    digitalWrite(R2,HIGH);
  }
  
  if(l>=0 && r<=0){
    analogWrite(enL,mod(l));
    analogWrite(enR,mod(r));
    
    digitalWrite(L1,HIGH);
    digitalWrite(L2,LOW);
    
    digitalWrite(R1,HIGH);
    digitalWrite(R2,LOW);
  }
  if(l==0 && r== 0){
    analogWrite(enL,0);
    analogWrite(enR,0);
    
    digitalWrite(L1,HIGH);
    digitalWrite(L2,HIGH);
    
    digitalWrite(R1,HIGH);
    digitalWrite(R2,HIGH);
  }
}

int mod(int v){
  if(v<0){
    return -1*v;
  }
  else if(v>0){
    return v;
  }
  return v;
}
