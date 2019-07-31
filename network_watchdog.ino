#include <SPI.h>
#include <WiFiNINA.h>

#include "arduino_secrets.h" 
///////store your sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;        // your SSID name
char pass[] = SECRET_PASS;    // your SSID password (use for WPA, or use as key for WEP)                     
int status = WL_IDLE_STATUS;     // WiFi radio's status

//Initialize digial out pin for relay
int relay = 7;
int led = 13;
int off_counter = 0;

// Specify IP address or hostname
String hostName = "www.google.com";
int pingResult;
int resetCounter = 0;

void setup() {
  // Initialize serial and wait for port to open before sending data:
  Serial.begin(9600);
  // Initialize relay pin
  pinMode(relay,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);
  
  // check for the WiFi module:
  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    // break
    while (true);
  }
  
  // attempt to connect to WiFi network:
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    for (int i = 0; i <= 75; i++) {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(i);
    digitalWrite(LED_BUILTIN,LOW);
    delay(i);
    }
    
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  {
  // a connection has been established, print a message:
  Serial.println("You're connected to the network");
  }
  }
void loop() {
  Serial.print("Pinging ");
  Serial.print(hostName);
  Serial.print(": ");

  pingResult = WiFi.ping(hostName);

  if (pingResult >= 0) {
    off_counter = 0;
    Serial.print("\n");
    Serial.print("Still connected");
    Serial.print("\n");
    digitalWrite(LED_BUILTIN,HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN,LOW);
    delay(250);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN,LOW);
    delay(250);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN,LOW);
    digitalWrite(LED_BUILTIN,HIGH);
  } else {
    Serial.print("FAILED! Error code: ");
    Serial.println(pingResult);
    
    int x = 1;
    for (int i = 0; i <= 100; i++) {
    digitalWrite(LED_BUILTIN,HIGH);
    delay(i);
    digitalWrite(LED_BUILTIN,LOW);
    delay(i);{
    digitalWrite(led, HIGH);
    off_counter = off_counter + 1;
    Serial.print("counter is at ");
    Serial.print(off_counter);
    if (off_counter > 3){
    Serial.print('\n');
    Serial.print("---------------------");
    Serial.print("resetting router");
    Serial.print('\n');
    Serial.print("---------------------");
    Serial.print('\n');    
    digitalWrite(relay,HIGH);
    delay(3000);
    digitalWrite(relay,LOW);
    WiFi.begin(ssid, pass);} 
  }
  delay(35000);
}
}
}
