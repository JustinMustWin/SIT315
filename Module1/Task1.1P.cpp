// C++ code
//
int baselineTemp = 0;

int celsius = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  // set threshold temp
  baselineTemp = 30;
  // measure temp
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.println(celsius);
  if (celsius < baselineTemp)
  {
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
   
  }
  if (celsius >= baselineTemp && celsius < baselineTemp + 20) 
  {
    digitalWrite(4, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    
  }
  
  if (celsius >= baselineTemp + 20 && celsius < baselineTemp + 40)
  {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
   
  }
  
  delay(1000); // Wait for 1 second
}