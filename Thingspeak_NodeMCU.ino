#include <DHT.h>
#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial s(D6,D5); // setting D6-Rx ping and D5-Tx pin
 
#define DHTPIN 2          //DHT11 is connected to GPIO Pin 2
int sensorValue;          //the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
float m = -0.6527; //Slope 
float b = 1.30; //Y-Intercept 
float R0 = 21.91; //Sensor Resistance in fresh air from previous code

String apiKey = "Your API key here";     //  Enter your Write API key from ThingSpeak
const char* ssid =  "";     // Enter your WiFi Network's SSID
const char* pass =  ""; // Enter your WiFi Network's Password
const char* server = "api.thingspeak.com";
 
float humi;
float temp;
 
DHT dht(DHTPIN, DHT11);
WiFiClient client;
 
void setup() 
{
       Serial.begin(115200);
       s.begin(57600);
       delay(10);
       dht.begin();

       pinMode(16,INPUT);
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(100);
            Serial.print("*");
     }
      Serial.println("");
      Serial.println("***WiFi connected***");
      Serial.println(" ");
 
}
 
void loop() 
{
      s.write("s");
      StaticJsonBuffer<1000> jsonBuffer;
      JsonObject& root = jsonBuffer.parseObject(s);

      if (root == JsonObject::invalid())
      {
        return;
      }

      Serial.println("***JSON received and parsed***");
      root.prettyPrintTo(Serial);
      float ppm1 = root["ppm1"];
      float ppm2 = root["ppm2"];
      Serial.println(" ");
       
      float sensor_volt; //Define variable for sensor voltage 
      float RS_gas; //Define variable for sensor resistance  
      float ratio; //Define variable for ratio
      int sensorValue = analogRead(0); //Read analog values of sensor  
      
      humi = dht.readHumidity();
      temp = dht.readTemperature();

      sensor_volt = sensorValue*(5.0/1023.0); //Convert analog values to voltage 
      RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
      ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
      
      double ppm_log = (log10(ratio)-b)/m; //Get ppm value in linear scale according to the the ratio value  
      double ppm = pow(10, ppm_log); //Convert ppm value to log scale 
      delay(2000);
 
      if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
      {  
       String sendData = apiKey+"&field1="+String(temp)+"&field2="+String(humi)+"&field3="+String(ppm)+"&field4="+String(ppm1)+"&field5="+String(ppm2)+"\r\n\r\n"; 
       
       //Serial.println(sendData);

       client.print("POST /update HTTP/1.1\n");
       client.print("Host: api.thingspeak.com\n");
       client.print("Connection: close\n");
       client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
       client.print("Content-Type: application/x-www-form-urlencoded\n");
       client.print("Content-Length: ");
       client.print(sendData.length());
       client.print("\n\n");
       client.print(sendData);

       Serial.print("Temperature: ");
       Serial.print(temp);
       Serial.print(" deg. C Humidity: ");
       Serial.print(humi);
       Serial.println(" %");
       Serial.print("CO: ");
       Serial.print(ppm, 3);  // prints the value read
       Serial.println(" ppm");
       Serial.print("General Air Quality: ");
       Serial.print(ppm1, 3);  // prints the value read
       Serial.println(" ppm");
       Serial.print("CH4: ");
       Serial.print(ppm2, 3);  // prints the value read
       Serial.println(" ppm");
       Serial.println("Connecting to Thingspeak.");
       }
      
      client.stop();

      Serial.println("Sending....");
  
 delay(10000);
}
