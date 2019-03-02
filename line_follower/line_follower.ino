
//left motor
int L1=2;
int L2=3;
int enL= 5;

//right motor
int R1=4;
int R2=7;
int enR=6;

//for PID
int a[6];
int last_proportional=0;
int integral=0;

int mod(int v);  //Modulus function
int set_motors(int a,int b);
void PID();

const int max=65;
int pre=1;
int c=1;
void setup(){
  pinMode(L1,OUTPUT);  //Left motor
  pinMode(L2,OUTPUT);
  
  pinMode(R1,OUTPUT);  //Right motor
  pinMode(R2,OUTPUT);
  
  pinMode(enL,OUTPUT);  //Enable pins of L and R motors
  pinMode(enR,OUTPUT);
  
  Serial.begin(9600);
}

void loop(){
  //PID();      //control
  //delay(1000);
  readline();
  if((a[0]==HIGH && a[1]==HIGH && a[2]==HIGH && a[3]==HIGH && a[4]==HIGH && a[5]==HIGH) && pre==1 ){
    Serial.println("Left in white");
    set_motors(max,0);
  }
  else if((a[0]==HIGH && a[1]==HIGH && a[2]==HIGH && a[3]==HIGH && a[4]==HIGH && a[5]==HIGH) && pre==-1){
    Serial.println("right in white");
    set_motors(0,max);
  }
  else if(a[0]==LOW && a[5]==LOW){
    Serial.println("stright");
    set_motors(70,70);
    //delay(30);
    //set_motors(0,0);
    pre=-1;
  }
  else if(a[2]==LOW && a[3]==LOW && a[4]==LOW && a[5]==LOW && a[0]==HIGH){
    Serial.println("Right");
    set_motors(0,max);
    delay(200);
    pre=-1;
  }
  else if(a[0]==LOW && a[1]==LOW && a[2]==LOW && a[3]==LOW && a[5]==HIGH){
    Serial.println("Left");
    set_motors(max,0);
    delay(200);
    pre=1;
  }
  else if(a[0]==LOW && a[5]==HIGH){   //Left
    Serial.println("Left");
    set_motors(max,0);
    pre=-1;
  }
  else if(a[0]==HIGH && a[5]==LOW){  //right
    Serial.println("right");
    set_motors(0,max);
    pre=1;
  }
  else if(a[2]==LOW || a[3]==LOW){
    Serial.println("Stright");
    set_motors(max,max);
    pre=-1;
  }
}

int readline(){
  int t=0;
  for(int i=0;i<6;i++){
    a[i]=digitalRead(8+i);
    Serial.print(a[i]);
    Serial.print(" ");
  }
  Serial.println();
  /*int v;
  v=(5000*a[0]+4000*a[1]+3000*a[2]+2000*a[3]+1000*a[4]+0*a[5])/ (a[0]+a[1]+a[2]+a[3]+a[4]+a[5]);
  return v;*/
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
    analogWrite(enL,mod(l)+3);
    analogWrite(enR,mod(r));
    
    digitalWrite(L1,LOW);
    digitalWrite(L2,HIGH);
    
    digitalWrite(R1,LOW);
    digitalWrite(R2,HIGH);
  }
  
  if(l>=0 && r<=0){
    analogWrite(enL,mod(l)+3);
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

