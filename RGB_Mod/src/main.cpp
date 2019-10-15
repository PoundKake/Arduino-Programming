// Libraries to include in project.
#include <Arduino.h>

// Globally defined variables.
#define PIN9 9
#define PIN10 10
#define PIN11 11

int G = 125;     // This represents the gain of the sin funtion. This should be 255/2 = 128. Can be adjusted depending on brightness.

int phase1 = 0;
int phase2 = 90;
int phase3 = 180;
int PINS [3] = {PIN9, PIN10, PIN11};
int phases [3] = {phase1, phase2, phase3};

// Initial set up function.
void setup() {
// put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0; i<3; i++){
    pinMode(i, OUTPUT);
  }
}

// Applications main loop.
void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0; i<3; i++) {
    analogWrite(PINS[i], G*(sin(phases[i]++*3.15/180) + 1)); 
  }
  delay(15);
} //END
