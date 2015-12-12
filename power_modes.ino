void powerMode(byte mode) {
  //because the 3.3v regulator only goes down to 3.8v when the backlight is off, we need to change the contrast
  switch(mode) {
    case 0:
      Serial.println("powerMode: 0");
      analogWrite(lcdBacklightPin, 0);
      display.setContrast(45);
      break;
    case 1:
      Serial.println("powerMode: 1");
      analogWrite(lcdBacklightPin, 190);
      display.setContrast(10);
      break;
    case 2:
      Serial.println("powerMode: 2");
      digitalWrite(lcdBacklightPin, 255);
      display.setContrast(10);
      break;
  }
}

