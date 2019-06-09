#include <Windows.h>
#include "struct.h"

date getDateToday() {
	SYSTEMTIME currentDay;
	GetSystemTime(&currentDay);
	date today;
	today.day = currentDay.wDay;
	today.month = currentDay.wMonth;
	today.year = currentDay.wYear;
	return today;
}