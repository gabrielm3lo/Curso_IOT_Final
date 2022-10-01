void setup()
{
  pinMode(A5, INPUT);
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A3, INPUT);
}

void loop()
{
  Serial.println(analogRead(A5));
  if (analogRead(A5) > 750) {
    Serial.println("claro");
    digitalWrite(3, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
  } else {
    if (analogRead(A3) > 500 || analogRead(A3) < 750) {
      Serial.println("Meia luz");
      digitalWrite(3, HIGH);
      digitalWrite(5, LOW);
      digitalWrite(4, LOW);
    } else {
      Serial.println("Escuro");
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
    }
  }
  delay(1000); // Wait for 1000 millisecond(s)
}