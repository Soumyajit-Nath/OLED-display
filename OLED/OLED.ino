#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Define OLED dimensions and I2C address
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Reset pin not used
#define DISPLAY_ADDRESS 0x3C

// Define custom I2C pins
#define OLED_SDA 17  // Change to your chosen SDA pin
#define OLED_SCL 16  // Change to your chosen SCL pin

TwoWire I2C_OLED = TwoWire(0);  // Use a custom Wire instance
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &I2C_OLED, OLED_RESET);

void setup() {
  Serial.begin(9600);

  // Initialize I2C with custom pins
  I2C_OLED.begin(OLED_SDA, OLED_SCL);

  // Initialize the display
  if (!display.begin(SSD1306_SWITCHCAPVCC, DISPLAY_ADDRESS)) {
    Serial.println("SSD1306 allocation failed");
    while (true)
      ;  // Stop if the display doesn't initialize
  }

  // Display "Hello, World!" message
  display.clearDisplay();
  display.setTextSize(2);  // Set text size to make it readable
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20);  // Set cursor position
  display.println("WELCOME");
  display.display();
  delay(5000);

  // Clear the screen after welcome message
  display.clearDisplay();
}

void loop() {
      // Example of dynamic content to display sensor data
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);

    // Display heading
    display.setCursor(0, 0);
    display.println("Agri Arena");
    display.println("Sensor Data");

    // Simulate temperature and humidity values
    float temperature = 24.5;  // Replace with actual reading
    float humidity = 60.2;     // Replace with actual reading
    float soilMoisture = 45.0; // Replace with actual reading

    display.display();
    delay(3000);
}
