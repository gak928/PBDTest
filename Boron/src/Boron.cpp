/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

#include "Particle.h"
SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);

//set global
int tempThres = 0;
String location = "your mom's house";
Ledger deviceConfig;

//Forward declarations
void regSync(Ledger ledger);                   

// setup() runs once, when the device is first turned on
void setup() {
  // Put initialization like pinMode and begin functions here
  deviceConfig = Particle.ledger("cloud-to-boron");   //Name of the ledger in the particle console
  deviceConfig.onSync(regSync);

  regSync(deviceConfig);
  
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  if (Particle.connected()) {
        float temperature = 50.0;
        float humidity = 90.0;
      //  bool isInThresh = false; //set to false to force a check if something funny happens
        //TODO should this be global?
        //ANS no, this logic is moved to LOGIC functs, rather than being listed here
/*
        if (temperature > tempThres) {
            isInThresh = false;
        } else {
            isInThresh = true;
        }
*/
        String data = "[" + String(temperature) + "," + String(humidity) + "," + String(tempThres) + ",\"" + location + "\"" + "]";
    
        Particle.publish("telemetry", data, PRIVATE);
        digitalWrite(D7, !digitalRead(D7));
    }

    delay(60000);
    //TODO make config
}
  
void regSync(Ledger ledger)
{
    LedgerData data = deviceConfig.get();
    location = data["Location"].asString();
    tempThres = data["TempThresh"].asInt();                                  
}