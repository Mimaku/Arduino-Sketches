# RGB-LED Morsecode Prototype
  
This is a RGB-LED morscode sketch.  
It is build upon the Simple RGB-LED Fader Sketch. Since fully functional, the code is rather ugly and messy.
  
## Requirements
  
1x Arduino Uno R3  
1x Breadboard  
1x RGB-LED  
3x 220Ohm Resistors  
4x Jumper Wire  
  
## Function
  
```c
// Morsecode function  
  
void morse(char message[])  
``` 
  
## Usage

```c
// Declare your message as a char-array  
  
char helloWorld[] = "Hello World";  
  
...  
  
void loop() {  
  morse(helloWorld);  
}  
``` 
  
## Note
  
Make sure you use your PWM-enabled Output-Pins, since this sketch is build upon the Simple RGB-LED Fader Sketch.  
This Sketch utilizes the pins 11, 10, 9 for red, green and blue cathodes of the RGB-LED.
