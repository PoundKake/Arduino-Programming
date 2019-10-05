/*
    Robot.ino Header header
*/

//  Moves the Robot Forward.
void forward() {
  // Right Wheel
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);

  // Left Wheel
  digitalWrite(9, LOW);
  digitalWrite(12, HIGH);
}

//  Moves the Robot Backwards.
void reverse() {
  // Right Wheel
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  // Left Wheel
  digitalWrite(9, HIGH);
  digitalWrite(12, LOW);
}

//  Turns Left
void right() {
  // Right Wheel
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);

  // Left Wheel
  digitalWrite(9, LOW);
  digitalWrite(12, HIGH);
}

//  Turns Right
void left() {
  // Right Wheel
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);

  // Left Wheel
  digitalWrite(9, HIGH);
  digitalWrite(12, LOW);
}

//  Searches for an obstacle.
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

  // Testing Purposes
  delay(.0001);				// "Refresh Rate"
  Serial.print("Dist: ");
  Serial.print(dist);
  Serial.println(" cm");

  // Searches for an Obstacle
  if (dist <= 12) {
    return 1;
  }
  else {
    return 0;
  }
}

//end
