#define ledYellow 2
#define ledGreen 4
#define buttonLightUp 6
// Challenge 2 : posisi lampu awal menyala, tombol ditekan lampu berkedip
void setup() {
    Serial.begin(9600); // Baud rate monitoring log input
    pinMode(buttonLightUp, INPUT_PULLUP); // Gunakan internal pull-up resistor
    pinMode(ledYellow, OUTPUT);
    pinMode(ledGreen, OUTPUT);
    
    // Set posisi awal lampu menyala
    digitalWrite(ledYellow, HIGH);
    digitalWrite(ledGreen, HIGH);
}

void loop() {
    int isButtonLightPressed = digitalRead(buttonLightUp);

    if (isButtonLightPressed == LOW) { // Tombol ditekan
        Serial.println("Button Pressed: Blinking!");

        // Lampu berkedip selama tombol ditekan
        digitalWrite(ledYellow, HIGH);
        digitalWrite(ledGreen, HIGH);
        delay(200);
        digitalWrite(ledYellow, LOW);
        digitalWrite(ledGreen, LOW);
        delay(200);
    } else {
        Serial.println("Button Released: OFF");
        // Kembali ke posisi awal (lampu menyala terus)
        digitalWrite(ledYellow, HIGH);
        digitalWrite(ledGreen, HIGH);
    }
}
