unsigned long interval = 1000; //interval in millisec
long nextPicture = 0; //millis() at which the next photo is to be taken

void intervalometer() {
  Serial.println("intervalometer()");
  bool exitApp = false;
  setInterval(0);

  interval = getSeconds(F("Set interval:"));
  if (interval == 0) {
    exitApp = true;
  }
  
  while(!exitApp) {
    readButtons();
    if(buttons[LEFT]) {
      exitApp = true;
      cancelInterval();
    } if(buttons[UP]) {
      interval = getSeconds(F("Set interval:"));
      setInterval(interval);
    } if(buttons[DOWN]) {
      interval = getSeconds(F("Set interval:"));
      setInterval(interval);
    } if(buttons[RIGHT]) {
      interval = getSeconds(F("Set interval:"));
      setInterval(interval);
    }

    display.clearDisplay();
    String menuItems[] = {String(interval / 1000) + F(".") + String((interval % 1000)/100) + F("sec"), "", F("Next picture:"), String((nextPicture - millis()) / 1000) + F(".") + String(((nextPicture - millis()) % 1000)/100) + F("sec"), ""};
    displayMenu("Intervalometer", menuItems, -1);

    checkInterval();
  }
}

void checkInterval() {
  if(millis() >= nextPicture && nextPicture != 0) {
    SendNikonCode();
    setInterval();
  }
}

void setInterval() {
  nextPicture = millis() + interval;
}

void setInterval(int interval) {
  nextPicture = millis() + interval;
}

void cancelInterval() {
  nextPicture = 0;
}

