// the pin for the active buzzer
#define BUZZER_PIN 12
#define POTI_PIN A0
#define ON_BUTTON 4
#define OFF_BUTTON 2

// Spacing and legth of the signals 
// Symbols:
//    Long   ===    aka   -   (1 dah = 3 dits)
//    Short  =      aka   .   (1 dit)
// Pauses:
//    between two symbols           _       (1 dit long)
//    between characters in a word  ___     (3 dits long)
//    between words                 _______ (7 dits long)

// declaring and initializing a structure to hold the character and corresponding morsecode
static const struct {const char character, *code;} morsechart[] = {
  // Pause
  // will be interpreted to "pause after word" in charToBeep()
  {" ", ""},
  
  // Letters
  {'A', ".-"},
  {'B', "-..."},
  {'C', "-.-."},
  {'D', "-.."},
  {'E', "."},
  {'F', "..-."},
  {'G', "--."},
  {'H', "...."},
  {'I', ".."},
  {'J', ".---"},
  {'K', "-.-"},
  {'L', ".-.."},
  {'M', "--"},
  {'N', "-."},
  {'O', "---"},
  {'P', ".--."},
  {'Q', "--.-"},
  {'R', ".-."},
  {'S', "..."},
  {'T', "-"},
  {'U', "..-"},
  {'V', "...-"},
  {'W', ".--"},
  {'X', "-..-"},
  {'Y', "-.--"},
  {'Z', "--.."},

  // Numerals
  {'1', ".----"},
  {'2', "..---"},
  {'3', "...--"},
  {'4', "....-"},
  {'5', "....."},
  {'6', "-...."},
  {'7', "--..."},
  {'8', "---.."},
  {'9', "----."},
  {'0', "-----"},

  // Special Characters & symbols
  {'.', ".-.-.-"},
  {',', "--..--"},
  {':', "---..."},
  {';', "-.-.-."},
  {'?', "..--.."},
  {'-', "-....-"},
  {'_', "..--.-"},
  {'(', "-.--."},
  {')', "-.--.-"},
  //{''', ".----."},
  {'=', "-...-"},
  {'+', ".-.-."},
  {'/', "-..-"},
  {'@', ".--.-."},

  // Signals (not used, because unable to parse)
  //{'KA', "-.-.-"},          // Start of Sequence
  //{'BT', "-...-"},          // Pause
  //{'AR', ".-.-."},          // End of Sequence
  //{'VE', "...-."},          // Aknowledged
  //{'SK', "...-.-"},         // End of Communication    
  //{'SOS', "...---..."},     // SOS
  //{'HH', "........"},       // Repeat from last Word

};

// Global variables

unsigned short int
// Speeds and lengths
    morseSpeed, // slow = 240, normal = 120, fast = 60
    dahLength,  // = 3 * morseSpeed
    ditLength,  // = 1 * morseSpeed

// Pauses
    pSymbol,    // = 1 * morseSpeed
    pCharacter, // = 3 * morseSpeed
    pWord;      // = 7 * morseSpeed

// The message to encode into morsecode
  char message[] = "Paris";

// Setup
void setup() {
  // declare BUZZER_PIN as OUTPUT
  pinMode(BUZZER_PIN, OUTPUT);

  /*// serial output for debugging
  Serial.begin(9600);
  Serial.println(sizeof morsechart);
  Serial.println(sizeof morsechart[0]);
  Serial.println(sizeof morsechart[1]);
  Serial.println(sizeof *morsechart);

  // */
}

// Loop
void loop() {

  // Set Speed to new value
  updateSpeed();
  
  // morse message
  morse(message);

  // Exit loop
  exit(0);
}

// set new speed
void updateSpeed()
{
  // read potentiometer for morse speed
  morseSpeed = analogRead(POTI_PIN);
  
  // Seraial output for debug
  //Serial.println(morseSpeed);
  
  // Speeds and lengths
  dahLength = 3 * morseSpeed;
  ditLength = 1 * morseSpeed;

  // Pauses
  pSymbol = 1 * morseSpeed;
  pCharacter = 3 * morseSpeed;
  pWord = 7 * morseSpeed;
}

// make beep
void beep(unsigned short int *duration){
  digitalWrite(BUZZER_PIN, HIGH);
  delay(*duration);
  digitalWrite(BUZZER_PIN, LOW);
}

// make pause
void pause(unsigned short int *duration){
  delay(*duration);
}

// morse the message
void morse(char *message)
{
  // initiate counter to loop through the message[]
  unsigned short int i = 0;

  // check if not end of message
  while(i < strlen(message))
  {
    // make string uppercase, to match character in the morsechart
    message[i] = toupper(message[i]);

    // loop through struct
    // Note: sizeof the whole struct is 150, whereas a single entry yields 3 Bytes
    for( unsigned short int k = 0; k < sizeof morsechart / sizeof *morsechart; ++k)
    {
      // Find the current character
      if( message[i] == morsechart[k].character )
      {
        unsigned short int j = 0;
        // Make beep-code for the current character
        while(j < strlen(morsechart[k].code))
        {
          // get the dit() or dah() at the position j of the character i
          switch (morsechart[k].code[j])
          {
            case '.':
              //Serial.print("=");
              beep(&ditLength);
              break;
            case '-':
              //Serial.print("===");
              beep(&dahLength);
              break;
          }
          
          // go to next dit() or dah()
          j++;

          // make a pause between symbols if there are any symbols left
          if (j < strlen(morsechart[k].code))
          {
            //Serial.print("_");
            pause(&pSymbol);
          }
        }
      }
    }
    
    // check if there is any symbol left in message
    if(i < strlen(message)-1)
    {
      // if the next symbol is a space, then make a pause between words
      if(isspace(message[i+1]))
      {
        //Serial.print("_______");
        pause(&pWord);
      }
      // else make a pause between characters
      else 
      {
        // dont do a pauseCharacter after a space
        if(isspace(message[i]))
        {
          // do nothing
        }
        else
        {
          //Serial.print("___");
          pause(&pCharacter);
        }
      }
    }
  // increment counter
  i++;
  }
}
