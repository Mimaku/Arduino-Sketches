# Active Buzzer Morsecode
  
This is a morsecode sketch utilizing an active buzzer. You can vary the speed with a potentiometer.  
Compared to the old version, this is a major rewrite. The code should be more readable and furthermore it uses less functions.  
  
## Requirements
  
1x Arduino Uno R3  
1x Breadboard  
1x Active Buzzer  
1x Potentiometer  
6x Jumper Wire  
  
## Function
  
```c
// Morsecode function  
  
void morse(char *message)  
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
