/*
 * TempMon.cpp
 *
 *  Created on: 16.06.2016
 *      Author: scan
 */

#include "TempMon.h"
#include "Timer.h"
#include "Adafruit_MCP9808.h"

//-----------------------------------------------------------------------------

class TempMeasTimerAdapter : public TimerAdapter
{
private:
  TempMon* m_tempMon;
public:
  TempMeasTimerAdapter(TempMon* tempMon)
  : m_tempMon(tempMon)
  { }

  virtual ~TempMeasTimerAdapter() { }

  void timeExpired()
  {
    if(0 != m_tempMon)
    {
      m_tempMon->measTemp();
    }
  }
 private:
  TempMeasTimerAdapter(const TempMeasTimerAdapter& src);              // copy constructor
  TempMeasTimerAdapter& operator = (const TempMeasTimerAdapter& src); // assignment operator
};

//-----------------------------------------------------------------------------

const unsigned long TempMon::s_defaultMonitorIntervalMillis = 16000;

TempMon::TempMon(ITempMonAdapter* tempMonAdapter, unsigned long monitorIntervalMillis)
: m_timer(new Timer(new TempMeasTimerAdapter(this), Timer::IS_RECURRING, monitorIntervalMillis))
, m_tempSensor(new Adafruit_MCP9808())
, m_adapter(tempMonAdapter)
, m_monitorIntervalMillis(monitorIntervalMillis)
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

