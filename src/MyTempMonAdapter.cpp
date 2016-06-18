/*
 * MyTempMonAdapter.cpp
 *
 *  Created on: 16.06.2016
 *      Author: niklausd
 */

#include <MyTempMonAdapter.h>
#include <ThingSpeak.h>
#include <DbgTracePort.h>
#include <DbgTraceLevel.h>

MyTempMonAdpater::MyTempMonAdpater()
: m_trPort(new DbgTrace_Port("temp", DbgTrace_Level::error))
{ }

void MyTempMonAdpater::NotifyTempChg(float temp)
{
  ThingSpeak.setField(1, temp);
  int status = ThingSpeak.writeFields(55398, "LMC59PNW77U4H01P");
  DbgTrace_Level::Level trLevel = DbgTrace_Level::error;
  if (status == 200)
  {
    trLevel = DbgTrace_Level::debug;
  }
  TR_PRINT_STR(m_trPort, trLevel, thingSpeakStatusString(status))
}

const char* MyTempMonAdpater::thingSpeakStatusString(int status)
{
  return ((status ==  200) ? "OK / Success                                                                           " :
          (status ==  404) ? "Incorrect API key (or invalid ThingSpeak server address)                               " :
          (status == -101) ? "Value is out of range or string is too long (> 255 characters)                         " :
          (status == -201) ? "Invalid field number specified                                                         " :
          (status == -210) ? "setField() was not called before writeFields()                                         " :
          (status == -301) ? "Failed to connect to ThingSpeak                                                        " :
          (status == -302) ? "Unexpected failure during write to ThingSpeak                                          " :
          (status == -303) ? "Unable to parse response                                                               " :
          (status == -304) ? "Timeout waiting for server to respond                                                  " :
          (status == -401) ? "Point was not inserted (most probable cause is the rate limit of once every 15 seconds)" : "UNKNOWN");
}
