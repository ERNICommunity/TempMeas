/*
 * TempMeasTimerAdapter.cpp
 *
 *  Created on: 16.06.2016
 *      Author: scan
 */

#include "TempMeasTimerAdapter.h"
#include "TempMon.h"

TempMeasTimerAdapter::TempMeasTimerAdapter(TempMon* tempMon)
:m_tempMon(tempMon)
{

}

void TempMeasTimerAdapter::timeExpired()
{
	if(0 != m_tempMon)
	{
		m_tempMon->measTemp();
	}
}
