
 /*
 * Project Title: Remote and wifi Controlled Lights using ESP8266 module\
 * Platform: *Esp8266 wifi module
 * Autor: Anwar Hussein
 * Date Created:1/4/2019
 * Last Updated: 1/4/2019
 */

/*
  MQTT-to-UART Bridge
  This code is meant to encapsulate all of the necessary protocols and resources for MQTT and
  leave it on the ESP8266. Connected over a simple UART connection, this can allow your project to quickly
  talk over the internet without the need for complicating your design.

  Commands:
  $Subscribe        SYNTAX: "$Topic\n"
  #Publish          SYNTAX: "#Topic Payload\n"
  !ReceivedMessage  SYNTAX: "!Topic: Message\n"
  ~Unsubscribe      SYNTAX: "~Topic\n"
*/
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
// Update these with values suitable for your network.
const char* ssid = "HOME-13D6-2.4";
const char* password =  "AA7A4NAR3DCNAH9A";
const char* mqtt_server = "10.0.0.115";
const int mqttPort = 1883;  
const char* mqttUser = "esp1";
const char* mqttPassword = "pass1";
/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

long lastReconnectAttempt = 0;

WiFiClient espClient;
PubSubClient mqttClient(espClient);

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
//  WiFi.setSleepMode(WIFI_NONE_SLEEP); // Suggested to help with led flickering issue
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


boolean reconnect() {
  Serial.println("Reconnecting to mqtt");
  if (mqttClient.connect("woodstoveClient")) {
    // Once connected, publish an announcement...
    mqttClient.publish("home/Living Room/Woodstove/state","\"online\"");
  }
  return mqttClient.connected();
}


void setup() {
  Serial.begin(115200);
  
  Serial.println("Starting up");
  /* ESP8266 Stuff */
  setup_wifi();


  Serial.println("Connect to mqtt server");
  mqttClient.setServer(mqtt_server, 1883);
//  mqttClient.setCallback(mqttCallback);


  lastReconnectAttempt = 0;
  /* End ESP8266 Stuff */
  
  Serial.println("Setup done");
}


void loop() {
  if (!mqttClient.connected()) {
    Serial.println("mqtt NOT connected");
    long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      lastReconnectAttempt = now;
      // Attempt to reconnect
      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    // Client connected
    mqttClient.loop();
  }

}
