void printlnInverted (String str) {
  byte cursorY = display.getCursorY();
        byte cursorX = display.getCursorX();
        display.setTextColor(WHITE, BLACK);
        display.print("              ");
        display.setCursor(cursorX, cursorY);
        display.print(str);
        display.setTextColor(BLACK);
        display.setCursor(0, cursorY+8);
}

void printStrInverted (String str) {
  display.setTextColor(WHITE, BLACK);
  display.print(str);
  display.setTextColor(BLACK);
}

