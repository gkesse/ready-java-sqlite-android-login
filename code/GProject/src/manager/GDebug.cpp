//===============================================
#include "GDebug.h"
#include "GDir.h"
//===============================================
GDebug* GDebug::m_instance = 0;
//===============================================
GDebug::GDebug() {
	__CLASSNAME__ = __FUNCTION__;
	char lCommand[256];
#if defined(__WIN32)
	homePathWin();
#else
	homePathUnix();
#endif
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
	va_list lArgs;
	va_start(lArgs, key);
	while(1) {
		if(strcmp(key, "log") == 0) {
			log(lArgs); break;
		}
		else if(strcmp(key, "sep") == 0) {
			sep(); break;
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
void GDebug::homePathWin() {
#if defined(__WIN32)
	char lCommand[256];
	sprintf(lCommand, "%s", "echo %HOMEDRIVE%%HOMEPATH%");
	FILE* lpFile = popen(lCommand, "r");
	int lBytes = fread(m_homePath, 1, 255, lpFile);
	m_homePath[lBytes - 1] = 0;
	pclose(lpFile);
	sprintf(m_debugPath, "%s%s", m_homePath, "\\.readydev\\readycpp\\data\\debug");
	sprintf(m_filename, "%s%s", m_debugPath, "\\debug.txt");
	//
	sprintf(lCommand, "if not exist %s ( mkdir %s )", m_debugPath, m_debugPath);
	lpFile = popen(lCommand, "r");
	pclose(lpFile);
#endif
}
//===============================================
void GDebug::homePathUnix() {
#if defined(__unix)
	char lCommand[256];
	sprintf(lCommand, "%s", "echo $HOME");
	FILE* lpFile = popen(lCommand, "r");
	int lBytes = fread(m_homePath, 1, 255, lpFile);
	m_homePath[lBytes - 1] = 0;
	pclose(lpFile);
	sprintf(m_debugPath, "%s%s", m_homePath, "/.readydev/readycpp/data/debug");
	sprintf(m_filename, "%s%s", m_debugPath, "/debug.txt");
	//
	sprintf(lCommand, "if [ -d \"%s\" ] ; then mkdir -p %s ; fi", m_debugPath, m_debugPath);
	lpFile = popen(lCommand, "r");
	pclose(lpFile);
#endif
}
//===============================================
