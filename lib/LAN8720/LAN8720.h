#ifndef LAN8720_H
#define LAN8720_H

#define DEBUG_ETHERNET_WEBSERVER_PORT       Serial
// Debug Level from 0 to 4
#define _ETHERNET_WEBSERVER_LOGLEVEL_       3

#include "Arduino.h"
#include <WebServer_WT32_ETH01.h>

class LAN8720
{
  private:
    // Select the IP address according to your local network
    IPAddress myIP;
    IPAddress myGW;
    IPAddress mySN;

    // Google DNS Server IP
    IPAddress myDNS;

  public:

    LAN8720()
    {
    }

    void init()
    {
      Serial.print("\nStarting HelloServer on " + String(ARDUINO_BOARD));
      Serial.println(" with " + String(SHIELD_TYPE));
      Serial.println(WEBSERVER_WT32_ETH01_VERSION);

      // To be called before ETH.begin()
      WT32_ETH01_onEvent();

      ETH.begin(ETH_PHY_ADDR, ETH_PHY_POWER);
    }

    void config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1)
    {
      myIP = local_ip;
      myGW = gateway;
      mySN = subnet;
      myDNS = dns1;
      // Static IP, leave without this line to get IP via DHCP
      //bool config(IPAddress local_ip, IPAddress gateway, IPAddress subnet, IPAddress dns1 = 0, IPAddress dns2 = 0);
      ETH.config(myIP, myGW, mySN, myDNS);
    }

    void connect()
    {
      WT32_ETH01_waitForConnect();

      Serial.print(F("HTTP EthernetWebServer is @ IP : "));
      Serial.println(ETH.localIP());
    }
};

#endif