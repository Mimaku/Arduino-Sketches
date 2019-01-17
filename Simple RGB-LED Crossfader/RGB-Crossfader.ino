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

// previous color-values necessary to crossfade from one color to another
byte prevRedValue;
byte prevGreenValue;
byte prevBlueValue;

// delayTime in for-loops
int delayTime = 10;

// Setup
void setup() {
  // declare pins for RGB-LED
  pinMode(REDPIN, OUTPUT); // RED LED
  pinMode(GREENPIN, OUTPUT); // GREEN LED
  pinMode(BLUEPIN, OUTPUT); // BLUE LED

  // serial output for debugging
  //Serial.begin(9600);
}

// Loop
void loop() {
  // since the initial "color" is black, the crossfade will
  // - fade in the first loop from black to red
  // - fade then from last color in loop to red
  crossfadeLed(500, 1000, red);

  // since the current color is now red, the crossfade will fade from red to green
  crossfadeLed(500, 1000, green);

  // since the current color is now green, the crossfade will fade from green to blue
  crossfadeLed(500, 1000, blue);

  // etc...
  crossfadeLed(500, 1000, yellow);
  crossfadeLed(500, 1000, magenta);
  crossfadeLed(500, 1000, cyan);
  
  crossfadeLed(500, 1000, white);
}

// crossfade function
// with variable crossfade-time to the specified color
// with variable on-time for the specified color

void crossfadeLed(int crossfadeTime, int onTime, byte color[3]){
  // save the color values for the color we come from
  prevRedValue = redValue;
  prevGreenValue = greenValue;
  prevBlueValue = blueValue;
  
  // crossfade phase
  int fadeInDelay = crossfadeTime / 255;
  for (byte i = 0; i < 255; i++) {
    // set pin to PWM-Level for the specific color
    analogWrite(REDPIN, redValue);
    analogWrite(GREENPIN, greenValue);
    analogWrite(BLUEPIN, blueValue);

    // increment or decremt PWM-Level to match the specified color

    // red color channel
    if(prevRedValue < color[0]) {
      redValue += 1;
    }
    else if(prevRedValue > color[0]){
      redValue -= 1;
    }

    // green color channel
    if(prevGreenValue < color[1]) {
      greenValue += 1;
    }
    else if(prevGreenValue > color[1]){
      greenValue -= 1;
    }

    // blue color channel
    if(prevBlueValue < color[2]) {
      blueValue += 1;
    }
    else if(prevBlueValue > color[2]){
      blueValue -= 1;
    }
    
    delay(fadeInDelay);
  }

  delay(onTime);
}
