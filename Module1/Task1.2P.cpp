// C++ code
//
int baselineTemp = 0;

int celsius = 0;

bool LEDState = false;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(A0), change, CHANGE);
}

void loop()
{
 
  
  delay(1000); // Wait for 1 second
}
void change()
{
  LEDState = !LEDState;
  digitalWrite(A0, LEDState);
  // set threshold temp
  baselineTemp = 30;
  // measure temp
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
 
  if (celsius < baselineTemp)
  {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    Serial.println(celsius);
  }
  if (celsius >= baselineTemp && celsius < baselineTemp + 20) 
  {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    Serial.println(celsius);
  }
  
  if (celsius >= baselineTemp + 20 && celsius < baselineTemp + 40)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    Serial.println(celsius);
  }
}                  
                  
                  
 
                