# arduino
Arduino Projects

https://github.com/patmconlon/arduino

Branch RCWL-0516:
 Description:
   The RCWL-0516 board interfacing with
   the Arduino Nano. When the signal is
   detected the LED light(s) will turn on.
 
 Setup
   RCWL-0615 Key Features
     Transmit power: 20 mW (minimum)/30 mW (max)
     Voltage input: 4–28 VDC
     Sensing Distance: 5–7 m
     Frequency of sensor: ~3.2 GHz
 
   RCWL-0615 Pinout
     VIN — 4V - 28V DC power supply input
     CDS — Sensor disable input (low = disable) (For LDR sensors)
     GND — Ground
     3volt— DC output (100 mA maximum)
     OUTPUT — HIGH /LOW(3.3 V) (according to the motion detection)
   
   Hookup
     Arduino Nano RCWL-0516
     GND          GND
     5V           VIN
     D3           OUT
   
   Circuit
     Connecting Nano to RCWL-0516
         Nano GND to breadboard GND
         Breadboard GND to RCWL-0516 GND
         
         Nano VIN to RCWL-0516 VIN
     This connects the RCWL-0516 to be powered
     by the Nano.
     
     Connecting the RCWL-0516 output to power the
     LED light(s).
         RCWL-0516 OUT to Nano Pin D12
         Nano Pin D3 to breadboard PWR
         breadboard PWR to Resistor
         Resistor to breadboard 5A
         LED POS in 5B NEG in 6B
         NEG Jump from 6C to NEG
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

Branch audino9012Drive:
 Description:
    Makes the Passive Buzzer Module Make Noise.
 
 Buzzer Module Pins:
    VCC = 3.3 | 5v
    GND = Ground
    I\O = Interface for SCM (Software Configuration Management)
 
 Arduino Nano Pins:
    VIN | 5v = 3.3 | 5v
    GND = Ground
    D3 = Arduino to buzzer
 
 Other:
    F2F = Female to Female Jumper cable (three of these)
 
 Setup:
    Connect Nano VIN male connector to Buzzer VCC male connector with F2F jumper cable.
    Connect Nano GND male connector to Buzzer GND male connector with F2F jumper cable.
    Connect Nano PIN D3 male connector to Buzzer I/O male connector with F2F jumper cable.
    All done.
 
 What this does:
    When digitalAnalog is set to true, then
    there will be an increase in pitch. This will continue till
    it is stopped. 
    When digitalAnalog is set to false, then
    the buzzer basically becomes a metronome with a tick tock sound.
 
 Note: Not sure if SCM is correct or not, but was on the packaging of the module
    and with some searching that is what I found. I personally do not like when
    anyone uses acronyms and expect everyone to know what it means.
    Define things people! ;)
=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

