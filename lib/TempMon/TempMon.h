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
class ITempMonAdapter;

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

};

#endif /* LIB_TEMPMON_TEMPMON_H_ */
