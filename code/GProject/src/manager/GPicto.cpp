//===============================================
#include "GPicto.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QTAWESOME_ON_)
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
QIcon GPicto::process(const char* key, ...) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	bool lRunFlag = 0;
	va_list lArgs;
	va_start(lArgs, key);
	QIcon lIcon;
	while(1) {
		if(strcmp(key, "picto") == 0) {
			int lPicto = va_arg(lArgs, int);
			lIcon = getPicto(lPicto, m_color); lRunFlag = 1; break;
		}
		else if(strcmp(key, "picto_c") == 0) {
			int lPicto = va_arg(lArgs, int);
			QColor lColor = va_arg(lArgs, char*);
			lIcon = getPicto(lPicto, lColor); lRunFlag = 1; break;
		}
		else if(strcmp(key, "color") == 0) {
			QColor lColor = va_arg(lArgs, char*);
			setColor(lColor); lRunFlag = 1; break;
		}
		break;
	}
	va_end(lArgs);
	return lIcon;
}
//===============================================
QIcon GPicto::getPicto(int picto, QColor color) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
    m_picto->setDefaultOption("color", color);
    m_picto->setDefaultOption("color-active", color);
    m_color = color;
    return m_picto->icon(picto);
}
//===============================================
void GPicto::setColor(QColor color) {
	GDebug::Instance()->process("log", __CLASSNAME__, "::", __FUNCTION__, "()", 0);
	m_color = color;
}
//================================================
#endif
//===============================================
