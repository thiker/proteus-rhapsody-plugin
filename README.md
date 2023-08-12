The ProteusDemo project contains an example with a connection to MQTT.

1. The paho C mqtt library needs to be built for win32.
2. Copy the mqtt library to ..\..\DefaultComponent\Eclipse-Paho-MQTT-C-1.3.12-win32
3. on the default component set the libraries path to: ..\..\DefaultComponent\Eclipse-Paho-MQTT-C-1.3.12-win32\lib\paho-mqtt3c.lib
4. on the default component set the include path to: ..\..\DefaultComponent\Eclipse-Paho-MQTT-C-1.3.12-win32\lib\paho-mqtt3c.lib
5. for standard headers set MQTTClient.h to incldue the mqtt on all files.

For the plugin:
1. Change the HEP file so that all absolute paths point are adapted to the directories on your system.
2. Add the plugin to your ibm rhapsody project.
2.1 Right click to get features of the project.
2.2 Go to properties and filter for helpersfile. Then browse to the Proteus plugin's helpers file and select it.
