#include <pins_arduino.h>
const byte beeper = 13;
const byte PIR_Pins[]={2, 3, 18, 19, 20, 21};
const byte greenledPins[]={22,26,30,34,38,42};
const byte yellowledPins[]={24,28,32,36,40,44};
volatile byte stateBeeper = LOW,state;
void (*pointerISRS[6])()={PIR0,PIR1,PIR2,PIR3,PIR4,PIR5};
uint8_t currentBox=0,nextBox=0;
volatile int interupptNum[6]={0};

void setup() {
  Serial.begin(9600);
  pinMode(beeper,OUTPUT);
  for(int i=0;i<6;i++){
    pinMode(greenledPins[i],OUTPUT);
    pinMode(yellowledPins[i],OUTPUT);
    pinMode(PIR_Pins[i],INPUT);
    attachInterrupt(digitalPinToInterrupt(PIR_Pins[i]),pointerISRS[i],RISING);//CHANGE
  }
}

void loop() {
  while(Serial.available() == 0);
  currentBox=(uint8_t)Serial.read();
  if(currentBox>5 || currentBox<0)currentBox=0;
  while(Serial.available() == 0);
  nextBox=(uint8_t)Serial.read();
  if(nextBox>5 || nextBox<0)nextBox=0;
  for(int i=0;i<6;i++){
    digitalWrite(greenledPins[i], LOW);
    digitalWrite(yellowledPins[i], LOW);
  }
  digitalWrite(greenledPins[currentBox],HIGH);
  digitalWrite(yellowledPins[nextBox],HIGH);
  digitalWrite(beeper, LOW);
}

void PIR0() {
  if(currentBox==0)Serial.println("next");
  else digitalWrite(beeper,HIGH);
}

void PIR1() {
  if(currentBox==1)Serial.println("next");
  else digitalWrite(beeper,HIGH);
}

void PIR2() {
 if(currentBox==2)Serial.println("next");
 else digitalWrite(beeper,HIGH);
}

void PIR3() {
  if(currentBox==3)Serial.println("next");
  else digitalWrite(beeper,HIGH);
}

void PIR4() {
  if(currentBox==4)Serial.println("next");
  else digitalWrite(beeper,HIGH);
}

void PIR5() {
  if(currentBox==5)Serial.println("next");
  else digitalWrite(beeper,HIGH);
}
