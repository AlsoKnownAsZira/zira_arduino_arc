#define ledyellow 2
#define ledGreen 4
#define buttonSpeedUp 6
void setup() {
  Serial.begin(9600); //baud rate monitoring log input
  pinMode(buttonSpeedUp, INPUT);
  digitalWrite(buttonSpeedUp,HIGH); // default state nyala
 pinMode(ledyellow,OUTPUT);
  pinMode(ledGreen,OUTPUT);

}

void speedMode(int opt){
  if(opt == 1 ){
    digitalWrite(ledyellow, HIGH); 
delay(500);
digitalWrite(ledGreen, HIGH); 
digitalWrite(ledyellow, LOW);
delay(500);
digitalWrite(ledGreen, LOW); 
  }else{
    digitalWrite(ledyellow, HIGH); 
delay(1000);
digitalWrite(ledGreen, HIGH); 
digitalWrite(ledyellow, LOW);
delay(1000);
digitalWrite(ledGreen, LOW); 
  }
}
void loop() {
  int isButtonSpeedPressed = digitalRead(buttonSpeedUp);
  
  if (isButtonSpeedPressed == LOW) { // Button pressed (LOW)
    Serial.println("Button Pressed: FAST!");
    speedMode(1);
  } else { // Button not pressed (HIGH)
    Serial.println("Button Released: SLOW!");
    speedMode(0);
  }
}
