#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 
#define OLED_RESET -1  
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  // Inicializar OLED
  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(5, 5);
  display.println("Dato:");
  display.display();
}

void loop() {
  if (Serial.available()) {
    String data = Serial.readStringUntil('\n');
    display.clearDisplay();
    display.setCursor(5,5);
    display.println("Dato:");
    display.setCursor(5,15);
    display.println(data);
    display.display();
  }
}
