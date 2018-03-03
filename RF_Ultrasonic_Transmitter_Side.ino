// Mark Boettcher, Sarah King, and Zander Pangilinan
// Senior Design 2017-2018
// 3.3.18
// Maxbotix 1340 Ultrasonic Sensor
// Xbee Module Series
// Arduino Zero
// The following code is for the "Transmitter" Sensor. 

// Maxbotix pinout
// Pin 1 is pulled to ground to allow use of Pin 5
// Pin 4 is used to transmit a pulse based on user interval
// Pin 5 used as reference for when pulse transmitted 
// Pin 6 and 7 VCC and GND 

/* 
Arduino Transmitter Program

Description: A simple program that sends serial data to the 
XBee to transmit.
*/

const int TxPin = 2;
long interval = 200;

void setup() {
  pinMode(TxPin, OUTPUT);
  
  // initialize serial:
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.print("+++");
  delay(1020);
  while(Serial1.available())
  {
    Serial.print((char) Serial1.read());
  }
  Serial1.print("ATBD 0xF4240\r");
  delay(1000);
  while(Serial1.available())
  {
    Serial.print((char) Serial1.read());
  }
  
  Serial.begin(1000000);
  Serial1.begin(1000000);
}

void loop() {
  // send ultrasonic pulse based on delay interval
  digitalWrite(TxPin, HIGH);     
  delay(1);
  digitalWrite(TxPin, LOW);
  delay(interval);                      
  
  // Send RF pulse 
  //Writes 1001 in hexadecimal
  Serial1.write(4097);
  delay(1000);
}
