# Simple RGB-LED Fader
  
This is a simple RGB-LED fader sketch. You can't crossfade from one color into another.
  
## Requirements
  
1x Arduino Uno R3  
1x Breadboard  
1x RGB-LED  
3x 220Ohm Resistors  
4x Jumper Wire  
  
## Function
  
```c
// RGB-LED fader function  
// variable fade-in- / fade-out- / on- / off-time in milliseconds for the specified color  
// use fadeInTime/fadeOutTime = 0 for (single) blink  
  
void fadeLed(int fadeInTime, int onTime, int fadeOutTime, int offTime, byte color[3])  
``` 
  
## Usage

```c
// Specify your color as an array  
  
byte red[3] = {255, 0, 0};  
byte magenta[3] = {255, 0, 255};  
  
...  
  
void loop() {  
  fadeLed(2000, 250, 2000, 250, red);  
  fadeLed(1000, 1000, 2000, 0, magenta);  
}  
``` 
  
## Note
  
Make sure you use your PWM-enabled Output-Pins.  
This Sketch utilizes the pins 11, 10, 9 for red, green and blue cathodes of the RGB-LED.
