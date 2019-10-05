/**
 * This is a test program (Modifyied Fade Sketch) that will offset the PWM of four 
 * alternating LEDs: RED, YELLOW, RED, YELLOW 
 * 
 */
 
//Defining pins 9, 6, 5, and 3 as global variables
int Rone = 9;
int Yone = 6;
int Rtwo = 5;
int Ytwo = 3;
int brightness1 = 0;
int brightness2 = 90;
int brightness3 = 180;
int brightness4 = 270;
int fadeAmount = 5;

/*************** Setup ***************/
void setup() {
    pinMode(Rone, OUTPUT); 
    pinMode(Yone, OUTPUT);
    pinMode(Rtwo, OUTPUT);
    pinMode(Ytwo, OUTPUT);
}

/*************** Main Loop ***************/
void loop() {
    analogWrite(Rone, (sin(brightness1++ * 3.14 / 180) + 1) * 128);
    brightness1 %= 360;
 
    analogWrite(Yone, (sin(brightness2++ * 3.14 / 180) + 1) * 128);
    brightness2 %= 360;
 
    analogWrite(Rtwo, (sin(brightness3++ * 3.14 / 180) + 1) * 128);
    brightness3 %= 360;
 
    analogWrite(Ytwo, (sin(brightness4++ * 3.14 / 180) + 1) * 128);
    brightness4 %= 360;
 
    delay(3);
} 
//End
