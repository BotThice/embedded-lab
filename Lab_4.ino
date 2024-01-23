#include <WiFi.h>
#include <MQTT.h>

#define PIN1 25
#define PIN2 26
#define PIN7 27
bool isReverse = false;


const char ssid[] = "@JumboPlusIoT";
const char pass[] = "nice123456";

const char mqtt_broker[]="test.mosquitto.org";
const char mqtt_topic[]="group_6/command";
const char mqtt_client_id[]="arduino_group_6"; // must change this string to a unique value
int MQTT_PORT=1883;

int counter=0;

WiFiClient net;
MQTTClient client;

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect(mqtt_client_id)) {  
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe(mqtt_topic);
  // client.unsubscribe("/hello");
}
void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);

  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.
  if(payload == "on"){
    digitalWrite(PIN1,HIGH);
    client.publish("group_6/log", "Motor is on.");
    digitalWrite(PIN2,HIGH);
    digitalWrite(PIN7,LOW);
  }else if(payload == "reverse"){
    if(isReverse){
      digitalWrite(PIN2,HIGH);
      digitalWrite(PIN7,LOW);
      //payload = "";
      client.publish("group_6/log", "Motor is reversed.");
      isReverse = !isReverse;
    }else{
      digitalWrite(PIN2,LOW);
      digitalWrite(PIN7,HIGH);
      //payload = "";
      client.publish("group_6/log", "Motor is reversed.");
      isReverse = !isReverse;
    }
  }else if(payload == "off"){
    digitalWrite(PIN1,LOW);
    client.publish("group_6/log", "Motor is off.");
  }
}

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  
  pinMode(PIN1,OUTPUT);
  pinMode(PIN2,OUTPUT);
  pinMode(PIN7,OUTPUT);
  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  client.begin(mqtt_broker, MQTT_PORT, net);
  client.onMessage(messageReceived);

  digitalWrite(PIN1,LOW);
  digitalWrite(PIN2,LOW);
  digitalWrite(PIN7,LOW);
  

  connect();
}


void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  // not that we don't use delay() because we need to keep calling the client.loop()
  // to keep the connection alive
  

  // if (millis() - lastMillis > 2000) {
  //   lastMillis = millis();
  //   client.publish(mqtt_topic, "Counter = " + String(counter++));
  // }
}


// #include <WiFi.h>

// //Set to your network SSID/Password
// const char ssid[] = "@JumboPlusIoT";
// const char pass[] = "nice123456";

// WiFiClient net;  // creat the wifi object

// void connect() {
//   Serial.print("checking wifi...");
//   while (WiFi.status() != WL_CONNECTED) {
//     Serial.print(".");
//     delay(1000);
//   }

//   Serial.println("\nwifi connected!");
// }

// void setup() {

//   Serial.begin(9600);
//   WiFi.begin(ssid, pass);

//   connect();
// }

// void loop() {
// // Your main code goes here
// }


// print Mac address

// #ifdef ESP32
//   #include <WiFi.h>
// #else
//   #include <ESP8266WiFi.h>
// #endif

// void setup(){
//   Serial.begin(9600);
//   Serial.println();
//   Serial.print("ESP Board MAC Address:  ");
//   Serial.println(WiFi.macAddress());
// }
 
// void loop(){

// }