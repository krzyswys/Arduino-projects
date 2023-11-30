int R; int G; int B;  int x = 0; //ten x to jeak nie będzie dobrze działało LedON
String inString = "";
#include <Adafruit_NeoPixel.h>
#include <NeoSWSerial.h>
#define LED_PIN    2
#define LED_COUNT 15
//brak funkcji do regulacjo prędkości obrotów
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
  
  pinMode(3, OUTPUT); // Sygnał PWM silnika nr 1
  pinMode(4, OUTPUT); // Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT); // Sygnał PWM silnika nr 1
  pinMode(7, OUTPUT); // Sygnały sterujące kierunkiem obrotów silnika nr 1
  pinMode(8, OUTPUT);
}

void loop()
{ int data = 0; int Brightness; //String stringOne  = Serial.readString();       Serial.print("Orygnalna data: ");   Serial.println(data);

                    int inChar = Serial.read();
                    if (isDigit(inChar))
                    {
                      inString += (char)inChar; // convert the incoming byte to a char and add it to the string:
                    }
                    if (inChar == '\n')     // if you get a newline, print the string, then the string's value:
                    {
                      data = inString.toInt();
                      inString = ""; // clear the string for new input:
                    }

  if (data == 1) //wlacza calosc
  {
    AllOn1(data);
  }
  if (data == 2) //wylacza calosc
  {
    AllOff2();
  }
   if (data == 3) //wlacza wiatrak 1
  {
    Fan1On3();
  }
  if (data == 4) //wylacza wiatrak 1
  {
    Fan1Off4();
  }
    if (data == 5) //wlacza wiatrak 2
  {
    Fan2On5();
  }
  if (data == 6) //wylacza wiatrak 3
  {
    Fan2Off6();
  }
 if (data > 55 && data < 317) //zmiena predkosc wiatrakow ale nie dziala bo brak pmw
  {
    int speedo = data - 55;
   //szybkosc wiatrak(speedo);
  }
  if (data == 7) //wlacza ledy
  {
    LedyOn7(data);
  }
  if (data == 8) //wylacza ledy
  {
    LedyOff8();
  }

 if (data > 315 && data < 570) //zmiena jasnosc
  {

    int y = data - 315;
    Brightness=y;
    LedBrightness(Brightness);
  }

   if (data >= 575 && data <= 1350) //zamaina kolorystyki
  {
    if (data >= 575 && data <= 830)
    {
      R = data - 575; //Nadaje wartość czerwonemu
    }
    else if (data >= 835 && data <= 1090)
    {
      G = data - 835; //Nadaje wartość zielonemu
    }
    else  if (data >= 1095 && data <= 1350)
    {
      B = data - 1095; //Nadaje wartość niebieskiemu
    }
    LedRainbow(R, G, B, Brightness);
  }
 // delay(1000);
}
void AllOn1(int datta)
{
  LedyOn7(datta);
  Fan1On3();
  Fan2On5();
}
void AllOff2()
{
  LedyOff8();
  Fan1Off4();
  Fan2Off6();
  x=0;
}
void inicjacja(int wait)          //poczatek wlacznia ledow
{
  strip.clear();
  uint32_t black = strip.Color(0, 0, 0);
  uint32_t red = strip.Color(255, 0, 0);
  uint32_t blue = strip.Color(0, 0, 255);
  uint32_t white = strip.Color(115, 115, 115);
  strip.setBrightness(25);
  for (int i = 0; i <= 15; i++)
  {
    strip.setPixelColor(i, red);// ustawia kolorek na czewony i wyswietla po kolei
    strip.show(); //przekazuje programowi żeby wyświetlił
    delay(wait + 50);
  }
  strip.fill(blue, 0, 15); // wejscie w niebieski kolor i
  delay(67);
  for (int i = 0; i <= 15; i++)
  {
    strip.setBrightness(15 + i * 7); // rozjaśnienie
    strip.show();
  }
  delay(90);
  strip.fill(black, 0, 15); //pierwsze mrugnięcie
  delay(100);
  strip.show();
  strip.fill(blue, 0, 15); //drugi raz niebieski
  delay(100);
  strip.show();
  strip.fill(black, 0, 15); //drugie mrugnięcie
  delay(100);
  strip.show();
  strip.fill(blue, 0, 15); //trzeci raz niebieski
  delay(100);
  strip.show();
  strip.fill(black, 0, 15); //mrugniecie ostatnie
  delay(100);
  strip.show();
  strip.fill(white, 0, 15); //przejście w biały
  strip.show();
  for (int i = 225; i >= 175; i--)
  {
    strip.setBrightness(i - 25); //zejście z jasnościa w dół
    strip.show();
    delay(10);
    // strip.show();
  }
  x = 1;
  strip.setBrightness(85);
  strip.fill(white, 0, 15);
  strip.show();
}
void bialyKoniec()       //Biale zakonczenie ledow
{
  strip.setBrightness(85);
  uint32_t white = strip.Color(115, 115, 115);
  strip.fill(white, 0, 15);
  strip.show();
}
void Fan1On3()
{
  analogWrite(3, 255); //Maksymalna prędkość obrotów 
   digitalWrite(4, HIGH); //Silnik nr 1 - obroty w lewo
  digitalWrite(5, LOW);
}
void Fan1Off4()
{
 digitalWrite(4, LOW); //Silnik nr 1 - stop
 digitalWrite(5, LOW);  
}
void Fan2On5()
{
  analogWrite(6, 255); //Maksymalna prędkość obrotów 
   digitalWrite(7, HIGH); //Silnik nr 2 - obroty w lewo
  digitalWrite(8, LOW);
}
void Fan2Off6()
{
 digitalWrite(7, LOW); //Silnik nr 2 - stop
 digitalWrite(8, LOW);  
}
void LedyOn7(int datta)            //Wlacza ledy
{
  if (x == 1 || datta==7)
  {
    bialyKoniec();
  }
  if (x != 1&&datta==1)
  {
    inicjacja(120);
  }
}
void LedyOff8()             //Wylacza LEDy
{
  //uint32_t black = strip.Color(0, 0, 0);
  strip.setBrightness(0);
  strip.show();
}
void LedBrightness(int Brightness)        //Reguluje jasnosc ledow
{
  strip.setBrightness(Brightness);
  strip.show();
}
void LedRainbow(int r, int g, int b, int Brightness)    //Zarzadza kolorami
{
  uint32_t ZeRGBa = strip.Color(r, g, b);
  strip.setBrightness(Brightness);
  strip.fill(ZeRGBa, 0, Brightness);
  strip.show();
}
