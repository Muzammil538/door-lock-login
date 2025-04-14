import serial
import time
import pywhatkit

# Replace with your COM port
esp = serial.Serial('/dev/cu.usbserial-0001', 9600, timeout=1)
time.sleep(2)

print("🔐 Listening to ESP8266...")

def send_alert(reason):
    try:
        if reason == "FORGOT_PASSWORD":
            msg = "🔐 Forgot Password Alert!\nPassword: 1234"
        else:
            msg = "🚨 Smart Lock Alert!\n⚠️ 3 failed login attempts detected."

        pywhatkit.sendwhatmsg_instantly(
            phone_no="+917075469007",  # Your number
            message=msg,
            wait_time=10,
            tab_close=True
        )
        print("✅ WhatsApp sent:", reason)
    except Exception as e:
        print("❌ Failed:", e)

try:
    while True:
        if esp.in_waiting:
            data = esp.readline().decode('utf-8').strip()
            print("📩 From ESP:", data)
            if data == "FORGOT_PASSWORD":
                send_alert("FORGOT_PASSWORD")
            elif data == "ALERT_FAIL":
                send_alert("ALERT_FAIL")

except KeyboardInterrupt:
    esp.close()
    print("🔌 Exiting...")
