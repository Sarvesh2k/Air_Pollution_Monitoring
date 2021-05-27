#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(5,6); // setting 5-Rx pin and 6-Tx pin

int gas_sensor = A0; //Sensor pin 
float m = -0.3376; //Slope 
float b = 0.7165; //Y-Intercept 
float R0 = 2.82; //Sensor Resistance in fresh air from previous code

int CH4_sensor = A1; //Sensor pin 
float m1 = -0.3720; //Slope 
float b1 = 1.3492; //Y-Intercept 
float R01 = 1.45; //Sensor Resistance

void setup() {
  
 
  Serial.begin(9600);      // PC to Arduino Serial Monitor
  pinMode(gas_sensor, INPUT);
  pinMode(CH4_sensor,INPUT);
  pinMode(A2,INPUT); //For DHT Sensor
  s.begin(57600); // Arduino UNO to Node MCU serial communication
 } 

 StaticJsonBuffer<500> jsonBuffer;
 JsonObject& root = jsonBuffer.createObject();

void loop() { 
  float sensor_volt; //Define variable for sensor voltage 
  float RS_gas; //Define variable for sensor resistance  
  float ratio; //Define variable for ratio
  float sensorValue = analogRead(gas_sensor); //Read analog values of sensor  
  sensor_volt = sensorValue*(5.0/1023.0); //Convert analog values to voltage 
    RS_gas = ((5.0*10.0)/sensor_volt)-10.0; //Get value of RS in a gas
  ratio = RS_gas/R0;  // Get ratio RS_gas/RS_air
  double ppm_log = (log10(ratio)-b)/m; //Get ppm value in linear scale according to the the ratio value  
  double ppm = pow(10, ppm_log); //Convert ppm value to log scale 
  Serial.print("General Air Quality PPM = ");
  Serial.println(ppm);
  

  float sensor_volt1; //Define variable for sensor voltage 
  float RS_gas1; //Define variable for sensor resistance  
  float ratio1; //Define variable for ratio
  float sensorValue1 = analogRead(CH4_sensor); //Read analog values of sensor  
  sensor_volt1 = sensorValue1*(5.0/1023.0); //Convert analog values to voltage 
  RS_gas1 = ((5.0*10.0)/sensor_volt1)-10.0; //Get value of RS in a gas
  ratio1 = RS_gas1/R01;  // Get ratio RS_gas/RS_air
  double ppm_log1 = (log10(ratio1)-b1)/m1; //Get ppm value in linear scale according to the the ratio value  
  double ppm1 = pow(10, ppm_log1); //Convert ppm value to log scale 
  Serial.print("CH4 PPM = ");
  Serial.println(ppm1);

  root["ppm1"] = ppm;
  root["ppm2"] = ppm1;

  if(s.available()>0)
  {
    root.printTo(s);
  }

  delay(4000);                            // wait for 4 sec
 }
