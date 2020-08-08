
#include "TDS.h"
#include "EthShield.h"
#include "Ping.h"
#include "Pump.h"
#include "Humidity.h"
#include "Parser.h"

void setup() {
  ethSetup();
  tdsSetup();
  pingSetup();
  humSetup();
//  pumpSetup();
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
}

void loop() {

  if (client.connect(server, 80)) {   
    tdsLoop();
    pingLoop();
    humLoop();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }

  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }
  _delay(5000);
}
