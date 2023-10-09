#include <WebServer_WT32_ETH01.h>
#include "LAN8720.h"

// Select the IP address according to your local network
IPAddress myIP(192, 168, 1, 232);
IPAddress myGW(192, 168, 1, 1);
IPAddress mySN(255, 255, 255, 0);
// Google DNS Server IP
IPAddress myDNS(8, 8, 8, 8);

LAN8720 lan8720;

void setup()
{   
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  while (!Serial);

  lan8720.init();
  lan8720.config(myIP, myGW, mySN, myDNS);
  lan8720.connect();
}

void loop()
{
  
}