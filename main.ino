void mainMenu() {
  Serial.println(F("main()"));
  int cursorPos = 0;
  display.setTextSize(1);
  while(true) {
  
  readButtons();
  if(buttons[UP] && cursorPos > 0) {
    cursorPos--;
  } if(buttons[DOWN] && cursorPos < 1) {
    cursorPos++;
  } if(buttons[RIGHT] || buttons[SELECT]) {
    switch(cursorPos) {
      case(0):
        intervalometer();
        break;
      case(1): 
        bulbMode();
        break;
      }
    } 
    String menuItems[] = {"Intervalometer", "Bulb Mode", "", "", "", ""};
    displayMenu("Choose mode:", menuItems, cursorPos);
  }
}

