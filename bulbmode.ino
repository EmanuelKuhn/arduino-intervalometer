unsigned long exposureTime = 3600000;
unsigned long closeExposure = -1;
void bulbMode() {
  Serial.println("bulbMode()");
  int prevButtonFreezeDelay = buttonFreezeDelay;
  buttonFreezeDelay = 80;
  bool exitApp = false;
  while(!exitApp) {
    readButtons();
    if(buttons[LEFT]) {
      exitApp = true;
    } if(buttons[UP]) {
      exposureTime+=100;
      cancelInterval();
    } if(buttons[DOWN]) {
      exposureTime-=100;
      cancelInterval();
    } if(buttons[RIGHT]) {
      startExposure();
    }
    
    String menuItems[] = {"exposure time:", String(exposureTime) + "ms", "Take exposure", "Change exposure", ""};
    displayMenu("Bulb mode:", menuItems, -1);

    checkExposure();
  }
  buttonFreezeDelay = prevButtonFreezeDelay;
}

void startExposure() {
  closeExposure = millis() + exposureTime;  
}

void checkExposure() {
  Serial.println(millis());
  Serial.println(closeExposure);
  display.println("Shutter open for " + String(exposureTime - millis())+ "ms");
  display.display();
  if(millis() >= closeExposure) {
    Serial.println("close exposure");
    SendNikonCode();
  }
}

