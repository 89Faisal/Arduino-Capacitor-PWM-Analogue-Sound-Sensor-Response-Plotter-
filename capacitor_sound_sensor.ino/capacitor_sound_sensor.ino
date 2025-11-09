const int capPin = A0;
const int soundPin = A1;
const int buttonPin = 7;
const int chargePin = 9; // PWM pin

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(chargePin, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    // Button pressed -> charge slowly using PWM (value 0-255)
    analogWrite(chargePin, 255); // low duty -> slow charge; increase for faster
  } else {
    // Button released -> discharge (let it go to GND through discharge path)
    analogWrite(chargePin, 0); // 0 means LOW
  }

  int capValue = analogRead(capPin);
  int soundValue = analogRead(soundPin);

  Serial.print("Button:");
  Serial.print(buttonState==LOW ? "1" : "0");
  Serial.print(" | CapVal:");
  Serial.print(capValue);
  Serial.print(" | Sound:");
  Serial.println(soundValue);

  // For Serial Plotter:
  Serial.print(capValue);
  Serial.print(",");
  // Serial.print(buttonState==LOW ? 1 : 0);
  // Serial.print(",");
  Serial.println(soundValue);

  delay(50);
}
