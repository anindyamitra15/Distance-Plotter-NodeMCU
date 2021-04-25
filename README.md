# Distance-Plotter-NodeMCU
This is a distance plotter using ESP8266 and ultrasonic sensor HC-SR04

### Follow this breadboard schematic
![NodeMCU Distance Plotter](https://user-images.githubusercontent.com/55695557/105572401-e2f58080-5d7c-11eb-88bd-6e3368d5c2c8.png)

### Use this diagram for NodeMCU GPIOs to use with Arduino IDE
![NodeMCU GPIOs](https://user-images.githubusercontent.com/55695557/105572448-2bad3980-5d7d-11eb-80c7-3420dcf9717b.png)

├── Clone this repository <br>
├── Head over to the `Distance_Plotter_Node_MCU` folder <br>
├── Open the .ino file with Arduino <br>
├── Set the board as generic ESP8266 <br>
└── Upload <br>

### Follow the procedure below to setup ESP8266 (nodeMCU) for your Arduino
Use generic ESP8266 module Board
<br> Go to File -> Preferences <br> <br>
![image](https://user-images.githubusercontent.com/55695557/105572502-8777c280-5d7d-11eb-8e78-e0c0d0c96d9d.png) <br>
And paste the link: `https://arduino.esp8266.com/stable/package_esp8266com_index.json` in Additional Board Manager URLs <br>
![image](https://user-images.githubusercontent.com/55695557/105572519-a413fa80-5d7d-11eb-8d8a-53d593645f51.png) <br>
<br> Go to Tools -> Board -> Board Manager -> Search for `ESP8266` and Download that package <br>
![image](https://user-images.githubusercontent.com/55695557/105572665-8e530500-5d7e-11eb-88f6-ac3942e6513b.png) <br>

### Upload the code
Keep the USB connected to NodeMCU to access the serial monitor in case you want to debug!
Type `http://mcu-node.local` on your browser, if you did everything properly, you will see something like this:
![image](https://user-images.githubusercontent.com/55695557/105572755-26e98500-5d7f-11eb-9d91-263d1d95b59d.png) <br>
