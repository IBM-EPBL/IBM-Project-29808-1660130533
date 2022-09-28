int redLed = 13;
int greenLed = 12;
int yelloled = 9;
int buzzer = 11;
int smokeA0 = A0;


void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yelloled, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int analogSensor = analogRead(smokeA0);

  Serial.print("Gas Level: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > 682 && analogSensor < 719)
  {
    digitalWrite(yelloled, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
    tone(buzzer, 3000, 200);
    Serial.print("\nLeakage Detecting");
  }
  else if(analogSensor > 720)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    digitalWrite(yelloled, LOW);
    tone(buzzer, 1000, 200);
    Serial.print("\nLeakage Detected");
  }
   
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(yelloled, LOW);
    noTone(buzzer);
    Serial.print("\nNo Leakage Found");
  }
    
  delay(100);
}