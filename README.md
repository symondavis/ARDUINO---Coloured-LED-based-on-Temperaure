###ARDUINO - Coloured LED based on Temperaure


####Input
PIN 0  = I'm using a 503 Thermistor, simple setup with resistor(10K) on 5v.

####Output
PIN 9  = LED pin for Red.
PIN 10 = LED pin for Green.
PIN 11 = LED pin for Blue.

####The Code
######Functions
Thermistor - Calculates the sensor value to Celcius.
getRGB - converts HSV to RGB.

######Loop
1. Read sensor
2. Map the sensor value to a corrisponding HSV range, in this instance 0 degrees to 270 degrees mapped to celcius values -5 to +35
3. Invert the HSV colour palette, no one wants Blue as hot!
4. Use function getRGB, sends HSV and returns RGB value for LED's.
5. AnalogWrite the RGB to LED Pins.

####Description
Sensor I'm using is a 503, which isn't accurate compared to other devices, yet! as this isn't displaying actual values but using colour to define the temperature so it's not as important.
Although the code works for a temperature range defined as -5 to 35 degrees celcius it actually works fine further around the temperatures.

####Still to do!
I need to tidy the code up a little more and possibly add ethernet capability to the Arduino to send details to a webserver and additionally display the colour accordingly. This will likely be done in PHP.
