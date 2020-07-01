/*******************************************
 * Name: buzzer.ino
 * Date: 07.01.2020
 * Author: Patrick Conlon
 * 
 * Description:
 *  Makes the Passive Buzzer Module Make Noise.
 * 
 * Buzzer Module Pins:
 *  VCC = 3.3 | 5v
 *  GND = Ground
 *  I\O = Interface for SCM (Software Configuration Management)
 * 
 * Arduino Nano Pins:
 *  VIN | 5v = 3.3 | 5v
 *  GND = Ground
 *  D3 = Arduino to buzzer
 * 
 * Other:
 *  f2f = Female to Female Jumper cable (three of these)
 * 
 * Setup:
 *  Connect Nano VIN male connector to Buzzer VCC male connector with f2f jumper cable.
 *  Connect Nano GND male connector to Buzzer GND male connector with f2f jumper cable.
 *  Connect Nano PIN D3 male connector to Buzzer I/O male connector with f2f jumper cable.
 * All done.
 * 
 * What this does:
 *  When digitalAnalog is set to true, then
 *  there will be an increase in pitch. This will continue till
 *  it is stopped. 
 *  When digitalAnalog is set to false, then
 *  the buzzer basically becomes a metronome with a tick tock sound.
 * 
 * Note: Not sure if SCM is correct or not, but was on the packaging of the module
 *  and with some searching that is what I found. I personally do not like when
 *  anyone uses acronyms and expect everyone to know what it means.
 *  Define things people! ;)
 *******************************************/

// Initalize global variables.
int  SENSOR        = 3;     // Sensor pin
bool digitalAnalog = false; // true = change freq; false = tick tock.

void setup() {
    // Setting up pin 3 for output.
    pinMode(SENSOR, OUTPUT);
}

/**
 * @brief: Send value to buzzer to make sound.
 * 
 * @description: Increase the frequency passed to the buzzer.
 *               The buzzer will play the same volume, but the pitch is altered.
 * 
 * @params: int
 * @return: int
 */
int testAnalog(int frequency) {
    analogWrite(SENSOR, frequency);
    delay(50);

    return frequency + 10;
}

/*
 * @brief: continuous looping
 * 
 * @description: Based on the digitalAnalog value or either true or false
 *               will depend on how the buzzer will act.
 *               If true, then the buzzer will behave as a buzzer.
 *               Else, the buzzer will behave more like a clock.
 * 
 * @params: none
 * @return: none
 */
void loop() {
    int freq = 2000;
    
    if (digitalAnalog == true) {
        while (freq < 5000) {
            freq = testAnalog(freq);
        }
    }
    else {
        digitalWrite(SENSOR, HIGH);
        delay(500);
        digitalWrite(SENSOR, LOW);
        delay(500);
    }
}
