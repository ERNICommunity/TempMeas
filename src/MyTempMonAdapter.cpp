/*
 * MyTempMonAdapter.cpp
 *
 *  Created on: 16.06.2016
 *      Author: niklausd
 */

#include "MyTempMonAdapter.h"

class MyTempMonAdpater
{
    public:
        virtual void NotifyTempChg(float temp)
        {
          ThingSpeak.setField(1, temp);
        }
};


