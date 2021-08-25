# IoT Based Air Pollution Monitoring System

The level of pollution is increasing rapidly due to factors like industrialization, urbanization, increase in population and vehicle use which can affect human health. Quality of the air is the most important factor that directly causes diseases and decreases the quality of life. Currently, the monitoring of air quality levels is achieved by placing sensors in various locations and the sensors alert if the pollution levels exceed the threshold level. However, there hardly exists a mobile solution wherein an individual can contribute to the pollution level checking from the convenience of their homes. Moreover, solutions for forecasting gas and particulate matter levels are location specific and require expensive training data (Meteorological data, wind speeds, etc.) which is unavailable in the reach of the common people.

Therefore, this project aims to collect data about the concentration of NO2, CO2, CO, as well as temperature and humidity via a compact and affordable solution, and host its visualization on a website as well as on a mobile app. We calculate the Air Quality Index (AQI) and also predict their future concentrations using machine learning approaches. The future concentration levels that are being predicted is aimed to provide maximum accuracy based on the regions in which the system is placed. The proposed device can be placed anywhere in the user’s home and the user can obtain real time data of the pollution levels in their immediate locality. The accuracy of the prediction model can be improved based on the data sensed from the user’s surroundings.

This project was a team project done as a part of the programme elective coursework "Internet of Things" offered by the Electronics and Communication Department of the National Institute of Technology, Tiruchirappalli.

## Hardware and Software Requirements

### Components, Sensors, and Boards Required

- To Measure Concentration of Carbon Monoxide in ppm – MQ7 Sensor
- To Measure Concentration of Methane, Butane and LPG in ppm – MQ 2 sensor
- To measure General Air Quality in ppm (CO2, NO2, NOx) – MQ135 Sensor
- Node MCU
- Arudino UNO

### Software Requirements

- Arduino IDE 1.6.13 – To code the Arduino UNO and the Node MCU
- HTML, CSS, Javascript – For designing the website
- Google Collaboratory – For model training and Prediction
- Google Firebase – For hosting the website on the cloud
- Thingspeak IoT Cloud – For reading and visualizing sensor values
- Blynk App – Mobile App for reading sensor value

## The Prototype Designed

Top view:

<div align="center">
<img src="https://github.com/Sarvesh2k/NES_Emulator/blob/master/pic1.jpg" width="450">
</div>

Side view:

<div align="center">
<img src="https://github.com/Sarvesh2k/NES_Emulator/blob/master/pic1.jpg" width="450">
</div>

Component Description:

<div align="center">
<img src="https://github.com/Sarvesh2k/NES_Emulator/blob/master/pic1.jpg" width="450">
</div>

## How to Use:

Refer to the `project report` file to understand how the code works and how to implement it. In addition, the source code for the website has also been provided to show how the real time data can be monitored in a cloud hosted website.
