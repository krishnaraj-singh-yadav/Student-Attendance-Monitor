# Student-Attendance-Monitor
# ----------Project Overview-----------
This project is an RFID-based access control system using an Arduino UNO. The system uses an RFID reader and tags to grant or deny access, and records the data of a student including TIME, NAME, REGISTRATION NO., and GROUP in an Excel sheet. Additionally, it incorporates two IR sensors (one for entry and another for exit), a 2x16 LCD display to show the count of students, and red and green LEDs to provide feedback to the user when RF tags are scanned through the RF reader.

# --------Components Used---------
1. Arduino UNO
2. RFID Reader (RC522)
3. RFID Tags
4. IR Sensor
5. 2x16 LCD Display
6. LEDs (Red and Green)
7. Breadboard and Jumper Wires
8. Resistors
# -------Features--------
# RFID-based Authentication:
The system reads RFID tags and compares them against a list of authorized tags.
# IR Sensor: 
Detects the presence of a user and activates the system.
# LCD Display: 
Provides feedback to the user, such as "Access Granted" or "Access Denied".
Shows the count of students.
Indicates the condition of the room light.
# LED Indicators: 
Green LED lights up for granted access.
Red LED lights up for denied access.
Blue LED lights up if there is at least one student in the class.
# Information Logging
Student information such as TIME, NAME, REGISTRATION NO., and GROUP will be recorded in an Excel sheet when an RF tag is scanned through the RF reader.
