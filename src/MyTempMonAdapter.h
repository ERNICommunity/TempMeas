/*
 * MyTempMonAdapter.h
 *
 *  Created on: 16.06.2016
 *      Author: niklausd
 */

#ifndef SRC_MYTEMPMONADAPTER_H_
#define SRC_MYTEMPMONADAPTER_H_

#include <TempMon.h>

class MyTempMonAdpater : public ITempMonAdapter
{
public:
  void NotifyTempChg(float temp);
};

#endif /* SRC_MYTEMPMONADAPTER_H_ */
