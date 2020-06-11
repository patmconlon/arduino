/*****
 * Name: rcwl-0516.ino
 * Author: Patrick Conlon
 * Description:
 *   The RCWL-0516 board interfacing with
 *   the Arduino Nano. When the signal is
 *   detected the LED light(s) will turn on.
 * 
 * Setup
 *   RCWL-0615 Key Features
 *     Transmit power: 20 mW (minimum)/30 mW (max)
 *     Voltage input: 4–28 VDC
 *     Sensing Distance: 5–7 m
 *     Frequency of sensor: ~3.2 GHz
 * 
 *   RCWL-0615 Pinout
 *     VIN — 4V - 28V DC power supply input
 *     CDS — Sensor disable input (low = disable) (For LDR sensors)
 *     GND — Ground
 *     3volt— DC output (100 mA maximum)
 *     OUTPUT — HIGH /LOW(3.3 V) (according to the motion detection)
 *   
 *   Hookup
 *     Arduino Nano RCWL-0516
 *     GND          GND
 *     5V           VIN
 *     D3           OUT
 *   
 *   Circuit
 *     Connecting Nano to RCWL-0516
 *         Nano GND to breadboard GND
 *         Breadboard GND to RCWL-0516 GND
 *         
 *         Nano VIN to RCWL-0516 VIN
 *     This connects the RCWL-0516 to be powered
 *     by the Nano.
 *     
 *     Connecting the RCWL-0516 output to power the
 *     LED light(s).
 *         RCWL-0516 OUT to Nano Pin D12
 *         Nano Pin D3 to breadboard PWR
 *         breadboard PWR to Resistor
 *         Resistor to breadboard 5A
 *         LED POS in 5B NEG in 6B
 *         NEG Jump from 6C to NEG
 */
int SENSOR     = 12;
int LED        = 3;
int BRIGHTNESS = 0;
int FADE       = 5;
int DOFADE     = false; // true = fade; false = don't fade.

void setup()
{
  pinMode(SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void fadingLED(boolean fader)
{
  if (fader == true) {
    while (BRIGHTNESS < 255) {
      analogWrite(LED, BRIGHTNESS);
      delay(100);
      BRIGHTNESS += FADE; // Increase brightness by 5.
    }

    delay(8000); // 8 second of full LED light.

    while (BRIGHTNESS > 0) {
      analogWrite(LED, BRIGHTNESS);
      delay(100);
      BRIGHTNESS -= FADE; // Decrease brightness by 5.
    }

    BRIGHTNESS = 0; // Just in case.
  }
  else {
    digitalWrite(LED, HIGH);
    delay(8000); // 8 seconds of full LED light.
  }
}

void loop()
{
  int value = digitalRead(SENSOR); // This is the output from motion detected.

  // Testing the value.
  if (value > 0) {
    fadingLED(DOFADE);
  }
  else {
    digitalWrite(LED, LOW); // Make sure LED lights are off.
  }

  value = 0;   // Reset the value.
  delay(2000); // 2 seconds for recovery.
}
