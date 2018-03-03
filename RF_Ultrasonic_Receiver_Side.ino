// Zander Pangilinan, Mark Boettcher, and Sarah King
// Senior Design 2017-2018
// 3.3.18
// Maxbotix 1340 Ultrasonic Sensor
// Xbee Module Series 
// Arduino Zero
// The following code is for the "Receiver" side of the system. 

// Maxbotix pinout
// Pin 2 Returns waveform from initial pulse from transmitter. 
// Pin 4 pulled to GND for only "listening mode" 
// Pin 6 and 7 VCC and GND 

int Rxpin = 2;
int checkPin = 3;
int pulse; 

void setup() {
  pinMode(Rxpin, INPUT);
  pinMode(checkPin, OUTPUT);
  
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
  // check for ultrasonic pulse
  pulse = digitalRead(Rxpin);
  if(pulse == 1)
  { 
    digitalWrite(checkPin, HIGH);
  }
  else
  {
   digitalWrite(checkPin, LOW);
  }
  // 150 uS between pulse read and checkPin activated 
  
  // look for RF pulse
  if(Serial1.available())
  {
    Serial.println("hi");
  }
}
