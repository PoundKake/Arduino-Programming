#include "variables.h"
#include "functions.h"

/**
 * Program: Robot.ino
 * Description: Autonomous robot functionality. This is a program that will allow a basic test of the Robot's funtionality.
 * Version: 0.1
 * Last Modified: 9/28/2018	
 */

//  Variable Declaration.
const int trig = 8;	// Sensro trigger Pin 
const int echo = 7;	// Sensor echo Pin 
const int V    = 3;	// Sensor power

//  States
int rest     = 0x0;	// 0000
int search   = 0x1;	// 0001
int discover = 0x2;	// 0010
int avoid    = 0x3;	// 0011


/*************** Setup ***************/
void setup() {
    // Sensor Pin 
    pinMode(trig, OUTPUT);    	
    pinMode(echo, INPUT);	
    pinMode(V, OUTPUT);		

    // Right Wheel 
    pinMode(10, OUTPUT);	
    pinMode(11, OUTPUT);		
	
    // Left Wheel
    pinMode(9, INPUT);	
    pinMode(12, INPUT);	

    Serial.begin(19200);    // Initializing the baud rate

    // PWM 
    pinMode(5, OUTPUT);     // Right Wheel
    pinMode(6, OUTPUT);	    // Left Wheel
}

/*************** Functions ***************/
/*
 * forward()
 * Moves the Robot Forward.
 */
void forward() {
    // Right Wheel
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);

    // Left Wheel
    digitalWrite(9, LOW);
    digitalWrite(12, HIGH);
}


/*
 * reverse()
 * Moves the Robot Backwards.
 */
void reverse() {
    // Right Wheel
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);

    // Left Wheel
    digitalWrite(9, HIGH);
    digitalWrite(12, LOW);
}


/*
 * right()
 * Turns right continuosly until stopped.
 */
void right() {
    // Right Wheel
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);

    // Left Wheel
    digitalWrite(9, LOW);
    digitalWrite(12, HIGH);
}


/*
 * left()
 * Turns left continuosly until stopped.
 */
void left() {
    // Right Wheel
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);

    // Left Wheel
    digitalWrite(9, HIGH);
    digitalWrite(12, LOW);
}


/*
 * obst()
 * Searches for an obstacle.
 */
int obst() {
    // HC-SR04 Functionality
    long dur, dist;
    digitalWrite(trig, HIGH);
    delay(.002);
    digitalWrite(trig, LOW);
    delay(.01);
    digitalWrite(trig, HIGH);
    dur = pulseIn(echo, HIGH);
    dist = (dur / 2) / 29.1;

    delay(.0001);            // "Refresh Rate"
    Serial.print("Dist: ");
    Serial.print(dist);
    Serial.println(" cm");

    // Searches for an Obstacle
    if (dist <= 12) 
        return 1;

    else 
        return 0;
    
}

/*************** Main Loop ***************/
void loop() {
    // Turn on the Motor Controller
    digitalWrite(V, HIGH);

    // Initialize PWM Speed
    analogWrite(5, 160);
    analogWrite(6, 160);

    // Autonomous Obstacle Avoider
    int obstacle = obst();

    if (obstacle != 1) {
        int o = obst();
    	while (o == 1)
	{
            right();
	}

	reverse();
    }

    else 
	forward();

    // NOTE: Future implemenation of Bug algorithms for obstacle avoidance.

} // End
