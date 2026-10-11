/* 
 * Project myProject
 * Author: Your Name
 * Date: 
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);
SerialLogHandler logHandler(LOG_LEVEL_INFO);

uint16_t pin1 = D7;
String needAlert = "no";
Ledger deviceConfig;
int delayRate = 1000;

void regSync(Ledger ledger);    

// setup() runs once, when the device is first turned on
void setup() {
 
  pinMode(pin1, OUTPUT);

  deviceConfig = Particle.ledger("cloud-to-photon");   //Name of the ledger in the particle console
  deviceConfig.onSync(regSync);

  regSync(deviceConfig);

}

void loop() {

 /* 
    digitalWrite(pin1, HIGH);
    delay(delayRate);
    Particle.publish("light", "on", PRIVATE);
    digitalWrite(pin1, LOW);
    delay(delayRate);
    Particle.publish("light", "off", PRIVATE);
*/
  if (needAlert == "yes") {
    digitalWrite(pin1, HIGH);
    Particle.publish("tempCheck", "TEMPERATURE OUT OF RANGE. CHECK DEVICE", PRIVATE);
    delay(delayRate);
    } else {
    digitalWrite(pin1, LOW);
    Particle.publish("tempCheck", "Temperature in range", PRIVATE);
    delay(delayRate);
  }


}

void regSync(Ledger ledger)
{

    LedgerData data = deviceConfig.get();
    needAlert = data["needAlert"].asString();   
    //delayRate = data["delayRate"].asInt();                       
}