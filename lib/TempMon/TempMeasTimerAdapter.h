/*
 * TempMeasTimerAdapter.h
 *
 *  Created on: 16.06.2016
 *      Author: scan
 */

#ifndef LIB_TEMPMON_TEMPMEASTIMERADAPTER_H_
#define LIB_TEMPMON_TEMPMEASTIMERADAPTER_H_

#include <Timer.h>

class TempMon;

class TempMeasTimerAdapter : public TimerAdapter {

public:
	TempMeasTimerAdapter(TempMon* tempMon);
	virtual ~TempMeasTimerAdapter() { }
	void timeExpired();

private:
	TempMon* m_tempMon;

private:
	TempMeasTimerAdapter(const TempMeasTimerAdapter& src);              // copy constructor
	TempMeasTimerAdapter& operator = (const TempMeasTimerAdapter& src); // assignment operator
};

#endif /* LIB_TEMPMON_TEMPMEASTIMERADAPTER_H_ */
