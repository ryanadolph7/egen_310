#include <IRremote.h>
#include <Servo.h>

Servo myServo;

int RECV_PIN = 2;	// set receiver pin to 2
int RED_LED = 10;
int GREEN_LED = 8;
bool keepGoing = false;


void setup()
{
  Serial.begin(9600); 	// Serial Monitor @ 9600 baud
  IrReceiver.begin(RECV_PIN);	// Enable the IR Receiver
  myServo.attach(11);
}

void loop()
{
  if (IrReceiver.decode()) { 	// if the receiver has decoded anything
    Serial.println(IrReceiver.decodedIRData.command);	// print the decoded info
  
    IrReceiver.resume();		// resume listening
  }
}
