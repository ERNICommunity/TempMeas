/*
 * TempMon.cpp
 *
 *  Created on: 16.06.2016
 *      Author: scan
 */

#include "TempMon.h"
#include "Timer.h"
#include "TempMeasTimerAdapter.h"
#include "ITempMonAdapter.h"
#include "Adafruit_MCP9808.h"

TempMon::TempMon(ITempMonAdapter* tempMonAdapter) :
    m_timer(new Timer(new TempMeasTimerAdapter(this))), m_tempSensor(new Adafruit_MCP9808()), m_adapter(tempMonAdapter)
{
  m_tempSensor->begin(0x18);
}

TempMon::~TempMon()
{

}

void TempMon::measTemp()
{
  if (0 != m_adapter && 0 != m_tempSensor)
  {
    m_adapter->NotifyTempChg(m_tempSensor->readTempC());
  }
}

