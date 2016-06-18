/*
 * TempMon.h
 *
 *  Created on: 16.06.2016
 *      Author: scan
 */

#ifndef LIB_TEMPMON_TEMPMON_H_
#define LIB_TEMPMON_TEMPMON_H_

class Timer;
class Adafruit_MCP9808;

//-----------------------------------------------------------------------------

class ITempMonAdapter
{
public:
  virtual void NotifyTempChg(float temp) = 0;
  virtual ~ITempMonAdapter() {}
};

//-----------------------------------------------------------------------------

class TempMon
{
public:
  TempMon(ITempMonAdapter* tempMonAdapter);
  virtual ~TempMon();
  void measTemp();

private:
  Timer* m_timer;
  Adafruit_MCP9808* m_tempSensor;
  ITempMonAdapter* m_adapter;

private:  // forbidden functions
  TempMon();                                // default constructor
  TempMon(const TempMon& src);              // copy constructor
  TempMon& operator = (const TempMon& src); // assignment operator
};

#endif /* LIB_TEMPMON_TEMPMON_H_ */
