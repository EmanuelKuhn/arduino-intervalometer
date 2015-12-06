void readButtons () {
//  Serial.println("readButtons()");
  for(byte i=0; i<5; i++) {
    buttons[i] = false;
  }
  if(!buttonsFreeze) {
    readButton(A0, UP);
    readButton(A1, RIGHT);
    readButton(A2, DOWN);
    readButton(A3, LEFT);
    readButton(12, SELECT);
  } else {
    if (millis() > buttonsUnFreeze) {
      buttonsFreeze = false;
    }
  }
}

void readButton(int pin, int button) {
  pinMode(pin, INPUT);
  digitalWrite(pin, HIGH);
  if(!digitalRead(pin)) {
    buttons[button] = true;
    buttonsFreeze = true;
    buttonsUnFreeze = millis() + buttonFreezeDelay;
  }
}

