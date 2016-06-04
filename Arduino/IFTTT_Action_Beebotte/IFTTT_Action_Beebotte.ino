// Reference
// https://beebotte.com/docs/mqtt

#include <ESP8266WiFi.h>

// Expand the max packet size from PubSubClient's default (i.e. 128 bytes)
#define MQTT_MAX_PACKET_SIZE 1024
#include <PubSubClient.h>

#include <ArduinoJson.h>

#include "config.h"

// Constants
const char clientID[] = "ESP8266";  // Your client ID
const char host[] = "mqtt.beebotte.com";  // The Beebotte server
const char ledPin = 14;

// Variables
WiFiClient wifiClient;
PubSubClient client(host, 1883, wifiClient);
char buffer[MQTT_MAX_PACKET_SIZE];  // The buffer to receive a message

// Function prototypes
void messageReceived(const String message);
void callback(char topic[], byte payload[], unsigned int length);
void printMqttConnectionState(const int state);

void setup() {
  Serial.begin(115200);
  Serial.println();

  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.print("connecting to ");
    Serial.print(ssid);
    Serial.println("...");
    WiFi.begin(ssid, password);

    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
      Serial.println("failed to connect");
      delay(5000);
      return;
    } else {
      Serial.print("WiFi connected: ");
      Serial.println(WiFi.localIP());
    }
  }

  // If the client is not connected to the server
  if (!client.connected()) {
    // Try connecting to the server
    String username = "token:";
    username += channelToken;
    client.connect(clientID, username.c_str(), NULL);

    printMqttConnectionState(client.state());
    if (client.connected()) {
      client.setCallback(callback);
      client.subscribe(topic);
    } else {
      delay(5000);
    }
  } else {
    // This should be called regularly to allow the client
    // to process incoming messages
    // and maintain its connection to the server
    client.loop();
  }
}

// Edit for your application
void messageReceived(const String message) {
  Serial.print("received: ");
  Serial.println(message);

  digitalWrite(ledPin, HIGH);
  delay(250);
  digitalWrite(ledPin, LOW);

  // Do something with the string
  // e.g.
  // if (message.equals("Something")) {
  //
  // }
  // if (message.startsWith("Something")) {
  //
  // }
  // See also
  // https://www.arduino.cc/en/Tutorial/StringComparisonOperators
}

// Handle a received message
void callback(char topic[], byte payload[], unsigned int length) {
  snprintf(buffer, sizeof(buffer), "%s", payload);

  // Decode the received message in JSON format
  StaticJsonBuffer<MQTT_MAX_PACKET_SIZE> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(buffer);

  if (!root.success()) {
    Serial.println("parseObject() failed");
    return;
  }

  const char* parsedPayload = root["data"];
  if (parsedPayload != NULL) {
    messageReceived(String(parsedPayload));
  }
}

// Print MQTT connection state to serial
void printMqttConnectionState(const int state) {
  switch (state) {
    case -4:
      Serial.println("MQTT_CONNECTION_TIMEOUT - the server didn't respond within the keepalive time");
      break;
    case -3 :
      Serial.println("MQTT_CONNECTION_LOST - the network connection was broken");
      break;
    case -2 :
      Serial.println("MQTT_CONNECT_FAILED - the network connection failed");
      break;
    case -1 :
      Serial.println("MQTT_DISCONNECTED - the client is disconnected cleanly");
      break;
    case 0 :
      Serial.println("MQTT_CONNECTED - the cient is connected");
      break;
    case 1 :
      Serial.println("MQTT_CONNECT_BAD_PROTOCOL - the server doesn't support the requested version of MQTT");
      break;
    case 2 :
      Serial.println("MQTT_CONNECT_BAD_CLIENT_ID - the server rejected the client identifier");
      break;
    case 3 :
      Serial.println("MQTT_CONNECT_UNAVAILABLE - the server was unable to accept the connection");
      break;
    case 4 :
      Serial.println("MQTT_CONNECT_BAD_CREDENTIALS - the username / password were rejected");
      break;
    case 5 :
      Serial.println("MQTT_CONNECT_UNAUTHORIZED - the client was not authorized to connect");
      break;
    default:
      break;
  }
}

