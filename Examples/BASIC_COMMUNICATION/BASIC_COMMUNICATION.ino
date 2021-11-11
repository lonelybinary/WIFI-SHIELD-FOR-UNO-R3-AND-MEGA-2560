#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11);  //RX,TX

void setup()
{
  // communication with the host computer
  Serial.begin(9600);     
  
  // Start the software serial for communication with the ESP8266
  // by default, ESP8266 uses 115200 bps which is too fast for arduino softwareserial to handle
  // The rates must be changed to 9600bps
  // AT+UART?  - enquire current settings
  // AT+UART=9600,8,1,0,1 - Change ESP8266 to 9600 bps
  // mySerial.begin(115200);
  mySerial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB
  }
  Serial.println("");
  Serial.println("Remember to to set Both NL & CR and 9600bps Rate in the serial monitor.");
  Serial.println("Ready");
  Serial.println("");
}

void loop()
{
  // listen for communication from the ESP8266 and then write it to the serial monitor
  if ( mySerial.available() )   {
    Serial.write( mySerial.read() );
  }

  // listen for user input and send it to the ESP8266
  if ( Serial.available() )       {
    mySerial.write( Serial.read() );
  }
}
