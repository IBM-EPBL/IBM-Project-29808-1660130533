#include <Servo.h>


Servo servobase;
#define t 6
#define e 7


void setup()
{
  Serial.begin(9600);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
  pinMode(e,INPUT);
  pinMode(t,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  servobase.attach(3);
  servobase.write(0);
}

void loop()
{
  int value=digitalRead(2);
  Serial.println(value);
  digitalWrite(4,value);
  digitalWrite(5,value);
  if(value>0)
    servobase.write(90);
  else
    servobase.write(0);
  digitalWrite(t,LOW);
  digitalWrite(t,HIGH);
  delayMicroseconds(10);
  digitalWrite(t,LOW);
  float dur=pulseIn(e,HIGH);
  float dis=((dur/2)*0.0343);
  Serial.print("Distance in cm:");
  Serial.println(dis);
  if(dis<100)
  {
    digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
    
  }
  else if(dis>100)
  {
    digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  }
  else if(dis>150)
  {
    digitalWrite(8,LOW);
  digitalWrite(8,LOW);
  digitalWrite(10,HIGH);
  }
}