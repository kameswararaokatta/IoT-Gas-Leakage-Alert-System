IoT Gas Leakage Alert & Auto-Regulating System
Project Overview

The IoT Gas Leakage Alert & Auto-Regulating System is an embedded safety solution designed to detect gas leakage and automatically prevent accidents by shutting off the gas supply and alerting users through GSM calls.

Unlike conventional gas detectors that only provide a local alarm, this system actively regulates the gas supply using a servo motor and notifies two users instantly via mobile calls, ensuring rapid response even when occupants are not present.

This project was developed as an academic / hackathon-based group project using Arduino and GSM technology.

Objectives
Detect LPG / combustible gas leakage
Automatically turn OFF the gas regulator
Alert responsible users through GSM calls
Reduce dependency on human intervention
Improve response time during emergencies

🛠️ Hardware Components Used
Component	Description
Arduino Uno	Main microcontroller
MQ Gas Sensor (MQ-2 / MQ-5)	Detects gas leakage
GSM Module (SIM800 / SIM900)	Emergency call alerts
Servo Motor	Controls gas regulator ON/OFF
Buzzer	Local alert indication
External Power Supply	For GSM & Servo

Pin Connections
Module ->	Arduino Pin
MQ Sensor (AO) ->	A0
Servo Signal ->	D9
GSM TX ->	D2
GSM RX ->	D3
Buzzer  -> D8

⚠️ Note: GSM module and servo motor must use an external power supply.
⚙️ Working Principle
The MQ gas sensor continuously monitors gas concentration.
Arduino reads sensor values and compares them with a predefined threshold.
When gas leakage is detected:
Servo motor rotates to turn OFF the gas regulator.
Buzzer is activated for local alert.
GSM module makes emergency calls to User 1 and User 2.
The system remains in a safe state until manual reset.

🔁 System Flow
Start System
Initialize Sensor, GSM, Servo
Monitor Gas Level
Gas Detected?
✅ YES → Shut off gas + Call User 1 & User 2
❌ NO → Continue Monitoring
📞 Alert Mechanism
GSM module automatically places two phone calls:
Primary User
Secondary User
Ensures alert delivery even if one user is unavailable.

Results & Performance:
Parameter	Result
Detection Time	< 3 seconds
Gas Shut-off	Immediate
Call Alert Delay	< 20 seconds
Reliability	Stable during testing

Testing Method:
MQ sensor calibrated using lighter gas (without ignition)
Servo rotation tested for proper regulator control
GSM network tested with valid SIM card
Multiple trials conducted successfully

Applications:
Domestic kitchens
Apartments and hostels
Restaurants and hotels
Gas storage areas
Laboratories

Advantages:
Automatic gas regulation
Works without internet
Low-cost and easy to implement
Fast emergency response
Reduces fire and explosion risk

Limitations:
Single-zone gas monitoring
No mobile app or cloud storage
Manual reset required after gas shut-off
Future Enhancements
SMS alerts along with calls
Mobile application integration
Multi-sensor support
Battery backup
IoT cloud monitoring

Project Outputs:

✔️ Working hardware prototype

✔️ Project completion certificate

✔️ Group photographs

✔️ Live demonstration video

Conclusion

The IoT Gas Leakage Alert & Auto-Regulating System demonstrates how embedded systems and GSM communication can be effectively used to enhance safety. By combining detection, automatic gas shut-off, and real-time alerting, the system significantly reduces response time and potential damage during gas leakage incidents.

“Safety should not wait for human reaction—automation must act first.”
