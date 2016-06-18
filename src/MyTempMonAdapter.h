/*
 * MyTempMonAdapter.h
 *
 *  Created on: 16.06.2016
 *      Author: niklausd
 */

#ifndef SRC_MYTEMPMONADAPTER_H_
#define SRC_MYTEMPMONADAPTER_H_

#include <TempMon.h>

class DbgTrace_Port;
class TM1638;

class MyTempMonAdpater : public ITempMonAdapter
{
public:
  MyTempMonAdpater(TM1638* tm1638);
  void NotifyTempChg(float temp);

private:
  const char* thingSpeakStatusString(int status);

private:
  DbgTrace_Port* m_trPort;
  TM1638* m_tm1638;
};

#endif /* SRC_MYTEMPMONADAPTER_H_ */
