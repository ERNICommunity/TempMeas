/*
 * wiring-iot-skeleton.cpp
 *
 *  Created on: 19.05.2016
 *      Author: niklausd
 */

#include <WiFiClient.h>
#include <Wire.h>

#ifdef ESP8266
#include <ESP8266WiFi.h>
#endif
// PlatformIO libraries
#include <SerialCommand.h>  // pio lib install 173, lib details see https://github.com/kroimon/Arduino-SerialCommand
#include <ThingSpeak.h>     // pio lib install 550, lib details see https://github.com/mathworks/thingspeak-arduino

// private libraries
#include <Timer.h>
#include <DbgCliNode.h>
#include <DbgCliTopic.h>
#include <DbgTracePort.h>
#include <DbgTraceContext.h>
#include <DbgTraceOut.h>
#include <DbgPrintConsole.h>
#include <DbgTraceLevel.h>
#include <ProductDebug.h>
#include <Adafruit_MCP9808.h>
#include <TM1638.h>
#include <TempMon.h>
#include <MyTempMonAdapter.h>

//-----------------------------------------------------------------------------
// TM1638 8-digit 7-segment LED Display
//-----------------------------------------------------------------------------
#define TM1638_DIO_PIN 12
#define TM1638_CLK_PIN 14
#define TM1638_STB_PIN 16
TM1638* tm1638 = 0;

// I2C Pins in use on Huzzah
#define SDA_PIN 4
#define SCL_PIN 5

SerialCommand* sCmd = 0;

void setup()
{
  //-----------------------------------------------------------------------------
  // ThingSpeak Client
  //-----------------------------------------------------------------------------
  Wire.begin(SDA_PIN, SCL_PIN);

  setupDebugEnv();
#ifdef ESP8266
  //-----------------------------------------------------------------------------
  // ThingSpeak Client
  //-----------------------------------------------------------------------------
  ThingSpeak.begin(*(new WiFiClient()));
#endif

  //-----------------------------------------------------------------------------
  // TM1638 8-digit 7-segment LED Display
  //-----------------------------------------------------------------------------
  tm1638 = new TM1638(TM1638_DIO_PIN, TM1638_CLK_PIN, TM1638_STB_PIN);

  //-----------------------------------------------------------------------------
  // Temperature Monitor
  //-----------------------------------------------------------------------------
  new TempMon(new MyTempMonAdpater(tm1638));
}

void loop()
{
  if (0 != sCmd)
  {
    sCmd->readSerial();     // process serial commands
  }
  yield();                  // process Timers
}
