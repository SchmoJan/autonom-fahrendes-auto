#define POTENSIO_PIN  0 // Pin Potentiometer A0
#define RPWM_PIN      5 // Digital Pin 5 Arduino Arduino
#define LPWM_PIN      6 // Digital Pin 6 Arduino Arduino

void setup()
{
pinMode(RPWM_PIN, OUTPUT);
pinMode(LPWM_PIN, OUTPUT);
}

void loop()
{
// sensor value range 0 to 1023
int sensorValue = analogRead(POTENSIO_PIN);

// reverse rotation
if (sensorValue < 512)
{
int reversePWM = -(sensorValue - 511) / 2;
analogWrite(LPWM_PIN, 0);
analogWrite(RPWM_PIN, reversePWM);
}

else{
// forward rotation
int forwardPWM = (sensorValue - 512) / 2;
analogWrite(LPWM_PIN, forwardPWM);
analogWrite(RPWM_PIN, 0);
}
}
