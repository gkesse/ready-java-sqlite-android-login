//===============================================
#include "GStyle.h"
#include "GWindowMath.h"
//===============================================
GStyle* GStyle::m_instance = 0;
//===============================================
GStyle::GStyle() {
	__CLASSNAME__ = __FUNCTION__;
}
//===============================================
GStyle::~GStyle() {

}
//===============================================
GStyle* GStyle::Instance() {
	if(m_instance == 0) {
		m_instance = new GStyle;
	}
	return m_instance;
}
//===============================================
void GStyle::process(const char* key, ...) {
	bool lRunFlag = 0;
	va_list lArgs;
	va_start(lArgs, key);
	while(1) {
		if(strcmp(key, "load") == 0) {
			QString lFilename = va_arg(lArgs, char*);
			load(lFilename); lRunFlag = 1; break;
		}
		break;
	}
	va_end(lArgs);
}
//===============================================
void GStyle::load(QString filename) {
	QFile lFile(filename);
	lFile.open(QFile::ReadOnly);
	QString lStyleSheet = QLatin1String(lFile.readAll());
	qApp->setStyleSheet(lStyleSheet);
}
//===============================================
