int LED_pins[] = {2,3,4,5};
int num_LED = 0;
int delta = 1;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);

  for(int i=0; i< sizeof(LED_pins)/sizeof(int); i++){
    pinMode(LED_pins[i], OUTPUT);
    digitalWrite(LED_pins[i], LOW);
  }
}

void loop() {
  if(Serial1.available()){
    char data = Serial1.read();
    if(data == '1'){
      num_LED += delta;

      if(num_LED == 5){
        delta = -1;
        num_LED = 3;
      }
      else if(num_LED == -1){
        delta = 1;
        num_LED = 1;
      }

      Serial.print("Currently ");
      Serial.print(num_LED);
      Serial.print(" LEDs are ON.");

      for(int i=0; i<sizeof(LED_pins)/sizeof(int); i++){
        if(i < num_LED)
          digitalWrite(LED_pins[i], HIGH);
        else
          digitalWrite(LED_pins[i], LOW);
      }
    }
  }
}
