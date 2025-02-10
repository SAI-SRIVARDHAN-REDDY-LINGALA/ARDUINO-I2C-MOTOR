                         // SLAVE 

// 📌 Include Wire library for I2C communication
#include <Wire.h>

// 📌 Include LCD library for displaying voltage values
#include <LiquidCrystal_I2C.h>

// 📺 Initialize LCD at I2C address 0x27 (16x2 display)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ⚙️ Define motor control pins (for H-Bridge or motor driver)
const int motorPin1 = 13;  // Motor Direction Pin 1
const int motorPin2 = 12;  // Motor Direction Pin 2
const int pwmPin = 9;      // PWM pin to control motor speed

// 📌 Variable to store the received voltage from the Master
float inputVoltage = 0;  

void setup() {
  // 📡 Initialize I2C communication as a Slave (Address: 8)
  Wire.begin(8);
  
  // 🔄 Register a function that gets triggered when data is received from Master
  Wire.onReceive(receiveData);

  // ⚙️ Set motor control pins as OUTPUT
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  
  // 🖥 Start Serial communication for debugging (9600 baud rate)
  Serial.begin(9600);

  // 📺 Initialize the LCD display
  lcd.init();
  lcd.backlight();

  // 📺 Display startup message
  lcd.setCursor(0, 0);
  lcd.print("Waiting for");
  lcd.setCursor(0, 1);
  lcd.print("input voltage");
}

void loop() {
  // 🔄 Convert received input voltage (-5V to +5V) into a motor voltage range (0V to 12V)
  float outputVoltage = (inputVoltage / 5.0) * 12.0;
  
  // 🔄 Convert absolute output voltage to a PWM duty cycle (0 to 255)
  int pwmValue = map(abs(outputVoltage), 0, 12, 0, 255);

  // 🔄 Motor Direction Control:
  if (outputVoltage > 0) {
    // ➡️ If output voltage is positive, rotate motor forward
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    analogWrite(pwmPin, pwmValue);
  } else if (outputVoltage < 0) {
    // ⬅️ If output voltage is negative, rotate motor in reverse
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    analogWrite(pwmPin, pwmValue);
  } else {
    // ⏹ Stop the motor if the voltage is zero
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
  }

  // 🖥 Print voltage values for debugging
  Serial.print("Input Voltage: ");
  Serial.print(inputVoltage);
  Serial.print(" V, Output Voltage: ");
  Serial.print(outputVoltage);
  Serial.println(" V");

  // 📺 Display input and output voltages on LCD screen
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("In: ");  
  lcd.print(inputVoltage, 2);
  lcd.setCursor(0, 1);
  lcd.print("Out: "); 
  lcd.print(outputVoltage, 2);

  // 🕒 Small delay for stable operation
  delay(50);
}

// 📡 Function to handle received data from the Master
void receiveData(int byteCount) {
  if (byteCount == 2) {  // ✅ Expecting 2 bytes (high + low)
    int receivedValue = (Wire.read() << 8) | Wire.read();  // 🔄 Reconstruct integer value
    inputVoltage = receivedValue / 100.0;  // 🔄 Convert back to float (-5V to +5V)
  }
}