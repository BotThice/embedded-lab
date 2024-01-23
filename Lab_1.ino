// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   //Serial.println("Hello World!");
// }
// void loop() {
//   // put your main code here, to run repeatedly:
//   Serial.println("Hello World");
//   delay(1000);
// }

//LAB1.2

#define LED 23
#define DELAY_TIME 1000
#define BUTTON 32
// void setup() {  
//   // initialize digital pin LED_BUILTIN as an output.
//  Serial.begin(9600);
//   pinMode(LED, OUTPUT);
// }
// // the loop function runs over and over again forever
// void loop() {
//   digitalWrite(LED, HIGH);   // turn the LED on 
//   delay(DELAY_TIME);             // wait for a second
//   digitalWrite(LED, LOW);    // turn the LED off 
//   delay(DELAY_TIME);             // wait for a second
// }

//Lab 3
int count=0;
void setup() { 
  Serial.begin(9600);
  pinMode(BUTTON, INPUT); // set arduino pin to input mode
  pinMode(LED, OUTPUT);  // set arduino pin to output mode
  
}
void loop() {
  if(digitalRead(BUTTON)==LOW) { 
    digitalWrite(LED, HIGH);
    count++;
    Serial.println(count);
    while(digitalRead(BUTTON)==LOW);
  }else{
    digitalWrite(LED, LOW);
  }
}