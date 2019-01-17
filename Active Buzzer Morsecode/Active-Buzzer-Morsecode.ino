// the pin for the active buzzer
#define BUZZER_PIN 12

// Global variables

// Speeds and lengths
int morseSpeed = 120;   // slow = 240, normal = 120, fast = 60
int dahLength = 3*morseSpeed;
int ditLength = 1*morseSpeed;

// Pauses
int pSymbol = 1*morseSpeed;
int pCharacter = 3*morseSpeed;
int pWord = 7*morseSpeed;

// The message to encode into morsecode
char message[] = "Ich liebe Dich";

// Setup
void setup() {
  // declare BUZZER_PIN as OUTPUT
  pinMode(BUZZER_PIN, OUTPUT);
}

// Loop
void loop() {
  // morse message
  morse(message);

  // Exit loop
  exit(0);
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

// make beep
void beep(int duration){
  digitalWrite(BUZZER_PIN, HIGH);
  delay(duration);
  digitalWrite(BUZZER_PIN, LOW);
}

// pause between symbol
void pauseSymbol(){
  delay(pSymbol);
}

// pause between characters
void pauseCharacter(){
  delay(pCharacter);
}

// pause between words
void pauseWord(){
  delay(pWord);
}

// Dit
void dit(bool hasPauseSymbol = true){
  beep(ditLength);
  if(hasPauseSymbol){
    pauseSymbol();
  }
}

// Dah
void dah(bool hasPauseSymbol = true){
  beep(dahLength);
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
