# Simple RGB-LED Crossfader
  
This is a simple RGB-LED crossfader sketch.
  
## Requirements
  
1x Arduino Uno R3  
1x Breadboard  
1x RGB-LED  
3x 220Ohm Resistors  
4x Jumper Wire  
  
## Function
  
```c
// RGB-LED crossfader function  
// variable fade-in- and on-time in milliseconds for the specified color  
  
void crossfadeLed(int fadeInTime, int onTime, byte color[3])  
``` 
  
## Usage

```c
// Specify your color as an array  
  
byte red[3] = {255, 0, 0};  
byte magenta[3] = {255, 0, 255};  
  
...  
  
void loop() {  
  crossfadeLed(1000, 1000, red);  
  crossfadeLed(500, 1000, magenta);  
}  
``` 
  
## Note
  
Make sure you use your PWM-enabled Output-Pins.  
This Sketch utilizes the pins 11, 10, 9 for red, green and blue cathodes of the RGB-LED.
