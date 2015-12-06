#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>;

#include <avr/sleep.h>
#include <avr/power.h>


//Globals:
bool buttons[] = {false, false, false, false, false};
int buttonFreezeDelay = 200;

//button macros:
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3
#define SELECT 4

// Software SPI (slower updates, more flexible pin options):
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

//lcd vars:
byte lcdBacklightPin = 10;

//IR vars:
byte IRledPin = 13;



void setup() {
  voidSetup();
  showSplashScreen();
  // showIntervalometer();



}

byte cursorPos = 0;
bool buttonsFreeze = false;
unsigned long buttonsUnFreeze = 0;
void loop() {
  // put your main code here, to run repeatedly:
  mainMenu();
}


