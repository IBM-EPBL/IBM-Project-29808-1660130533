int  LED = A1;
const int gas = 0;
int MQ2pin = A0;
int baselineTemp = 0;
const int buzzer = 9;
int celsius= 0;
void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  float sensorValue, MQ2pin;
  sensorValue = analogRead(MQ2pin);
  int sensor = analogRead(A2);
  float voltage = (sensor / 1024.0) * 5.0;
  float tempC = (voltage - .5) * 100;
  if(tempC >= 40){
    digitalWrite(LED, HIGH);
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
    Serial.println("Temp Values: ");
    Serial.println(tempC);
  }
  if(sensorValue <= 300){
	digitalWrite(LED, LOW);
    Serial.print(sensorValue);
    Serial.println("!SMOKE DETECTED");
  }
  else{
    tone(buzzer, 1000);
    delay(200);
    noTone(buzzer);
  	digitalWrite(LED, HIGH);
    Serial.println("Sensor Values: ");
    Serial.println(sensorValue);
  }
  delay(1000);
}
float getsensorValue(int pin){
  return (analogRead(pin));
}