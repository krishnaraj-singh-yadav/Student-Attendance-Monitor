# Student-Attendance-Monitor
# ----------Project Overview-----------
This project is an RFID-based access control system using an Arduino UNO. The system uses an RFID reader and tag to grant or deny access and the data of a student as TIME ,  NAME , REGISTRAtion no.,and GROUP are noted in excel sheet . Additionally, it incorporates two IR sensors , one for entry and other for exit and a 2x16 LCD display show count of student and red and green LEDs to provide feedback to the user when RF Tag are scanned through RF Reader.

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
Provides feedback to the user, such as "Access Granted" or "Access Denied" , show count of student and condition of room light .
# LED Indicators: 
Green LED lights up for granted access, and Red LED lights up for denied access.
Blue LED light up if there is even a single student in the class.
# Information on excel sheet:
Student information such as  TIME ,  NAME , REGISTRAtion no.,and GROUP will be fed when RF Tag will be scanned through RF Reader.
