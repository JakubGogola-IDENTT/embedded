#define LED 13

volatile String serialInput;
volatile int delayTime;
volatile int unit;
volatile int dotTime;
volatile int dashTime;
volatile int spaceSymbols;
volatile int spaceLetters;
volatile int spaceWord;


void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  unit = 100;
  
  dotTime = unit;
  dashTime = 3 * unit;
  spaceSymbols = unit;
  spaceLetters = 3 * unit;
  spaceWord = 7 * unit;
}

void loop() {
  while (Serial.available())
  {
    serialInput = Serial.readString();
    for(int i = 0; i < serialInput.length(); i++) {
      Serial.write(serialInput.charAt(i));
      if(serialInput.charAt(i) != ' ') {
        print(serialInput.charAt(i));
        delay(spaceLetters);
      } else {
        delay(spaceWord);
      }
    }
  }
}


void doTheBlinking(int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED, HIGH);
    delay(delayTime);
    digitalWrite(LED, LOW);
    delay(delayTime);
  } 
}

void print(char c) {
  switch(c) {
   case'a':
      // DOT
      dot();
      // DASH
      dash();
      break;
      
    case'b':
      // DASH
      dash();
      // DOT
      dot();
      // DOT
      dot();
      // DOT
      dot();
      break;
      
    case 'c':
       // DASH
      dash();
      // DOT
      dot();
       // DASH
      dash();
      // DOT
      dot();
      break;
      
    c ase 'd':
      // DASH
      dash();
      // DOT
      dot();
      // DOT
      dot();
      break;
      
    case 'e':
      // DOT
      dot();
      break;
  }
}

void dash() { 
  // DASH
  digitalWrite(LED, HIGH);
  delay(dashTime);
  digitalWrite(LED, LOW);
  delay(spaceSymbols);
}

void dot() {
  // DOT
  digitalWrite(LED, HIGH);
  delay(dotTime);
  digitalWrite(LED, LOW);
  delay(spaceSymbols);
}
