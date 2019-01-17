// Declare global variables

// Replace pin-number with name for future use
#define REDPIN 11
#define GREENPIN 10
#define BLUEPIN 9

// color arrays
byte black[3]   = {0, 0, 0};
byte white[3]   = {255, 255, 255};

byte red[3]     = {255, 0, 0};
byte green[3]   = {0, 255, 0};
byte blue[3]    = {0, 0, 255};

byte yellow[3]  = {255, 255, 0};
byte magenta[3] = {255, 0, 255};
byte cyan[3]    = {0, 255, 255};

// Value of the PWM-Level in analogWrite()
// use byte as data type for 8-Bit unsigned number, from 0-255
byte redValue = 0;
byte greenValue = 0;
byte blueValue = 0;

// delayTime in for-loops
int delayTime = 10;

// Setup
void setup() {
  // declare pins for RGB-LED
  pinMode(REDPIN, OUTPUT); // RED LED
  pinMode(GREENPIN, OUTPUT); // GREEN LED
  pinMode(BLUEPIN, OUTPUT); // BLUE LED

  // serial output for debugging
  Serial.begin(9600);
}

// Loop
void loop() {
  // put your main code here, to run repeatedly:
  
  
  fadeLed(2000, 250, 2000, 250, red);
  fadeLed(2000, 250, 2000, 250, green);
  fadeLed(2000, 250, 2000, 250, blue);

  fadeLed(1000, 250, 2000, 0, yellow);
  fadeLed(1000, 250, 2000, 0, magenta);
  fadeLed(1000, 250, 2000, 0, cyan);
  
  fadeLed(0, 250, 0, 250, white);

  // Pause between new loop
  delay(2000);
}

// Fade Function with variable Fade-In, Fade-Out, On-/Off-Time for the set color
// use fadeInTime/fadeOutTime = 0 for blink
void fadeLed(int fadeInTime, int onTime, int fadeOutTime, int offTime, byte color[3] ){

  // FADEIN phase
  int fadeInDelay = fadeInTime / 255;
  for (byte i = 0; i < 255; i++) {
    // set pin to PWM-Level for the specific color
    analogWrite(REDPIN, redValue);
    analogWrite(GREENPIN, greenValue);
    analogWrite(BLUEPIN, blueValue);

    // increment PWM-Level
    if(redValue < color[0]) {
      redValue += 1;
    }
    if(greenValue < color[1]) {
      greenValue += 1;
    }
    if(blueValue < color[2]) {
      blueValue += 1;
    }
    
    delay(fadeInDelay);
  }
  
  // Debug
  Serial.println("FADEIN ENDVALUES");
  Serial.print(redValue);
  Serial.print("\t");
  Serial.print(greenValue);
  Serial.print("\t");
  Serial.print(blueValue);
  Serial.print("\t");
  Serial.println("");
  
  // ON phase
  delay(onTime);
  
  // FADEOUT phase
  int fadeOutDelay = fadeOutTime / 255;
  for (byte i = 0; i < 255; i++) {
    // set pin to PWM-Level for the specific color
    analogWrite(REDPIN, redValue);
    analogWrite(GREENPIN, greenValue);
    analogWrite(BLUEPIN, blueValue);

    // increment PWM-Level
    if(redValue != 0) {
      redValue -= 1;
    }
    if(greenValue != 0) {
      greenValue -= 1;
    }
    if(blueValue != 0) {
      blueValue -= 1;
    }

    delay(fadeOutDelay);
  }
  // turn pins fully off
  digitalWrite(REDPIN, LOW);
  digitalWrite(GREENPIN, LOW);
  digitalWrite(BLUEPIN, LOW);

  // Debug
  Serial.println("FADEOUT ENDVALUES");
  Serial.print(redValue);
  Serial.print("\t");
  Serial.print(greenValue);
  Serial.print("\t");
  Serial.print(blueValue);
  Serial.print("\t");
  Serial.println("");

  // OFF phase
  delay(offTime);
    
}
