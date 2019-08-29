 
## INTRODUCTION

Please read the Arduino [introduction](https://www.arduino.cc/en/Guide/Introduction) page for background details about Arduino and Arduino programming

## INSTALLATION OF ARDUINO IDE

Visit the [Arduino](https://www.arduino.cc/en/Guide/HomePage) site to download and install the Arduino IDE based on your operating system.
			  
## PORT

Ensure the micro-controller is connected to your desktop by confirming the connected port is displayed using Tools -> Port

## ADAFRUIT FEATHER M0 and ESP8266

Most of the examples in this tutorial will be based on the Adafruit Feather M0 and ESP8266. Since these are other vendor boards, we will have to include the URLs for these boards.

From File -> Preferences -> Additional Boards Manager URLs: 
```
https://adafruit.github.io/arduino-board-index/package_adafruit_index.json  // for Adafruit Feather M0 
http://arduino.esp8266.com/stable/package_esp8266com_index.json             // for Adafruit ESP8266
```

## BOARDS

The Arduino IDE supports boards from both Arduino and other vendors. On the IDE, you will have to select the board (board type depends on the micro-controller used) you are connected to.
First, you have to install the Adafruit Feather M0 and ESP8266 boards. This is done by:

1) Navigate to boards manager
* Tools -> Board -> Boards Manager

2) For the M0 board, install: 
* Arduino SAMD Boards
* Adafruit SAMD Boards

3) For the ESP8266 board, install: 
* esp8266 by ESP8266 Community   

4) Select the appropriate board:
* Tools -> Board -> Adafruit Feather M0
* Tools -> Board -> Adafruit Feather HUZZAH ESP8266

## LIBRARIES

Learn how to install and update [libraries](https://www.arduino.cc/en/Guide/Libraries) using the IDE

## FURTHER READING

You can read more about [Adafruit Feather M0 WiFi](https://learn.adafruit.com/adafruit-feather-m0-wifi-atwinc1500?view=all) and [ESP8266](https://learn.adafruit.com/adafruit-feather-huzzah-esp8266?view=all)
for further details.
  
## COMPONENTS OF THE IDE

The IDE consists of the following sections:

1) void setup() method.
* Here, only parts of the code that is meant to be run once are added here. Examples of what should be included in this section are:
```
initialising the serial line/monitor
initialising global variables
initialising the contructors
```

Note: Any variable declared here is local to this method and will not be accessed outside this method

2) void loop() method
* This loops through the code included in this method. It repeats non-stop till there is a re-boot. All parts of the code that are not in the setup section above 
are added here. This method continuously updates variables, both local or global. 

3) Any part of the code outside these two sections are deemed global. This is usually before the setup section. 
This section is used to:

* include libraries
* declare constructors 
* declare global variables
* initialise global variables

## EXAMPLES

1) Blink
* declare a global variable called *led* and initialise same to the actual pin number the LED is connected to(in this case PIN 13)
```
int led = 13; // the pin the LED is connected to
```
* in *setup*, set the LED pin as an output
```
pinMode(led, OUTPUT) // Declare the LED as an output
```
* in *loop*, blink the LED by setting the output HIGH and LOW. To increase visibility of the LED blinking, 
we added a delay of 1s.
```
digitalWrite(led, HIGH)   // Turn the LED on
delay(1000);              // wait for a second
digitalWrite(led, LOW);   // turn the LED off by making the voltage LOW
delay(1000);              // wait for a second
```

2) Voltage measurement
* Since output will be printed on the serial monitor, we initialised the serial line and set the baud rate to 9600bps
```
Serial.begin(9600);
```
* For Adafruit Feather M0, change the bit resolution to 12 (that is 2^12) as arduino has this set at 10 by default
```
analogReadResolution(12);
```
* For ESP8266, which has **only one** analog-to-digital converter pin A0, set pin A0 as input
```
pinMode(A0, INPUT); // set pin A0 as input
```

* Read the volatge and scale it to 5V for Adafruit Feather M0 and 3.3V for ESP8266. Display output on serial console
```
// for esp8266
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3.3V):
  float voltage = sensorValue * (3.3 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);
  
// for feather M0 
  int sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  // print out the value you read:
  Serial.println(voltage);  

```

3) Using library
* In the global space, include the desired library, declare constructor and any other global variables
```
#include "DHT.h"

#define DHTPIN 2          // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22     // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);

```
* in *setup*, initialise serial console and constructor
```
Serial.begin(9600);
dht.begin();
```
* read the temperature, humidity and heat index values and print on the serial console
in *loop* section
```
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
```