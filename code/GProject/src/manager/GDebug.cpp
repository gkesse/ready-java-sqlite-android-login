//===============================================
#include "GDebug.h"
#include "GWindowMath.h"
//===============================================
GDebug* GDebug::m_instance = 0;
//===============================================
GDebug::GDebug() {
	__CLASSNAME__ = __FUNCTION__;
	m_filename = "data/debug/debug.txt";
	//clear();
}
//===============================================
GDebug::~GDebug() {

}
//===============================================
GDebug* GDebug::Instance() {
	if(m_instance == 0) {
		m_instance = new GDebug;
	}
	return m_instance;
}
//===============================================
void GDebug::process(const char* key, ...) {
	bool lRunFlag = 0;
	va_list lArgs;
	va_start(lArgs, key);
	while(1) {
		if(strcmp(key, "log") == 0) {
			log(lArgs); lRunFlag = 1; break;
		}
		else if(strcmp(key, "sep") == 0) {
			sep(); lRunFlag = 1; break;
		}
		break;
	}
	va_end(lArgs);
}
//===============================================
void GDebug::log(va_list args) {
	char lBuffer[256];
	char lDate[256];
	int lIndex = 0;
	date(lDate);
	lIndex += sprintf(&lBuffer[lIndex], "%s | ", lDate);
	while(1) {
		char* lData = va_arg(args, char*);
		if(lData == 0) break;
		lIndex += sprintf(&lBuffer[lIndex], "%s", lData);
	}
	write(lBuffer);
}
//===============================================
void GDebug::sep() {
	const char* lSep = "=================================================";
	line(lSep);
}
//===============================================
void GDebug::line(const char* data) {
	char lBuffer[256];
	char lDate[256];
	date(lDate);
	sprintf(lBuffer, "%s | %s", lDate, data);
	write(lBuffer);
}
//===============================================
void GDebug::write(const char* data) {
	FILE* lpFile = fopen(m_filename, "a+");
	fprintf(lpFile, "%s\n", data);
	fclose(lpFile);
}
//===============================================
void GDebug::clear() {
	FILE* lpFile = fopen(m_filename, "w");
	fclose(lpFile);
}
//===============================================
void GDebug::date(char* buffer) {
	time_t lRawTime;
	time(&lRawTime);
	struct tm* lTimeInfo = localtime(&lRawTime);
	int lDay = lTimeInfo->tm_mday;
	int lMonth = lTimeInfo->tm_mon + 1;
	int lYear = lTimeInfo->tm_year + 1900;
	int lHour = lTimeInfo->tm_hour;
	int lMin = lTimeInfo->tm_min;
	int lSec = lTimeInfo->tm_sec;
	if(lTimeInfo->tm_isdst == 1) lHour++;
	sprintf(buffer, "%02d/%02d/%04d %02d:%02d:%02d", lDay, lMonth, lYear, lHour, lMin, lSec);
}
//===============================================
