/*
 * MyTempMonAdapter.h
 *
 *  Created on: 16.06.2016
 *      Author: niklausd
 */

#ifndef SRC_MYTEMPMONADAPTER_H_
#define SRC_MYTEMPMONADAPTER_H_

#include "ITempMonAdapter.h"


class MyTempMonAdpater : public ITempMonAdapter
{
public:
  MyTempMonAdpater()
  : ITempMonAdapter()
  { }
  virtual ~MyTempMonAdpater() { }
  void NotifyTempChg(float temp);
};

#endif /* SRC_MYTEMPMONADAPTER_H_ */
