#include <SoftwareSerial.h>

SoftwareSerial mySerial(11,10); // RX, TX
void setup() 
{
  Serial.begin(9600);  
  mySerial.begin(9600); 
  pinMode(6, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(13, OUTPUT); 
  pinMode(12, OUTPUT); 
  digitalWrite(4, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);  
       
  Serial.println("Board is connected!!");   
}
char variable;
void loop()
{
         
    if (mySerial.available()){
      char temp = mySerial.read();
      if(temp>0)
      variable=temp;
      Serial.println(variable);
      switch (variable){
        case 'a':
          digitalWrite(6, HIGH);
          digitalWrite(5, HIGH);
          digitalWrite(3, HIGH);
          break;
        case 'b':
          digitalWrite(3, HIGH);
          break;
        case 'c':
          digitalWrite(5, HIGH);
          break;
        case 'd':
          digitalWrite(6, HIGH);
          break;
        case 'e':
          digitalWrite(6, LOW);
          digitalWrite(5, LOW);
          digitalWrite(3, LOW);
          break;
        case 'f':
          digitalWrite(3, LOW);
          break;
        case 'g':
          digitalWrite(5, LOW);
          break;
        case 'h':
          digitalWrite(6, LOW);
          break;
      }
    }

    if (Serial.available())
      mySerial.write(Serial.read());

delay(500);
}