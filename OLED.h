
#include "Wire.h"

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h> //for progress bar

// adafruit oled stuff:
//  4 lines by 21 characters
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 32    // OLED display height, in pixels
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
bool OLEDnotWorking = false;

void OLEDclearAll()
{
  if (OLEDnotWorking)
    return;
  display.fillRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SSD1306_BLACK); // fill the screen with black
  display.display();
}

void OLEDclearLine(int line)
{ // There are 4 lines numbered 1-4
  if (OLEDnotWorking)
    return;
  int lin = line - 1;
  display.fillRect(0, 10 * lin, SCREEN_WIDTH, 11, SSD1306_BLACK); // Overwrite the line at y = 10*line, height = 8
  display.display();
}

void OLEDmsg(String msg)
{ // Writes a message on line 1
  if (OLEDnotWorking)
    return;
  OLEDclearLine(1);
  display.setCursor(0, 0);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.display();
  String message = msg.substring(0, 21);
  display.print(message);
  display.display();
}

void OLEDmsg(String msg, int line)
{ // Writes a message on line specified by the argument
  // That line will be cleared
  // The message is limited to 21 characters (full line)
  if (OLEDnotWorking)
    return;
  OLEDclearLine(line);
  int lin = line - 1;
  display.setCursor(0, lin * 12);

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.display();
  String message = msg.substring(0, 21);
  display.print(message);
  display.display();
}

void OLEDerrorMsg(String msg, int line)
{ // Writes an error message on line specified by the argument
  // That line will be cleared and changed to white background
  // The message is limited to 21 characters (full line)
  if (OLEDnotWorking)
    return;
  int lin = line - 1;
  display.fillRect(0, 10 * lin, SCREEN_WIDTH, 10, SSD1306_WHITE); // Overwrite the line at y = 10*line, height = 8
  display.display();
  display.setCursor(0, lin * 12);

  display.setTextSize(1);
  display.setTextColor(SSD1306_BLACK);
  display.display();
  String message = msg.substring(0, 21);
  display.print(message);
  display.display();
}

void OLEDmsgMultiLine(String msg, int startLine)
{ // Writes a multiline message starting at line 1
  // The message automatically wraps to the next line
  // The bottom line does not wrap to the top.
  if (OLEDnotWorking)
    return;
  int numLines = msg.length() / 21;
  int remainder = msg.length() - numLines * 21;
  if (remainder > 0)
    numLines++;
  for (int i = startLine; i < startLine + numLines; i++)
  {
    OLEDclearLine(i);
    int iChar = i-startLine;
    OLEDmsg(msg.substring(iChar*21,(iChar+1)*21),i);
  }
}

void OLEDinit()
{
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("OLED not available or not working"));
    OLEDnotWorking = true;
  }
  OLEDclearAll();
}
