void setup() {
  Serial.begin(9600); //Baud rate 
  pinMode(A1,INPUT);
}
 
void loop() { 
  float sensor_volt; //Define variable for sensor voltage 
  float RS_air; //Define variable for sensor resistance
  float R0; //Define variable for R0
  float sensorValue=0.0; //Define variable for analog readings 
  for(int x = 0 ; x < 500 ; x++) //Start for loop 
  {
    sensorValue = sensorValue + analogRead(A1); //Add analog values of sensor 500 times 
  }
  sensorValue = sensorValue/500.0; //Take average of readings
  Serial.print("Average = ");
  Serial.println(sensorValue);
  sensor_volt = sensorValue*(5.0/1023.0); //Convert average to voltage 
  RS_air = ((5.0*10.0)/sensor_volt)-10.0; //Calculate RS in fresh air 
  R0 = RS_air/27; //Calculate R0 
  Serial.print("Sensor RAW value = ");
  Serial.println(analogRead(A1));
  Serial.print("R0 = "); //Display "R0"
  Serial.println(R0); //Display value of R0 
  Serial.println(analogRead(A1));
  delay(1000); //Wait 1 second 
 
}
