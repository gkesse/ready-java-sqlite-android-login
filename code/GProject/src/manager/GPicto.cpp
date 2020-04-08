//===============================================
#include "GPicto.h"
#include "GWindowMath.h"
//===============================================
GPicto* GPicto::m_instance = 0;
//===============================================
GPicto::GPicto() {
	__CLASSNAME__ = __FUNCTION__;
	m_picto = new QtAwesome(qApp);
	m_picto->initFontAwesome();
	m_color = "white";
}
//===============================================
GPicto::~GPicto() {

}
//===============================================
GPicto* GPicto::Instance() {
	if(m_instance == 0) {
		m_instance = new GPicto;
	}
	return m_instance;
}
//===============================================
void GPicto::process(const char* key, ...) {
	bool lRunFlag = 0;
	va_list lArgs;
	va_start(lArgs, key);
	while(1) {
		if(strcmp(key, "picto") == 0) {
			QString lFilename = va_arg(lArgs, char*);
			load(lFilename); lRunFlag = 1; break;
		}
		break;
	}
	va_end(lArgs);
}
//===============================================
void GPicto::getPicto(QString filename) {
	QFile lFile(filename);
	lFile.open(QFile::ReadOnly);
	QString lStyleSheet = QLatin1String(lFile.readAll());
	qApp->setStyleSheet(lStyleSheet);
}
//===============================================
