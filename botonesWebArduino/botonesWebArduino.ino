#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define OLED_RESET 4
Adafruit_SH1106 display(OLED_RESET);

void setup() {
  Serial.begin(9600);
  // Inicializar OLED
  delay(250); // wait for the OLED to power up
  display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
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
