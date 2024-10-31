// Lit le potentiomètre sur l'ADC0 et bouge le servo moteur en conséquence sur la pin 2 (DD2.1 du Grove Shield)
// ATTENTION, ici on ne va PAS utiliser la lib Servo.h d'Arduino mais faire la génération de pulse à la mano avec un delay

// zf220727.1634, zf241031.1549

/*
  Arduino Starter Kit example
  Project 5 - Servo Mood Indicator

  This sketch is written to accompany Project 5 in the Arduino Starter Kit

  Parts required:
  - servo motor
  - 10 kilohm potentiometer
  - two 100 uF electrolytic capacitors

  created 13 Sep 2012
  by Scott Fitzgerald

  https://store.arduino.cc/genuino-starter-kit

  This example code is part of the public domain.
*/

// include the Servo library
// #include <Servo.h>

// Servo myServo;  // create a servo object

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
  // myServo.attach(10); // attaches the servo on pin 10 to the servo object
  // myServo.attach(2); // attaches the servo on pin 10 to the servo object
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



