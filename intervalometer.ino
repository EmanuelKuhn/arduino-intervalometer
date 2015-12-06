unsigned long interval = 1;
long nextPicture = 1000000;



void intervalometer() {
  Serial.println("intervalometer()");
  setInterval(0);

  bool exitApp = false;
  while(!exitApp) {
    readButtons();
    if(buttons[LEFT]) {
      exitApp = true;
    } if(buttons[UP]) {
      interval++;
      cancelInterval();
    } if(buttons[DOWN]) {
      interval--;
      cancelInterval();
    } if(buttons[RIGHT]) {
      setInterval(0);
    }
    
    String menuItems[] = {"", String(interval) + F("sec.     OK"), "", "", ""};
    displayMenu("Set interval:", menuItems, -1);

    checkInterval();
  }
}

void checkInterval() {
  if(millis() >= nextPicture) {
    Serial.println(String(nextPicture) + ";"  + String(millis()));
    SendNikonCode();
    setInterval();
  }
}

void setInterval() {
  nextPicture = millis() + interval * 1000;
}

void setInterval(int interval) {
  nextPicture = millis() + interval;
}

void cancelInterval() {
  nextPicture = millis() + 1000000;
}

