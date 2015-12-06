void mainMenu() {
  Serial.println("main()");
  int cursorPos = 0;
  display.setTextSize(1);
  while(true) {
  
  readButtons();
  if(buttons[UP] && cursorPos > 0) {
    cursorPos--;
  } if(buttons[DOWN] && cursorPos < 4) {
    cursorPos++;
  } if(buttons[RIGHT] || buttons[SELECT]) {
    switch(cursorPos) {
      case(0):
        bulbMode();
        break;
      case(1): 
        intervalometer();
        break;
      }
    } 
  String menuItems[] = {"Bulb Mode", "Intervalometer", "uptime: " + String(millis())};
    displayMenu("Choose mode:", menuItems, cursorPos);
  }
}

