
#include <math.h>

double Thermister(int RawADC) {
  double Temp;
  Temp = log(((10240000/RawADC) - 10000));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;                                       // Convert Kelvin to Celcius
  Temp = (Temp * 9.0)/ 5.0 + 32.0;                            // Convert Celcius to Fahrenheit
  return Temp;
}

const int sensorPin = 0;                                      // pin the potmeter is attached too
const int ledPinR   = 9;                                      // pwm pin with red led
const int ledPinG   = 10;                                     // pwm pin with green led
const int ledPinB   = 11;                                     // pwm pin with blue led

int sensorVal = 0;                                            // store the value coming from the sensor

// getRGB function stores RGB values in this array use these values for the red, blue, green led. 
int rgb_colors[3]; 
int hue;
int saturation;
int brightness;

void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  // Serial.begin(115200); unremark this and the about 10 lines down for feedback from sensor.
}

void loop() {

  sensorVal = int(Thermister(analogRead(sensorPin)));
  hue        = map(sensorVal,-5, 35,0, 270);                 //  240 is red in HSB/HSV
  saturation = 255;                                         // saturation is a number between 0 - 255
  brightness = 255;		                            // value is a number between 0 - 255

  hue = 240 - hue;

  getRGB(hue,saturation,brightness,rgb_colors);             // converts HSB to RGB

  analogWrite(ledPinR, rgb_colors[0]);                      // red value in index 0 of rgb_colors array
  analogWrite(ledPinG, rgb_colors[1]);                      // green value in index 1 of rgb_colors array
  analogWrite(ledPinB, rgb_colors[2]);                      // blue value in index 2 of rgb_colors array
  
  // Serial.println(int(Thermister(analogRead(sensorPin))));   // display Fahrenheit
}

void getRGB(int hue, int sat, int val, int colors[3]) { 
  // convert hue, saturation and brightness ( HSB/HSV ) to RGB    
  int r;
  int g;
  int b;
  int base;

  if (sat == 0) { // Acromatic color (gray). Hue doesn't mind.
    colors[0]=val;
    colors[1]=val;
    colors[2]=val;  
  } 
  else  { 
    base = ((255 - sat) * val)>>8;
    switch(hue/60) {
    case 0:
      r = val;
      g = (((val-base)*hue)/60)+base;
      b = base;
      break;
    case 1:
      r = (((val-base)*(60-(hue%60)))/60)+base;
      g = val;
      b = base;
      break;
    case 2:
      r = base;
      g = val;
      b = (((val-base)*(hue%60))/60)+base;
      break;
    case 3:
      r = base;
      g = (((val-base)*(60-(hue%60)))/60)+base;
      b = val;
      break;
    case 4:
      r = (((val-base)*(hue%60))/60)+base;
      g = base;
      b = val;
      break;
    case 5:
      r = val;
      g = base;
      b = (((val-base)*(60-(hue%60)))/60)+base;
      break;
    }
    colors[0]=r;
    colors[1]=g;
    colors[2]=b; 
  }   
}
