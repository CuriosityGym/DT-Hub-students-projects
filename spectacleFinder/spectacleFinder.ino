#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "756b4915924d4d59883a0ce4a2107286";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Spectacle Finder";
char pass[] = "abc@1234";
int pinValue=0;
int ledPin = 2;
// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
BLYNK_WRITE(V1)
{
   pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable

  // process received value
}
void loop()
{
  Blynk.run();
  if(pinValue == 0) 
    {
      digitalWrite(ledPin, LOW);
    }
  if(pinValue == 1) 
    {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval) {
         // save the last time you blinked the LED
         previousMillis = currentMillis;

         // if the LED is off turn it on and vice-versa:
         if (ledState == LOW) {
            ledState = HIGH;
           } 
         else {
           ledState = LOW;
         }

       // set the LED with the ledState of the variable:
       digitalWrite(ledPin, ledState);
      } 
    }    
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
