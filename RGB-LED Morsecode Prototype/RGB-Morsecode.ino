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

char helloWorld[] = "Hello World";

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
  
  /*
  fadeLed(2000, 250, 2000, 250, red);
  fadeLed(2000, 250, 2000, 250, green);
  fadeLed(2000, 250, 2000, 250, blue);

  fadeLed(2000, 250, 2000, 250, yellow);
  fadeLed(2000, 250, 2000, 250, magenta);
  fadeLed(2000, 250, 2000, 250, cyan);
  */

  /*  //SOS
  dit();
  pauseSymbol();
  dit();
  pauseSymbol();
  dit();

  pauseCharacter();

  dah();
  pauseSymbol();
  dah();
  pauseSymbol();
  dah();

  pauseCharacter();

  dit();
  pauseSymbol();
  dit();
  pauseSymbol();
  dit();
  */

  morse(helloWorld);

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

// Morsecodes
// Symbols:
//    Long   ===  (3 dits = 1 dah)
//    Short  =    (1 dit)
// Pauses:
//    between two symbols           _       (1 dit long)
//    between characters in a word  ___     (3 dits long)
//    between words                 _______ (7 dits long)
//
//  ALPHABET
//
// A  .-          =_===
// B  -...        ===_=_=_=
// C  -.-.
// D  -..
// E  .

// Speeds and lengths
int morseSpeed = 120;   // slow = 240, normal = 120, fast = 60
int dahLength = 3*morseSpeed;
int ditLength = 1*morseSpeed;
// Pauses
int pSymbol = 1*morseSpeed;
int pCharacter = 3*morseSpeed;
int pWord = 7*morseSpeed;

// pause between symbol
void pauseSymbol(){
  fadeLed(0, pSymbol, 0, 0, black);
}

// pause between characters
void pauseCharacter(){
  fadeLed(0, pCharacter, 0, 0, black);
}

// pause between words
void pauseWord(){
  fadeLed(0, pWord, 0, 0, blue);
}

// Dit
void dit(bool hasPauseSymbol = true){
  fadeLed(0, ditLength, 0, 0, red);
  if(hasPauseSymbol){
    pauseSymbol();
  }
}

// Dah
void dah(bool hasPauseSymbol = true){
  fadeLed(0, dahLength, 0, 0, red);
  if(hasPauseSymbol){
    pauseSymbol();
  }
}

// translate character to beep-code
void charToBeep(char character){
  switch (character) {
    case 'a':
      dit();
      dah(false);
      break;
    case 'b':
      dah();
      dit();
      dit();
      dit(false);
      break;
    case 'c':
      dah();
      dit();
      dah();
      dit(false);
      break;
    case 'd':
      dah();
      dit();
      dit(false);
      break;
    case 'e':
      dit(false);
      break;
    case 'f':
      dit();
      dit();
      dah();
      dit(false);
      break;
    case 'g':
      dah();
      dah();
      dit(false);
      break;
    case 'h':
      dit();
      dit();
      dit();
      dit(false);
      break;
    case 'i':
      dit();
      dit(false);
      break;
    case 'j':
      dit();
      dah();
      dah();
      dah(false);
      break;
    case 'k':
      dah();
      dit();
      dah(false);
      break;
    case 'l':
      dit();
      dah();
      dit();
      dit(false);
      break;
    case 'm':
      dah();
      dah(false);
      break;
    case 'n':
      dah();
      dit(false);
      break;
    case 'o':
      dah();
      dah();
      dah(false);
      break;
    case 'p':
      dit();
      dah();
      dah();
      dit(false);
      break;
    case 'q':
      dah();
      dah();
      dit();
      dah(false);
      break;
    case 'r':
      dit();
      dah();
      dit(false);
      break;
    case 's':
      dit();
      dit();
      dit(false);
      break;
    case 't':
      dah(false);
      break;
    case 'u':
      dit();
      dit();
      dah(false);
      break;
    case 'v':
      dit();
      dit();
      dit();
      dah(false);
      break;
    case 'w':
      dit();
      dah();
      dah(false);
      break;
    case 'x':
      dah();
      dit();
      dit();
      dah(false);
      break;
    case 'y':
      dah();
      dit();
      dah();
      dah(false);
      break;
    case 'z':
      dah();
      dah();
      dit();
      dit(false);
      break;
    case '1':
      dit();
      dah();
      dah();
      dah();
      dah(false);
      break;
    case '2':
      dit();
      dit();
      dah();
      dah();
      dah(false);
      break;
    case '3':
      dit();
      dit();
      dit();
      dah();
      dah(false);
      break;
    case '4':
      dit();
      dit();
      dit();
      dit();
      dah(false);
      break;
    case '5':
      dit();
      dit();
      dit();
      dit();
      dit(false);
      break;
    case '6':
      dah();
      dit();
      dit();
      dit();
      dit(false);
      break;
    case '7':
      dah();
      dah();
      dit();
      dit();
      dit(false);
      break;
    case '8':
      dah();
      dah();
      dah();
      dit();
      dit(false);
      break;
    case '9':
      dah();
      dah();
      dah();
      dah();
      dit(false);
      break;
    case '0':
      dah();
      dah();
      dah();
      dah();
      dah(false);
      break;
    default:
      break;
  }
}

// Morse-Code
void morse(char message[]){
  // initiate counter
  int i = 0;

  // loop through char-array
  while(i < strlen(message)){
    // make string lowercase only
    message[i] = tolower(message[i]);
    
    // Make beep-code
    charToBeep(message[i]);

    // check if there is any symbol left
    if(i < strlen(message)-1){
      // if the next symbol is a space, then do a pause between words
      // if next symbol is not a space, then do a pause between characters
      if(isspace(message[i+1])){
        pauseWord();
      } else {
        // dont do a pauseCharacter after a space
        if(isspace(message[i])) {
          // do nothing
          } else {
          pauseCharacter();
        }
      }
    }

    // increment counter
    i++;
  }
}
