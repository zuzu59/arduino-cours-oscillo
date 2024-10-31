// envoie un caractère ascii sur le 2e port UART afin de pouvoir le 'voir' avec un oscilloscope

// zf220727.1634, zf241031.1735

// Sources:
// https://seeeddoc.github.io/Grove-Base_shield_v2/res/Base_Shield_v2.pdf
// https://docs.arduino.cc/tutorials/communication/SoftwareSerialExample/
// https://www.ascii-code.com/fr


#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 3); // RX, TX

// General

String zString = "toto";


void setup() {
  Serial.begin(9600); // open a serial connection to your computer
  mySerial.begin(9600);
  delay(1000);
  Serial.println("\n\ncoucou\n");
}

void loop() {
  zString = "D";

  // print out the value to the Serial Monitor
  Serial.println(zString);
  mySerial.print(zString);

  // wait 
  delay(1550);
}
