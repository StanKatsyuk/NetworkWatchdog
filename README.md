# Network Monitor/Watchdog 
	Checks your network status and resets your router/modem if network connectivity is lost.

# Hardware used:
	1 x Arduino MKR-WIFI1010
	1 x DigitalLoggers.com IoT Relay (https://www.amazon.com/Iot-Relay-Enclosed-High-power-Raspberry/dp/B00WV7GMA2)
	1 x Blue LED (use a 220k resistor)

# Set up
	Relay trigger is on pin 7
	LED pin is on 13
  Download the .ino file, open it inside the arduino software and flash it onto your arduino.

# How it works :
	The program will connect to your wi-fi network and ping out to www.google.com once every 35 seconds. If more than 3 consecutive ping attempts are unsuccesful, it will trigger the relay to reset the outlet powering your router/modem. 

Created 15 May 2019 by Stan Katsyuk
