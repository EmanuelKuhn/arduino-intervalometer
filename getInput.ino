//Globals because I don't know how to pass objects to methods in c++
  
  byte getInputDigit[] = {3, 9, 3, 9, 2, 4};
  byte getInputDigits;
  unsigned long getInputMsec;
  

unsigned long getMilliSeconds(byte bgetInputDigits) {
  Serial.println("getInput::getMilliSeconds");

  getInputDigit[4] = 9;
  getInputMsec = 0;
  getInputDigits = bgetInputDigits;

  bool cancel = false;
  bool exitApp = false;
  byte cursor = 0;
  while(!exitApp) {
    readButtons();
    if(buttons[LEFT]) {
      exitApp = true;
      cancel = true;
    } if(buttons[UP]) {

    } if(buttons[DOWN]) {

      
    } if(buttons[RIGHT]) {
      
    } if(buttons[SELECT]) {
      exitApp = true;
    }


    //UI:
    //menuBar:
    display.setCursor(0,0);
    printlnInverted("Input:");

    //input:
    display.setCursor(0, 2*8);
    display.println(String() + F("ms"));
    //buttons:
    
    display.display();
  }
  display.clearDisplay();
  
  
  if(!cancel) {
    calcMs();
    return getInputMsec;
  }
  return 0;
}

void calcMs() {
  getInputMsec = 0;
  byte exp = getInputDigits-1;
    for(byte i = 0; i<getInputDigits; i++) {
      Serial.println("hai2");
      Serial.println(String(getInputDigit[i] * pow(10, i)));
      Serial.println(String(getInputDigit[i]));
      getInputMsec += getInputDigit[i] * pow(10, exp);
      exp--;
    }
//    getInputMsec++;
}


