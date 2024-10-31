// Lit le potentiomètre sur l'ADC0 et bouge le servo moteur en conséquence sur la pin 2 (DD2.1 du Grove Shield)
// ATTENTION, ici on ne va PAS utiliser la lib Servo.h d'Arduino mais faire la génération de pulse à la mano avec un delay

// zf220727.1634, zf241031.1641

// General
const int ledPin = 33;             // the number of the LED pin
//const int buttonPin = 9;          // the number of the pushbutton pin
const int servoPin = 2;             // the number of the servo pin

int const potPin = A0; // analog pin used to connect the potentiometer
int potVal;  // variable to read the value from the analog pin
int angle;   // variable to hold the angle for the servo motor


void zServoPulseUs(int zPulse ) {
  Serial.print("zPulse: ");
  Serial.println(zPulse);

  digitalWrite(servoPin, HIGH);
  delayMicroseconds(zPulse);
  digitalWrite(servoPin, LOW);

}


void setup() {
  Serial.begin(9600); // open a serial connection to your computer
  pinMode(servoPin, OUTPUT);
}

void loop() {
  potVal = analogRead(potPin); // read the value of the potentiometer
  // print out the value to the Serial Monitor
  Serial.print("potVal: ");
  Serial.print(potVal);

  angle = map(potVal, 1023, 0, 2400, 660);
  zServoPulseUs(angle);

  // wait for the servo to get there
  delay(50);
}
