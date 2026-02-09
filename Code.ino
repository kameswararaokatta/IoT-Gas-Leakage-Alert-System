#include <SoftwareSerial.h>
#include <Servo.h>

/* -------- PIN DEFINITIONS -------- */
#define GAS_SENSOR   A0
#define SERVO_PIN    9
#define BUZZER       8

#define GSM_RX       2   // Arduino RX ← GSM TX
#define GSM_TX       3   // Arduino TX → GSM RX

/* -------- OBJECTS -------- */
SoftwareSerial gsm(GSM_RX, GSM_TX);
Servo gasServo;

/* -------- PHONE NUMBERS -------- */
const char user1[] = "+911234567890";   // Replace
const char user2[] = "+919876543210";   // Replace

/* -------- SETTINGS -------- */
int gasThreshold = 400;   // Adjust after calibration
bool gasDetected = false;

void setup() {
  Serial.begin(9600);
  gsm.begin(9600);

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);

  gasServo.attach(SERVO_PIN);
  gasServo.write(0);   // 0° = Gas ON position

  delay(3000);

  Serial.println("System Ready");
  gsm.println("AT");
  delay(1000);
}

void loop() {
  int gasValue = analogRead(GAS_SENSOR);
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > gasThreshold && !gasDetected) {
    gasDetected = true;
    emergencyAction();
  }

  delay(1000);
}

/* -------- EMERGENCY FUNCTION -------- */
void emergencyAction() {
  Serial.println("GAS LEAK DETECTED!");

  // Buzzer ON
  digitalWrite(BUZZER, HIGH);

  // Turn OFF gas regulator
  gasServo.write(90);   // 90° = Gas OFF
  delay(1000);

  // Call User 1
  makeCall(user1);
  delay(15000);

  // Call User 2
  makeCall(user2);
  delay(15000);

  digitalWrite(BUZZER, LOW);
}

/* -------- CALL FUNCTION -------- */
void makeCall(const char* number) {
  gsm.print("ATD");
  gsm.print(number);
  gsm.println(";");
  Serial.print("Calling ");
  Serial.println(number);
}
