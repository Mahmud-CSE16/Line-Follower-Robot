int a[6];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  readline();
}

int readline(){
  int t=0;
  for(int i=0;i<6;i++){
    a[i]=digitalRead(8+i);
    Serial.print(a[i]);
    Serial.print("  ");
  }
  Serial.println();
  int v;
  v=(5000*a[0]+4000*a[1]+3000*a[2]+2000*a[3]+1000*a[4]+0*a[5])/ (a[0]+a[1]+a[2]+a[3]+a[4]+a[5]);
  Serial.println(v);
  delay(1000);
  return v;
}
