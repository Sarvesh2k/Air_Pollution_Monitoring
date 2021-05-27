#define BLYNK_PRINT Serial
 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial s(D6,D5); // setting D6-Rx ping and D5-Tx pin
 
// We should get Auth Token from the Blynk App.
char auth[] = "g3lkjc1kZ4bW4jtN-jRR-4xSYGggwHN8";
int sensorValue;          //the AOUT pin of the CO sensor goes into analog pin A0 of the arduino
float m = -0.6527; //Slope 
float b = 1.30; //Y-Intercept 
float R0 = 21.91; //Sensor Resistance in fresh air from previous code
 
// WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Shrimoorthy";
char pass[] = "Angammal";
 
#define DHTPIN 2          // D3
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
 
// This function sends Arduino's up time every second to Virtual Pin.
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
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
  
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  sensor_volt = sensorValue*(5.0/1023.0); //Convert analog values to voltage 
  RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
  ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
     
  double ppm_log = (log10(ratio)-b)/m; //Get ppm value in linear scale according to the the ratio value  
  double ppm = pow(10, ppm_log); //Convert ppm value to log scale 
 
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  // We can send any value at any time.
  // We cannot send more that 10 values per second.
  Blynk.virtualWrite(V5, t);
  Blynk.virtualWrite(V6, h);
  Blynk.virtualWrite(V7, ppm);
  Blynk.virtualWrite(V8, ppm1);
  Blynk.virtualWrite(V9, ppm2);
}
 
void setup()
{
  // Debug console
  Serial.begin(9600);
  s.begin(57600);
 
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
 
  pinMode(16,INPUT);
  delay(10);
  dht.begin();
 
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
