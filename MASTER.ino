
             // MASTER 

// 📌 Include Wire library for I2C communication
#include <Wire.h>

// 📌 Define the analog input pin where the potentiometer is connected
const int potentiometerPin = A0;

// 📌 Variable to store the processed voltage in integer form
int voltageToSend = 0;  

void setup() {
  // 📡 Initialize I2C communication as a Master
  Wire.begin(); 
  
  // 🖥 Start Serial communication for debugging (9600 baud rate)
  Serial.begin(9600);
}

void loop() {
  // 📌 Read the raw analog value from the potentiometer (0-1023)
  int sensorValue = analogRead(potentiometerPin);
  
  // 🔄 Convert the raw sensor value into a voltage range (-5V to +5V)
  float inputVoltage = ((sensorValue / 1023.0) * 10.0) - 5.0;
  
  // 📝 Convert the float voltage into an integer (scaled by 100) for accurate I2C transmission
  voltageToSend = (int)(inputVoltage * 100);  

  // 📡 Start I2C transmission to Slave device with address 8
  Wire.beginTransmission(8);
  
  // ✉️ Send the **high byte** of the voltage value
  Wire.write((voltageToSend >> 8) & 0xFF);  
  
  // ✉️ Send the **low byte** of the voltage value
  Wire.write(voltageToSend & 0xFF);  
  
  // 🔚 End transmission to Slave
  Wire.endTransmission();  

  // 🖥 Print the voltage value for debugging purposes
  Serial.print("Input Voltage: ");
  Serial.println(inputVoltage);

  // 🕒 Small delay to prevent buffer overflow and CPU overuse in Proteus
  delay(50);
}
