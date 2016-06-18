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

class MyTempMonAdpater : public ITempMonAdapter
{
public:
  MyTempMonAdpater();
  void NotifyTempChg(float temp);

private:
  const char* thingSpeakStatusString(int status);

private:
  DbgTrace_Port* m_trPort;
};

#endif /* SRC_MYTEMPMONADAPTER_H_ */
