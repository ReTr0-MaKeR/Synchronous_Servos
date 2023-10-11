#include <Servo.h>

Servo servo1;
Servo servo2;
int angle;

void setup() 
{
  servo1.attach(9);
  servo2.attach(10);
}

void loop() 
{
  servo1.write(0);
  servo2.write(0);

  // for 30 seconds, servo 1 moves 0 to 60, and servo 2 remains at 0
  for (angle = 0; angle <= 60; angle++)
  {
    servo1.write(angle);
    servo2.write(0);
    delay(500);
  }

  // for the next 30 seconds, both servos moves to 180
  for (angle = 60; angle <= 180; angle += 2)
  {
    servo1.write(angle);
    int i =map(angle,60,180,0,180);
    servo2.write(i);
    delay(500);
  }
  // for 30 seconds, servo 1 moves 180 to 60, and servo 2 remains at 180
  for (angle = 180; angle >= 60; angle -=2)
  {
    servo1.write(angle);
    servo2.write(180);
    delay(500);
  }
  // for the next 30 seconds, both servos moves to 0
  for (angle = 60; angle >= 0; angle --)
  {
    servo1.write(angle);
    int i =map(angle,60,0,180,0);
    servo2.write(i);
    delay(500);
  }
}
