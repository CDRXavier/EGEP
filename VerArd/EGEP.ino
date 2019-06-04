#include <Arduboy2.h>
#include <ArduboyTones.h>
int8_t squareX = 3;
int8_t squareY = 3;
int8_t circleX = 64;
int8_t circleY = 32;
Arduboy2 arduboy;
ArduboyTones sound(arduboy.audio.enabled);
void setup()
{
  arduboy.begin();
  arduboy.initRandomSeed();
  arduboy.setFrameRate(30);
  arduboy.clear();
  circleX = random(3, 125);
  circleY = random(3, 61);
}

void loop()
{
  if (arduboy.nextFrame()) {
    arduboy.clear();
    if (arduboy.pressed(UP_BUTTON))
      squareY -= 1;
    if (arduboy.pressed(DOWN_BUTTON))
      squareY += 1;
    if (arduboy.pressed(LEFT_BUTTON))
      squareX -= 1;
    if (arduboy.pressed(RIGHT_BUTTON))
      squareX += 1;
    if (squareX < 3) squareX = 125;
    if (squareX > 125) squareX = 3;
    if (squareY < 3) squareY = 61;
    if (squareY > 61) squareY = 3;
    if (abs(squareX - circleX) < 5 && abs (squareY - circleY) < 5) {
      circleX = random(3, 125);
      circleY = random(3, 61);
      sound.tone(400, 5);
      delay(5);
      sound.tone(500, 5);
      delay(5);
      sound.tone(600, 5);
      delay(5);
      sound.tone(700, 5);
      delay(5);
      sound.tone(800, 5);
      delay(5);
      sound.tone(900, 5);
      delay(5);
      sound.tone(1000, 5);
    }
    arduboy.drawRect(squareX - 2, squareY - 2, 5, 5, 1);
    arduboy.drawCircle(circleX, circleY, 2, 1);
    arduboy.display();
  }
}

