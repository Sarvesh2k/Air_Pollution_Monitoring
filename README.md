# IoT Based Air Pollution Monitoring System

The level of pollution is increasing rapidly due to factors like industrialization, urbanization, increase in population and vehicle use which can affect human health. Quality of the air is the most important factor that directly causes diseases and decreases the quality of life. Currently, the monitoring of air quality levels is achieved by placing sensors in various locations and the sensors alert if the pollution levels exceed the threshold level. However, there hardly exists a mobile solution wherein an individual can contribute to the pollution level checking from the convenience of their homes. Moreover, solutions for forecasting gas and particulate matter levels are location specific and require expensive training data (Meteorological data, wind speeds, etc.) which is unavailable in the reach of the common people.

Therefore, this project aims to collect data about the concentration of NO2, CO2, CO, as well as temperature and humidity via a compact and affordable solution, and host its visualization on a website as well as on a mobile app. We calculate the Air Quality Index (AQI) and also predict their future concentrations using machine learning approaches. The future concentration levels that are being predicted is aimed to provide maximum accuracy based on the regions in which the system is placed. The proposed device can be placed anywhere in the user’s home and the user can obtain real time data of the pollution levels in their immediate locality. The accuracy of the prediction model can be improved based on the data sensed from the user’s surroundings.

This project was a team project done as a part of the programme elective coursework "Internet of Things" offered by the Electronics and Communication Department of the National Institute of Technology, Tiruchirappalli.


## Hardware and Software Requirements

### Components, Sensors, and Boards Required

- To Measure Concentration of Carbon Monoxide in ppm – [MQ7 Sensor](https://www.sparkfun.com/products/9403)
- To Measure Concentration of Methane, Butane and LPG in ppm – [MQ 2 sensor](https://www.sparkfun.com/products/17049)
- To measure General Air Quality in ppm (CO2, NO2, NOx) – [MQ135 Sensor](https://quartzcomponents.com/products/mq-135-air-quality-gas-sensor-module)
- [Node MCU](https://www.nodemcu.com/index_en.html)
- [Arudino UNO](https://store-usa.arduino.cc/products/arduino-uno-rev3/)

### Software Requirements

- Arduino IDE 1.6.13 – To code the Arduino UNO and the Node MCU
- HTML, CSS, Javascript – For designing the website
- Google Collaboratory – For model training and Prediction
- [Google Firebase](https://firebase.google.com/) – For hosting the website on the cloud
- [Thingspeak IoT Cloud](https://thingspeak.com/) – For reading and visualizing sensor values
- [Blynk App](https://blynk.io/) – Mobile App for reading sensor value


## The Prototype Designed

<div align="center">
<img src="https://github.com/Sarvesh2k/Air_Pollution_Monitoring/blob/main/pic1.jpg" width="650">
</div>
<p align="center"><i>Top View</i></p>


<div align="center">
<img src="https://github.com/Sarvesh2k/Air_Pollution_Monitoring/blob/main/pic2.jpg" width="650">
</div>
<p align="center"><i>Side View</i></p>


<div align="center">
<img src="https://github.com/Sarvesh2k/Air_Pollution_Monitoring/blob/main/pic3.JPG" width="650">
</div>
<p align="center"><i>Description of Component</i></p>


## Demo Video (Click to Watch)

[![Watch the video](https://img.youtube.com/vi/z_8ENrIU1NQ/maxresdefault.jpg)](https://youtu.be/z_8ENrIU1NQ)


## How to Use

### Hardware Code

Refer to the `Project Report.pdf` file to understand how the code works and how to implement it. The Arduino files have been provided in the `Hardware Codes` folder. Make sure to install the following libraries in the Arduino IDE:

- ArduinoJSON Library
- NodeMCU Library (to provide support for coding the NodeMCU board in the Arduino IDE)

### Analytics

Refer to the `Project Report.pdf` file to understand how the code works. the Notebooks have been provided in the `Analytics` folder.
NOTE: Download the data.csv folder and load the file before running the code. 

### Website Frontend

In addition, the source code for the website has also been provided to show how the real time data can be monitored in a cloud hosted website. It can be viewed in the `Website` folder. For details on hosting a website in google firebase, it has been well documented in the [firebase website](https://firebase.google.com/docs) itself.


## Quick Links

- [Thingspeak IoT Dashboard](https://thingspeak.com/channels/1371486)
- [The hosted website](https://air-pollution-98b87.web.app/Air_pollution0.html)

NOTE: The the prototype isn't powered on currently, and hence you won't be able to view any readings in real time for now.


### Contributors

- V. Shri Sarvesh
- Adithya Sineesh
- Balaji K S
