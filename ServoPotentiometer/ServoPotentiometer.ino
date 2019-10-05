#include <Servo.h>

// Variables 
Servo microServo;

/*************** Set up ***************/
void setup() {
    Serial.begin(115200);    // Initializing the serial stream ransfer stream in "bits per second." 
    microServo.attach(6);
}

/*************** Main Loop ***************/
void loop() {  
    long input = analogRead(1);    // 1 = Analog pin input.
    int rotation = input * 180 / 1023; 
  
    Serial.println("Write Value:");
    Serial.println(rotation); 

    microServo.write(rotation);

    // Motor Protection for invalid values or rotation.
    if (rotation > 180) 
        microServo.write(90);

    if (rotation < 0) 
        microServo.write(90);
  
} // End
