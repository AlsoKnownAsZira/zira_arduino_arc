#define ledYellow 2
#define ledGreen 4
#define buttonLightUp 6
/// Challenge 1: Posisi awal lampu selalu mati, tombol ditekan semua lampu nyala tanpa berkedip, tombol dilepas semua lampu posisi awal
void setup() {
  Serial.begin(9600); //baud rate monitoring log input
  pinMode(buttonLightUp, INPUT);
  digitalWrite(buttonLightUp,HIGH); // default state mati
 pinMode(ledYellow,OUTPUT);
  pinMode(ledGreen,OUTPUT);

}

void lightMode(int opt) {
    if (opt == 1) {
        digitalWrite(ledYellow, HIGH);
        digitalWrite(ledGreen, HIGH);
    } else {
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledGreen, LOW);
    }
}

void loop() {
    int isButtonLightPressed = digitalRead(buttonLightUp);

    if (isButtonLightPressed == LOW) { // Button pressed
        Serial.println("Button Pressed: ON!");
        lightMode(1); // Turn LEDs ON
    } else { // Button released
        Serial.println("Button Released: OFF!");
        lightMode(0); // Turn LEDs OFF
    }
}
