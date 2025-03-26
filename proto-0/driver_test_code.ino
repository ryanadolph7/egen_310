#include <IRremote.h>
#include <Servo.h>

// Pin assignments
int Speed_Pin = 6;
int in1Pin = 8;
int in2Pin = 7;
int rec_pin = 2;
int red_pin = 9;
int green_pin = 10;
int blue_pin = 11;


// Object assignments
Servo myServo;

void setup() {

  // Setting serial monitor baud rate to see IR Sensor values
  Serial.begin(9600); 	// Serial Monitor @ 9600 baud

  // IR Sensor controller
  IrReceiver.begin(rec_pin);	// Enable the IR Receiver

  // Servo Controller 
  myServo.attach(11);

  // Setting pins for Motor controller
  pinMode(Speed_Pin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);

  // PCB Controller
  pinMode(red_pin, OUTPUT);

}

void loop() {

  if (IrReceiver.decode()) { 	// if the receiver has decoded anything
    Serial.println(IrReceiver.decodedIRData.command);	// print the decoded info

    switch (IrReceiver.decodedIRData.command) {

      // -----------------------------------------------
      // Motor Driver 
      //------------------------------------------------

      case 70:    // move foward from play / pause button press
        digitalWrite(in1Pin, HIGH);
        digitalWrite(in2Pin, LOW);
        digitalWrite(Speed_Pin, HIGH);
        Serial.println("Moving motors forward");
        //delay(2000); // Run forward for 2 seconds
        break;

      case 64:    // stop motors from vol - 
          digitalWrite(in1Pin, LOW);
          digitalWrite(in2Pin, LOW);
          Serial.println("Stopping motors");
          //delay(1000); // Pause for 1 second
        break;

      case 21:  // Move backward from EQ button press
        digitalWrite(in1Pin, LOW);
        digitalWrite(in2Pin, HIGH);
        digitalWrite(Speed_Pin, HIGH);
        Serial.println("Moving motors backwards");
       //delay(2000); // Run backward for 2 seconds
        break;

      case 71:  // move the servo back / forth 4 times
        Serial.println("Swinging servo");
        for (int i = 0; i < 5; i++) {   
          myServo.write(180);    
          delay(500);        // wait 1 second before writing a different angle
          myServo.write(0);
          delay(500);
        }
        break;

      case 0: 
        Serial.println("Stop pointing a camera at me!!!");
        break;

      default: 
        Serial.println("No input / bad input ... doing nothing");
        break;


    }

    IrReceiver.resume();		// resume IR sensor listening

  }

}
