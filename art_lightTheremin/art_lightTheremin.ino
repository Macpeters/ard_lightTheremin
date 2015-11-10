int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

//indicator that censor has finished calibrating - use onboard led connected to 13
const int ledPin = 13;


void setup() {
  //turn the led light on
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  //for 5 seconds, check how high and low the values go (max/min)
  while(millis() < 5000){
      sensorValue = analogRead(A0);
      if(sensorValue > sensorHigh){
        sensorHigh = sensorValue;
      }else if(sensorValue < sensorLow){
        sensorLow = sensorValue;
      }
  }
  //calibration done, turn off the light
  digitalWrite(ledPin, LOW);
}

void loop() {
  //get the value
  sensorValue = analogRead(A0);
  //final values set the range of frequencies arduino will generate
  int pitch = map(sensorValue, sensorLow, sensorHigh, 0, 3000);
  //call with the pin number, the pitch, and how long to play the note
  tone(8, pitch, 20);
  delay(10);
}
