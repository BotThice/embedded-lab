#define LED 23

void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  digitalWrite(LED,LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
 
    digitalWrite(LED,HIGH);
    delay(5000);
    digitalWrite(LED,LOW);
    delay(5000);

}
