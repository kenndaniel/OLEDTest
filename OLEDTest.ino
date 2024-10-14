#include "OLED.h"

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Wire.begin();
  String test;
  OLEDinit();

  OLEDmsg("Message on line 1 "); // Defaults to line 1

  test = "Replace message line1";

  delay(2000);
  OLEDmsg(test);

  test = "Info message line 2";

  delay(2000);
  OLEDmsg(test, 2);

    test = "Info message line 3";

  delay(2000);
  OLEDmsg(test, 3);

  test = "Info message line 4";
  
  delay(2000);
  
  OLEDmsg(test, 4);
  delay(2000);
    OLEDerrorMsg("Error message", 2);

  test = "This is a long message that will wrap";
  delay(3000);
  OLEDmsgMultiLine(test,2);
  delay(3000);
  OLEDclearAll();

  OLEDrotate("Message 0",INFO);
  delay(1000);
  OLEDrotate("Message 1",INFO);
  delay(1000);
  OLEDrotate("Error 2",ERROR);
  delay(1000);
  OLEDrotate("Message 3",INFO);
  delay(1000);
  OLEDrotate("Message 4",INFO);
  delay(1000);
    OLEDrotate("Message 5",INFO);
  delay(1000);
    OLEDrotate("Message 6",INFO);
  delay(1000);
  for( int i = 5; i>=0; i--)
   { OLEDmsg(String(i), bottomLine);
    delay(1000);}
  
  OLEDrotate("Lift Off ",ERROR);
  delay(3000);
  OLEDrotate("The End",INFO);
  delay(3000);

}

void loop()
{
}
