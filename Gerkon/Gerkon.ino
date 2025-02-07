
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(7));
  delay(100);
}
