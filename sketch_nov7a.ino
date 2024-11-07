// needed library
#include <Adafruit_CircuitPlayground.h>

// Variables for the sensor input
int sensor1;
int sensor2;

// Variables for output
int ledPattern;
int soundEffect;

void setup() {
 CircuitPlayground.begin();

 //setting up sensor pins as inputs
 pinMode(A1, INPUT);
 pinMode(A2, INPUT);

 // Set output pins as outputs
 pinMode(13, OUTPUT);
 pinMode(10, OUTPUT);
}

void loop() {
 //sensor inputs
 sensor1 = analogRead(A1);
 sensor2 = analogRead(A2);

 // Map inputs to the output range
 ledPattern = map(sensor1, 0, 1023, 0, 5);
 soundEffect = map(sensor2, 0, 1023, 0, 10);

 // controling LED pattern
 switch (ledPattern) {
   case 0:
     // Turn off all LEDs
     CircuitPlayground.clearPixels();
     break;
   case 1:
     // Set all LEDs to red
     CircuitPlayground.setPixelColor(0, 255, 0, 0);
     CircuitPlayground.setPixelColor(1, 255, 0, 0);
     CircuitPlayground.setPixelColor(2, 255, 0, 0);
     CircuitPlayground.setPixelColor(3, 255, 0, 0);
     CircuitPlayground.setPixelColor(4, 255, 0, 0);
     break;
   case 2:
     // Set all LEDs to green
     CircuitPlayground.setPixelColor(0, 0, 255, 0);
     CircuitPlayground.setPixelColor(1, 0, 255, 0);
     CircuitPlayground.setPixelColor(2, 0, 255, 0);
     CircuitPlayground.setPixelColor(3, 0, 255, 0);
     CircuitPlayground.setPixelColor(4, 0, 255, 0);
     break;
   case 3:
     // Set all LEDs to blue
     CircuitPlayground.setPixelColor(0, 0, 0, 255);
     CircuitPlayground.setPixelColor(1, 0, 0, 255);
     CircuitPlayground.setPixelColor(2, 0, 0, 255);
     CircuitPlayground.setPixelColor(3, 0, 0, 255);
     CircuitPlayground.setPixelColor(4, 0, 0, 255);
     break;
   case 4:
     // Set all LEDs to rainbow
     CircuitPlayground.setPixelColor(0, 255, 0, 0);
     CircuitPlayground.setPixelColor(1, 255, 127, 0);
     CircuitPlayground.setPixelColor(2, 255, 255, 0);
     CircuitPlayground.setPixelColor(3, 0, 255, 0);
     CircuitPlayground.setPixelColor(4, 0, 0, 255);
     break;
   case 5:
     // Set all LEDs to random colors
     CircuitPlayground.setPixelColor(0, random(255), random(255), random(255));
     CircuitPlayground.setPixelColor(1, random(255), random(255), random(255));
     CircuitPlayground.setPixelColor(2, random(255), random(255), random(255));
     CircuitPlayground.setPixelColor(3, random(255), random(255), random(255));
     CircuitPlayground.setPixelColor(4, random(255), random(255), random(255));
     break;
 }

 // Use sensor inputs to control sound effect
 for (int i = 0; i < soundEffect; i++) {
   // Play a tone with a random frequency and duration
   tone(10, random(1000), random(500));
   delay(100);
 }
}

