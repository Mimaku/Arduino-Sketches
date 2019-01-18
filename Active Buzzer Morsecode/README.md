# Active Buzzer Morsecode
  
This is a morsecode sketch utilizing an active buzzer.  
Since functional, the code is rather ugly and messy. Furthermore there is room for optimization in the charToBeep().  
  
## Requirements
  
1x Arduino Uno R3  
1x Breadboard  
1x Active Buzzer  
2x Jumper Wire  
  
## Function
  
```c
// Morsecode function  
  
void morse(char message[])  
``` 
  
## Usage

```c
// Declare your message as a char-array  
  
char message[] = "Hello World";  
  
...  
  
void loop() {  
  morse(message);  
}  
```  
