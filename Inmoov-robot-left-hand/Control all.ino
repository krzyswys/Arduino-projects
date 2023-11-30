#include <Servo.h>
Servo P1; // Define our Servo
Servo P2;
Servo P3;
Servo P4;
Servo P5;
Servo w1;

int clos = 180; //Max close: 180 deg
int ope = 0; //Max open: 0 deg
void setup()
{
  Serial.begin(9600);
  P1.attach(2); //thumb
  P2.attach(3);
  P3.attach(4);
  P4.attach(5);
  P5.attach(6);
  w1.attach(7); //wrist

}

void loop()
{
  String recivedData; int convertedData;
  if (Serial.available())
  {
    recivedData = Serial.readStringUntil('\n'); //reads data from serial com port until enter
    Serial.println(recivedData); //writes recived data to serial port

    convertedData = recivedData.toInt(); //converts recived data via comport to int type of data

    if (convertedData != 0)            //if converted data is diffrent than none the do stuff
    {
      Serial.println(convertedData);
      P1.write(convertedData);
      P2.write(convertedData);
      P3.write(convertedData);
      P4.write(convertedData);
      P5.write(convertedData); 
     // w1.write(convertedData);
    }
    else if (recivedData == "c") //close
    {
      closee();
    }
    else if (recivedData == "o") //open
    {
      opene();
    }
    else if (recivedData == "w") //wave
    {
      wave();
    }
    else if (recivedData == "f") //wave
    {
      fuck();
    }
    else if (recivedData == "v") //wave
    {
      victory();
    }
     else if (recivedData == "q") //closewrist
    {
      closewrist();
    }
     else if (recivedData == "ow") //open wrist
    {
      openwrist();
    }
    else if (recivedData == "a") //wave
    {
      animations();
    }
    else
    {
      Serial.println("No match for such request");
    }

  }
}

void opene()
{
  for (int i = clos; i > ope; i--)
  {
    Serial.println(i);
    P1.write(i);
    P2.write(i);
    P3.write(i);
    P4.write(i);
    P5.write(i);
    delay(25);
  }
}

void closee()
{
  for (int i = ope; i < clos; i++)
  {
    Serial.println(i);
    P1.write(i);
    P2.write(i);
    P3.write(i);
    P4.write(i);
    P5.write(i);
    delay(25);
  }
}

void wave()  //wave hand
{
  //int servoPosition;
 // servoPosition= P1.read(); //check posioton on thumb
closee();
  for (int i = clos; i > ope; i--) //open
  {
    P1.write(i);
    P2.write(i);
    P3.write(i);
    P4.write(i);
    P5.write(i);
    delay(5);
  }
  for (int i = ope; i < clos; i++)
  {
    P1.write(i);
    P2.write(i);
    P3.write(i);
    P4.write(i);
    P5.write(i);
    delay(5);
  }
}

void victory() //victory sym
{
  P1.write(clos);
  P2.write(ope);
  P3.write(ope);
  P4.write(clos);
  P5.write(clos);
}

void fuck() //fuck sym
{
  P1.write(ope);
  P2.write(clos);
  P3.write(ope);
  P4.write(clos);
  P5.write(clos);
}


void animations() //all animations 
{
opene();
delay(2000);
closee();
  delay(2000);
  fuck();
  delay(2000);
  victory();
  delay(2000);
  opene();
  delay(2000);
  closewrist();
  delay(500);
  openwrist();
  
}
void closewrist()
{
  for (int i = 0; i < 160; i++) //close wrist
  {
    w1.write(i);
    delay(5);
  }
}
void openwrist()
{
  for (int i = 160; i > 1; i--) //open wrist
  {
    w1.write(i);
    delay(5);
  }
}
