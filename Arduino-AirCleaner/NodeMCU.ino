#define BLYNK_PRINT Serial
#include<SoftwareSerial.h> 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<stdlib.h>
int x=0;
SoftwareSerial s(3,1);

char auth[] = "wHpLrm_YSfZsDSNzXY3RaWJC-ii0TvLI";
char ssid[] = "TP-LINK_10AC";
char pass[] = "10456217";

void setup()
{
   Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}
BLYNK_CONNECTED()
{
  Blynk.syncVirtual(V1);//calosc
  Blynk.syncVirtual(V2);//wiatrak1
  Blynk.syncVirtual(V3);//wiatrak2
  Blynk.syncVirtual(V4);//predkosc wiatrakow
  Blynk.syncVirtual(V5);//ledy
  Blynk.syncVirtual(V6);// jasnosc ledy
  Blynk.syncVirtual(V7);//ZeRGBa
}
BLYNK_WRITE(V1)
{
   int buttonState=param.asInt();
    if (buttonState == 1)
 {
  Blynk.virtualWrite(V2, 1);
  Blynk.virtualWrite(V3, 1);
  Blynk.virtualWrite(V5, 1);
     Serial.println(1);
     Serial.println("");
 }
  else if (buttonState == 0)
  {
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V3, 0);
    Blynk.virtualWrite(V4, 55);
    Blynk.virtualWrite(V5, 0);
    Blynk.virtualWrite(V6, 315);
     Serial.println(2);
     Serial.println("");
  } 
}
BLYNK_WRITE(V2)
{
   int buttonState=param.asInt();
    if (buttonState == 1)
 {
     Serial.println(3);
     Serial.println("");
 }
  else if (buttonState == 0)
  {
     Serial.println(4);
     Serial.println("");
  } 
}
BLYNK_WRITE(V3)
{
    int buttonState=param.asInt();
    if (buttonState == 1)
 {
     Serial.println(5);
     Serial.println("");
 }
  else if (buttonState == 0)
  {
     Serial.println(6);
     Serial.println("");
  } 
}
BLYNK_WRITE(V4) //narazie nie działa bo nie ma pmw w wiatrakach
{
    int buttonState=param.asInt();
     Serial.println(buttonState);
     Serial.println("");
}
BLYNK_WRITE(V5)
{
    int buttonState=param.asInt();
    if (buttonState == 1)
 {
     Serial.println(7);
     Serial.println("");
 }
  else if (buttonState == 0)
  {
     Serial.println(8);
     Serial.println("");
  } 
}
BLYNK_WRITE(V6)
{
    int buttonState=param.asInt();
     Serial.println(buttonState);
     Serial.println("");
}
BLYNK_WRITE(V7) 
{
    int r = param[0].asInt();
        Serial.println(r);
        Serial.println("");
    int g = param[1].asInt();
        Serial.println(g);
        Serial.println("");
    int b = param[2].asInt();
        Serial.println(b);
        Serial.println("");    
}
void loop() {  
  if(x==0)
  {
    Blynk.virtualWrite(V1, 0);
    Blynk.virtualWrite(V2, 0);
    Blynk.virtualWrite(V3, 0);
    Blynk.virtualWrite(V4, 55);
    Blynk.virtualWrite(V5, 0);
    Blynk.virtualWrite(V6, 315);
     Serial.println(8);
     Serial.println("");
    x++;
  }
  
    Blynk.run();
}
