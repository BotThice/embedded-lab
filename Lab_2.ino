#define MOTOR  23

// void setup()
// {
//   pinMode(MOTOR, OUTPUT);
// }void loop()
// {
//   digitalWrite(MOTOR,)
//   digitalWrite(MOTOR, HIGH);
//   delay(5000); // Wait for 5000 millisecond(s)
//   digitalWrite(MOTOR, LOW);
//   delay(5000); // Wait for 5000 millisecond(s)
// }

//2.4
// #define STEP_PIN1 25
// #define STEP_PIN2 26
// #define STEP_PIN3 32
// #define STEP_PIN4 33

// int delaytime=3;
// bool reverse=false;

// int step_number=0;
// void setup(){
//   pinMode(STEP_PIN1,OUTPUT);
//   pinMode(STEP_PIN2,OUTPUT);
//   pinMode(STEP_PIN3,OUTPUT);
//   pinMode(STEP_PIN4,OUTPUT);

//   digitalWrite(STEP_PIN1,LOW);
//   digitalWrite(STEP_PIN2,LOW);
//   digitalWrite(STEP_PIN3,LOW);
//   digitalWrite(STEP_PIN4,LOW);
// }

// void loop(){
//   if(reverse){
//     digitalWrite(STEP_PIN1,HIGH);
//   delay(delaytime);
//   digitalWrite(STEP_PIN1,LOW);

//   digitalWrite(STEP_PIN2,HIGH);
//   delay(delaytime);
//   digitalWrite(STEP_PIN2,LOW);

//   digitalWrite(STEP_PIN3,HIGH);
//   delay(delaytime);
//   digitalWrite(STEP_PIN3,LOW);

//   digitalWrite(STEP_PIN4,HIGH);
//   delay(delaytime);
//   digitalWrite(STEP_PIN4,LOW);
//   }else{
//   digitalWrite(STEP_PIN4,HIGH);
//   delay(delaytime);
//   digitalWrite(STEP_PIN4,LOW);

//   digitalWrite(STEP_PIN3,HIGH);
//   delay(delaytime);
//   digitalWrite(STEP_PIN3,LOW);

//   digitalWrite(STEP_PIN2,HIGH);
//   delay(delaytime);
//   digitalWrite(STEP_PIN2,LOW);

//   digitalWrite(STEP_PIN1,HIGH);
//   delay(delaytime);
//   digitalWrite(STEP_PIN1,LOW);
//   }
//   step_number+=4*delaytime;
//   if(step_number>=5000){
//     reverse=!reverse;
//     step_number=0;
//   } 

  
// }

//2.5

#define PIN2 15
#define PIN7 2

void setup(){
  
  pinMode(PIN2,OUTPUT);
  pinMode(PIN7,OUTPUT);
  digitalWrite(PIN2,LOW);
  digitalWrite(PIN7,LOW);
}

void loop(){
  digitalWrite(PIN2,HIGH);
  digitalWrite(PIN7,LOW);
  delay(5000);
  digitalWrite(PIN2,LOW);
  digitalWrite(PIN7,HIGH);
  delay(5000);
  digitalWrite(PIN2,HIGH);
  digitalWrite(PIN7,HIGH);
  delay(5000);
  digitalWrite(PIN2,LOW);
  digitalWrite(PIN7,LOW);
  delay(5000);

}
 