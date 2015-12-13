unsigned long exposureTime = 1000; //in millisec
unsigned long closeExposure = 0;
void bulbMode() {
  Serial.println("bulbMode()");
  
  int prevButtonFreezeDelay = buttonFreezeDelay;
  buttonFreezeDelay = 200;
  
  bool exitApp = false;
  byte cursor = 0;
  while(!exitApp) {
    readButtons();
    if(buttons[LEFT]) {
      exitApp = true;
    } if(buttons[UP]) {
      if (cursor <= 0) {
        cursor = 2;
      } else {
        cursor --;
      }
    } if(buttons[DOWN]) {
      if (cursor >= 2) {
        cursor = 0;
      } else {
        cursor ++;
      }
    } if(buttons[RIGHT] || buttons[SELECT]) {
      switch(cursor) {
      case(0):
        exposureTime = getSeconds("Exposure time:");
        break;
      case(1): 
        startExposure();
        break;
      case(2):
        closeExposure = 0;
        break;
      }
    }
    
    if (closeExposure - millis() < 172800000) {
      String menuItems[] = {String(exposureTime / 1000) + F(".") + String((exposureTime % 1000)/100) + F("sec"), "Set exposure", "Take Exposure", "Cancel exp.", String((closeExposure - millis()) / 1000) + F(".") + String(((closeExposure - millis()) % 1000)/100) + F("sec")};
      displayMenu("Bulb mode:", menuItems, cursor + 1);
    } else {
      String menuItems[] = {String(exposureTime / 1000) + F(".") + String((exposureTime % 1000)/100) + F("sec"), "Set exposure", "Take Exposure", "Cancel exp.", ""};
      displayMenu("Bulb mode:", menuItems, cursor + 1);
    }
    
  }
  buttonFreezeDelay = prevButtonFreezeDelay;
}

void startExposure() {
  closeExposure = millis() + exposureTime;  
}

void checkExposure() {
  if(millis() >= closeExposure && closeExposure != 0) {
    SendNikonCode();
  }
}
