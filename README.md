Absolutely! Here's a **complete beginner-friendly documentation** to help you build a **Wi-Fi-based Door Lock System** using **ESP8266**, a **servo motor**, and **free WhatsApp alerts using CallMeBot API** — from scratch.

---

# 🔐 Wi-Fi Door Lock System with ESP8266 + WhatsApp Alerts (Beginner Guide)

---

## 📦 What You’ll Build:
- A simple login page hosted by the ESP8266.
- If the user enters the **correct credentials**, the **door opens** (servo motor rotates).
- If login **fails**, a **WhatsApp alert** is sent to the owner — all for **free**.

---

## 🛠️ Components Needed:
| Component          | Quantity |
|--------------------|----------|
| ESP8266 NodeMCU    | 1        |
| Servo Motor (e.g., SG90) | 1        |
| Jumper Wires       | As needed |
| Breadboard (optional) | 1        |
| Power Supply (USB or 5V) | 1        |

---

## 🔌 Circuit Diagram

| ESP8266 Pin | Connect To         |
|-------------|--------------------|
| `D4` (GPIO2) | Servo Signal (Orange/White) |
| `3.3V` / `Vin` | Servo VCC (Red)    |
| `GND`       | Servo GND (Brown/Black) |

> ⚠️ Use `Vin` if your servo needs more power than 3.3V. Make sure the total current draw is safe.

---

## 💻 Software Required:
- Arduino IDE (Install from [here](https://www.arduino.cc/en/software))
- ESP8266 Board Package
- USB cable for flashing

---

## 🔧 Setup Arduino IDE

1. **Install ESP8266 Board Support**  
   - Go to `File > Preferences`
   - In "Additional Boards URL", paste:
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
   - Go to `Tools > Board > Boards Manager`, search "ESP8266" and install.

2. **Select Your Board and Port**  
   - Board: `NodeMCU 0.9 (ESP-12 Module)`
   - Port: Select the correct COM port (check in Device Manager if unsure)

---

## 🧾 Get Your Free CallMeBot API Key

1. Save the number `+34 644 53 78 56` to your phone contacts.
2. Open WhatsApp, and send:
   ```
   I allow callmebot to send me messages
   ```
3. CallMeBot will reply with your **API key**.

✅ **Note that this is totally free!**

---


## 🧪 Testing It Out

1. Upload the code to ESP8266.
2. Open **Serial Monitor** at **115200 baud**.
3. Look for the line:
   ```
   📡 IP Address: 192.168.x.x
   ```
4. Open that IP in your browser (on same Wi-Fi).
5. Try logging in:
   - Correct = Servo rotates to unlock
   - Wrong = WhatsApp alert sent to you

---

## ❓ Troubleshooting

| Problem | Solution |
|--------|----------|
| Can't open ESP IP | Make sure you're on same Wi-Fi, and get IP from Serial Monitor |
| WhatsApp not received | Ensure you completed CallMeBot setup, and your phone is connected to internet |
| Servo not moving | Check wiring, use `Vin` if it needs more than 3.3V |
| Login not working | Check username (`admin`) and password (`1234`) in code |

---
