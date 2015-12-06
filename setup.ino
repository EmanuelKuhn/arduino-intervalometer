
void voidSetup() {
  
  
  pinMode(IRledPin, OUTPUT);      
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(F("setup()"));
  display.begin();
 // display.clearDisplay();   // no adafruit logo
  // init done

  //lcd backlight
  pinMode(lcdBacklightPin, OUTPUT);
  digitalWrite(lcdBacklightPin, LOW);
  powerMode(0);

  Serial.println(String("2147483649").toInt());
}

void showSplashScreen() {
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.setTextSize(2);
  display.println("Nikon  Intervalometer");
  display.display();
  delay(1000);
  display.clearDisplay();
}

void showIntervalometer() {
  display.setTextSize(1);
  display.println("Set interval:");
  display.setTextColor(BLACK);
  display.println("");
  display.println("001.000sec");
  display.display();
}

