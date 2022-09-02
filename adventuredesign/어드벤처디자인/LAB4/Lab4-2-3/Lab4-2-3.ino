int pins_LED[] = {2,3};
int pins_button[] = {15,16};
void setup() {
  Serial.begin(9600);
  for (int i =0;i <2;i++){
    pinMode(pins_button[i],INPUT);
    pinMode(pins_LED[i],OUTPUT);
  }
}

void loop() {
  for (int i = 0; i<2;i++){
    boolean state = digitalRead(pins_button[i]);
    digitalWrite(pins_LED[i],state);
    Serial.print(state);
    Serial.print(" ");
  }
  Serial.println();
  delay(1000);
}
