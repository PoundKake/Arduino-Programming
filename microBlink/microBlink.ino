/**
 * Program: microBlink.ino
 * Description: Sinusoidal blink test for future Arduino Micro project.
 * Version: v1.0
 * Last Modified: 10-06-2016
 */

//  Global Variables
int led = 0;

//  Setup 
void setup() {
    pinMode(5, OUTPUT);
}

//  Main Loop
void loop() {
    analogWrite(5, ( sin( led++ * 3.14 / 180 ) + 1 ) * 100);
    led %= 360;
    delay(5);
}
// End
