/*
 * MyTempMonAdapter.h
 *
 *  Created on: 16.06.2016
 *      Author: niklausd
 */

#include "ITempMonAdapter.h"

#ifndef SRC_MYTEMPMONADAPTER_H_
#define SRC_MYTEMPMONADAPTER_H_

class MyTempMonAdapter : public ITempMonAdapter
{
     public:
        virtual void NotifyTempChg(double temp);

};

#endif /* SRC_MYTEMPMONADAPTER_H_ */
