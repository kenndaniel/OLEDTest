#include "OLED.h"

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Wire.begin();

  OLEDinit();

  OLEDmsg("Message on line 1"); // Defaults to line 1

  String test = "Replace message line1";

  delay(5000);
  OLEDmsg(test, 1);

  test = "Message on line2";

  delay(2000);
  OLEDmsg(test, 2);

  OLEDerrorMsg("Error message", 2);

  test = "Info message line 2";

  delay(5000);
  OLEDmsg(test, 2);

    test = "Info message line 3";

  delay(5000);
  OLEDmsg(test, 3);

  test = "This is a long message that will wrap";
  delay(5000);
  OLEDmsgMultiLine(test,2);
  delay(5000);
  void OLEDclearAll();
}

void loop()
{
}
