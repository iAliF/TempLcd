#include <Adafruit_PCD8544.h>

const int blPin = 3, rstPin = 4, cePin = 5, dcPin = 6, dinPin = 7, clkPin = 8;
Adafruit_PCD8544 display = Adafruit_PCD8544(clkPin, dinPin, dcPin, cePin, rstPin);

void loadingScreen() {
  display.println("Loading");
  display.display();

  for (int i = 10; i < 74; i++) {
    for (int j = 30; j < 34; j++) {
      display.drawPixel(i, j, BLACK);
    }

    delay(250);
    display.display();
  }
}

void setup() {
  Serial.begin(9600);

  // Setup display
  display.begin(57);
  display.clearDisplay();

  // Set back light
  pinMode(blPin, OUTPUT);
  analogWrite(blPin, 255);

  // Set Text Size & Color
  display.setTextSize(1);
  display.setTextColor(BLACK);

  // Draw Rect
  display.drawRoundRect(0, 0, display.width(), display.height(), 8, BLACK);
  display.setCursor(20, 15);

  loadingScreen();
}

void loop() {
}
