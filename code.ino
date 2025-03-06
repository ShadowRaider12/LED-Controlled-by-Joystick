const int joyXPin = A0;
const int joyYPin = A1;
const int potPin = A2;
const int ledRed = 9;
const int ledGreen = 10;
const int ledBlue = 11;
const int buzzerPin = 8;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(joyXPin);
  int yValue = analogRead(joyYPin);
  int potValue = analogRead(potPin);
  int frequency = map(potValue, 0, 1023, 100, 2000);

  analogWrite(ledRed, 0);
  analogWrite(ledGreen, 0);
  analogWrite(ledBlue, 0);
  
  if (xValue < 400 && abs(yValue - 512) < 200) {
    analogWrite(ledRed, 255);
    tone(buzzerPin, frequency);
  } else if (xValue > 600 && abs(yValue - 512) < 200) {
    analogWrite(ledRed, 255);
    analogWrite(ledBlue, 255);
    tone(buzzerPin, frequency);
  } else if (yValue < 400 && abs(xValue - 512) < 200) {
    analogWrite(ledBlue, 255);
    tone(buzzerPin, frequency);
  } else if (yValue > 600 && abs(xValue - 512) < 200) {
    analogWrite(ledRed, 255);
    analogWrite(ledGreen, 255);
    tone(buzzerPin, frequency);
  } else if (xValue < 400 && yValue < 400) {
    analogWrite(ledRed, 255);
    analogWrite(ledBlue, 255);
    tone(buzzerPin, frequency);
  } else if (xValue < 400 && yValue > 600) {
    analogWrite(ledRed, 255);
    analogWrite(ledGreen, 255);
    tone(buzzerPin, frequency);
  } else if (xValue > 600 && yValue < 400) {
    analogWrite(ledGreen, 255);
    analogWrite(ledBlue, 255);
    tone(buzzerPin, frequency);
  } else if (xValue > 600 && yValue > 600) {
    analogWrite(ledRed, 255);
    analogWrite(ledGreen, 255);
    analogWrite(ledBlue, 255);
    tone(buzzerPin, frequency);
  } else {
    noTone(buzzerPin);
  }

  Serial.print("X-axis: ");
  Serial.print(xValue);
  Serial.print(" | Y-axis: ");
  Serial.print(yValue);
  Serial.print(" | Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | Buzzer Frequency: ");
  Serial.println(frequency);
}