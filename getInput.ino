//Globals because I don't know how to pass objects to methods in c++
  
  byte getInputDigit[] = {0, 0, 0, 0, 0}; //0000.0 s
  byte getInputDigits;
  

unsigned long getSeconds(String menuTitle) {
  Serial.println("getInput::getMilliSeconds");
  
  bool exitApp = false;
  byte cursor = 0;

  unsigned long seconds;
  unsigned long totalMilliseconds = 0;
  
  while(!exitApp) {
    readButtons();
    if(buttons[LEFT]) {
      if (cursor <= 0) {
        cursor = 4;
      } else {
        cursor --;
      }
    } if(buttons[UP]) {
      if (getInputDigit[cursor] >= 9) {
        getInputDigit[cursor] = 0;
      } else {
        getInputDigit[cursor] ++;
      }
      
    } if(buttons[DOWN]) {
      if (getInputDigit[cursor] >= 1) {
        getInputDigit[cursor] --;
      }
    } if(buttons[RIGHT]) {
      if (cursor >= 4) {
        cursor = 0;
      } else {
        cursor ++;
      }
    } if(buttons[SELECT]) {
      exitApp = true;
    }

    //bytes to string to long convertion:
    String secondsS = "";
    for (byte i = 0; i<4; i++) {
      secondsS += getInputDigit[i]; 
    }

    seconds = secondsS.toInt();
    totalMilliseconds = seconds * 1000 + getInputDigit[4] * 100;
    
    
    //UI:s
    display.clearDisplay();
    //menuBar:
    display.setCursor(0,0);
    printlnInverted(menuTitle);

    //input:
    display.setCursor(0, 2*8);

    for (int i=0; i<5; i++) {
      if (cursor == i) {
        printStrInverted(String(getInputDigit[i]));
      } else {
        display.print(String(getInputDigit[i]));
      }
      if (i == 3) {
        display.print(F("."));
      }
      if (i > 3) {
        display.println(F("sec"));
      }
    }
    
    display.display();

//    for (int i=0; i<4; i++) {
//      Serial.println("getInput::getInputDigit[" + String(i) +"] = " + String(getInputDigit[i]));
//    }
//    Serial.println("getInput::secondsS = " + secondsS);
//    Serial.println("getInput::totalMilliseconds = " + String(totalMilliseconds));
    Serial.println("getInput::cursor = " + String(cursor));
  }
  
  
  return totalMilliseconds;
}

