#define EnA 7
#define In1 6
#define In2 5
#define In3 4
#define In4 3
#define EnB 2


void setup() {
  // put your setup code here, to run once:
  pinMode(EnA, OUTPUT);
  pinMode(In1, OUTPUT);
  pinMode(In2, OUTPUT);
  pinMode(EnB, OUTPUT);
  pinMode(In3, OUTPUT);
  pinMode(In4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(7, 100);
  digitalWrite(EnA, HIGH);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  digitalWrite(EnB, HIGH);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
  analogWrite(2, 500);
}
