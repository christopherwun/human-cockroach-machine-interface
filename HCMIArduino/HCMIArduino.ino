#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo servo;
const int numReadings = 25;    // Number of readings to average
int readings[numReadings];     // Readings from the analog input
int readIndex = 0;             // Index of the current reading
int total = 0;                 // Total of the readings
int average = 0;               // The average

// Set up timer
unsigned long startTime;
const long timerDuration = 5000; // 5 seconds in milliseconds
bool timerActive = false;

void setup() {

  if (!timerActive) {
    // Start the timer
    startTime = millis();
    timerActive = true;
  }

  // Initialize the LCD
  lcd.init();
  
  // Turn on the backlight
  lcd.backlight();

  // Print a message to the LCD
  lcd.setCursor(0, 0); // Set the cursor on the first column and the first row.
  lcd.print("Brain Ball Blaster");
  lcd.setCursor(0, 1); // Set the cursor on the first column and the second row (if applicable).
  lcd.print("LCD Tutorial");
  
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT);
  servo.attach(3);
  
  Serial.begin(9600);

  // Initialize all the readings to 0
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {
  // Subtract the last reading
  total = total - readings[readIndex];
  // Read from the sensor
  readings[readIndex] = analogRead(A0);
  // Add this reading to the total
  total = total + readings[readIndex];
  // Advance to the next position in the array
  readIndex = readIndex + 1;

  // If we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning
    readIndex = 0;
  }

  // Calculate the average
  average = total / numReadings;
  // Map the average value to a servo angle
  int angle = map(average, 0, 1023, 0, 179);

  servo.write(angle);
  Serial.println(average);
}
