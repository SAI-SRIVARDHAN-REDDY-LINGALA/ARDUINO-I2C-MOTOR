# ARDUINO-I2C-MOTOR
Arduino-Based Motor Control System with I2C Communication

# 📜 **Arduino-Based Motor Control System with I2C Communication** 🚀  
🎉 **Developed using Arduino & Proteus for learning and experimentation!** 🔥🚀

## 🎯 **Project Overview**  
This project demonstrates **DC motor speed and direction control** using **two Arduino boards** that communicate via **I2C protocol**. The system uses a **potentiometer** as an input, and a **motor driver** (L293D/BTS7960) to drive the motor. Additionally, an **LCD display** shows real-time voltage values.  

---

## ⚙️ **System Workflow**  
🔹 **Arduino 1 (Master)** reads input from a **potentiometer** (-5V to +5V).  
🔹 **I2C Communication** sends the processed voltage data to **Arduino 2 (Slave)**.  
🔹 **Arduino 2 (Slave)** controls the **motor driver** using **PWM** signals.  
🔹 **Motor driver** generates an output voltage of **-12V to +12V** based on input.  
🔹 **LCD Display** shows the input and output voltages in real time.  

---

## 🔌 **Components Used**  
- 🎛 **Arduino 1 (Master)** – Reads potentiometer values & transmits via I2C.  
- 🎛 **Arduino 2 (Slave)** – Receives data, controls motor driver & updates LCD.  
- 🎚 **Potentiometer** – Provides adjustable voltage input.  
- ⚡ **Motor Driver (L293D/BTS7960)** – Amplifies Arduino output for motor control.  
- 🔄 **DC Motor** – Controlled using PWM for speed & direction.  
- 📟 **LCD Display (JHD-2X16-I2C)** – Displays input & output voltages.  
- 🔌 **I2C Communication Wires** – Connect SDA & SCL pins between Arduinos.  
- 🔧 **Pull-up Resistors (4.7kΩ)** – Ensures proper I2C communication.  

---

## 🔗 **Circuit Connections**  
### **📌 Arduino 1 (Master)**  
✅ **Potentiometer → A0**  
✅ **SDA (A4) & SCL (A5) → Arduino 2 (Slave)**  
✅ **GND → Shared with Arduino 2**  

### **📌 Arduino 2 (Slave)**  
✅ **SDA & SCL → Arduino 1**  
✅ **Motor Driver → Motor Pins & PWM Control**  
✅ **LCD Display → I2C Communication (SDA & SCL)**  

---

## 🔬 **I2C Communication - Hardware Level Understanding**  
📡 **I2C (Inter-Integrated Circuit)** is a serial communication protocol that uses:  
✔️ **SDA (Serial Data Line)** – Carries the data bits.  
✔️ **SCL (Serial Clock Line)** – Synchronizes data transfer.  

### **🛠 How It Works:**  
1️⃣ **Arduino 1 (Master)** initiates communication & sends input voltage.  
2️⃣ **Arduino 2 (Slave)** receives data & maps it to motor control logic.  
3️⃣ **Motor driver** controls the motor using **PWM signals**.  
4️⃣ **LCD** displays **real-time voltage readings**.  

🔹 **Precision Handling:** Data transmission maintains **0.01V accuracy**.  
🔹 **Pull-up Resistors (4.7kΩ)** are used for stable I2C communication.  

---

## 🖥 **Software Implementation**  
✔️ **Arduino 1 (Master):**  
- Reads **analog input from potentiometer**.  
- Maps input voltage range **(-5V to +5V)** to **(0-255) for I2C transmission**.  
- Sends data to Arduino 2 via **I2C protocol**.  

✔️ **Arduino 2 (Slave):**  
- Receives data & converts it back to voltage range **(-12V to +12V)**.  
- Uses **PWM** to control the motor driver for speed & direction.  
- Updates the **LCD display** with real-time voltage readings.  

---

## 📂 **Project Files**  
📜 PDF ->PROJECT REPORT
📜 'MASTER CODE' -> MASTER ARDUINO CODE (ARDUINO IDE)
📜 'SLAVE CODE' -> SLAVE ARDUINO CODE (ARDUINO IDE)
📜 `SSP2.pdsprg` → Full system circuits SIMULATED  IN PROTEUS 
📜 'SCREENSHOT' -> CIRCUUT DIAGRAM SCREENSHOT 
📜 `README.md` → This documentation  

---

## 🎯 **Results & Observations**  
✅ **Successful I2C communication** between two Arduinos.  
✅ **Smooth motor control** with accurate **PWM voltage mapping**.  
✅ **LCD provides real-time feedback** of input & output voltages.  
✅ **Minimal data loss** in transmission, maintaining **0.01V precision**.  

---

## 🚀 **Future Improvements**  
🔹 **Implement PID control** instead of a simple proportional controller.  
🔹 **Use external ADC for higher resolution** in voltage reading.  
🔹 **Test with different motor drivers** for optimized efficiency.  
🔹 **Enhance display features** with graphical representation.  

---

## 📖 **References**  
🔗 [I2C Protocol Overview](https://www.arduino.cc/en/Tutorial/MasterReader)  
🔗 [L293D Motor Driver Datasheet](https://www.tescaglobal.com/pdf/l293d.pdf)  
🔗 [Proteus Software Installation](https://www.geeksforgeeks.org/how-to-download-and-install-proteus-software-on-windows/)  

---
