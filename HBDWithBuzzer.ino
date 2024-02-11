#define BUZZER 16
#define BUTTON 32
hw_timer_t *Sound = NULL;
hw_timer_t *Stage = NULL;

#define G  638
#define A  568
#define C7 478
#define B  506
#define D7 426
#define E7 379
#define F7 358
#define G7 319

#define Full 350000
#define Half Full/2
#define Double Full*2

int note[29] = {  G,0,G,A,G,C7,B, G,0,G,A,G,D7,C7, G,0,G,G7,E7,C7,B,A,  F7,0,F7,E7,C7,D7,C7};
int tempo[29] = { Half*0.9,Half*0.1,Half,Full,Full,Full,Double,    Half*0.9,Half*0.1,Half,Full,Full,Full,Double,  Half*0.9,Half*0.1,Half,Full,Full,Full,Full,Double,   Half*0.9,Half*0.1,Half,Full,Full,Full,Double};
int arrLength = sizeof(note) / sizeof(int);
int noteCount = 0;
int tempoCount = 0;
double songSpeed[5] = {0.5,0.75,1,1.5,2};
double currentSpeed = songSpeed[2];
int idx = 1;

void IRAM_ATTR pulseGen(){
  digitalWrite(BUZZER, !digitalRead(BUZZER));
}

void IRAM_ATTR changeSpeed(){
  currentSpeed = songSpeed[idx];
  idx = (idx + 1)%5;
}
int runNote(){
  int t = note[noteCount]/2; //ใช้ Octave 6 แล้วฟังในBuzzerไม่ออกเลย /2 มาใช้ 5 แทน
  noteCount = (noteCount + 1)%arrLength;
  return t;
}
int runTempo(){
  double t = tempo[tempoCount] * currentSpeed;
  tempoCount = (tempoCount + 1)%arrLength;
  return t;
}



void IRAM_ATTR start(){
  timerAlarmWrite(Sound, runNote(), true);
  timerAlarmEnable(Sound);
  timerAlarmWrite(Stage, runTempo(), true);
  timerAlarmEnable(Stage);
}

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT);
  
  attachInterrupt(BUTTON, changeSpeed, RISING);
  Sound = timerBegin(0, 80, true);
  Stage = timerBegin(1, 80, true);
  timerAttachInterrupt(Sound, &pulseGen, true);
  timerAttachInterrupt(Stage, &start, true);
  
  start();
} 

void loop()
{
  // Do nothing....
}