 #include <Servo.h>
Servo servoMain; 

void setup()
{
  Serial.begin(9600);
  servoMain.attach(2); 
}

void loop()
{
  String x; int number;
  
 x=Serial.readStringUntil('\n');
   Serial.println(x);
   
number=x.toInt();

if(number!=0)
{
Serial.println(number);
servoMain.write(number);
}
if(x=="c")
{
  for(int i=0; i<180; i++)
  { 
    Serial.println(i);
servoMain.write(i);
  delay(25);
}
}
if(x=="o")
{
  for(int i=180; i>0; i--)
  { 
    Serial.println(i);
servoMain.write(i);
  delay(25);
}
}

 // servoMain.write(90);  // Turn Servo back to center position (90 degrees)
 // delay(1000);          // Wait 1 second
//noInterrupts();
//while(1) {} 
}
