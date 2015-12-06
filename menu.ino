void displayMenu(String menuTitle, String menuItems[8], byte pos) {
//   Serial.println("displayMenu()");
    display.clearDisplay();
    display.setCursor(0, 0);
    printlnInverted(menuTitle);
    
    //draw menuItems
    display.setTextColor(BLACK);
    for(byte i = 0; i<5; i++) {
      display.setCursor(0, 8 * i + 8);
      if(pos == i) {
        display.print(">" + menuItems[i]);
      } else {
       display.print(menuItems[i]);
      }
    };
    display.display();
};
