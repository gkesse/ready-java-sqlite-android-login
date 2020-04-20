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
QIcon GPicto::getPicto(int picto) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
    m_picto->setDefaultOption("color", m_color);
    m_picto->setDefaultOption("color-active", m_color);
    return m_picto->icon(picto);
}
//===============================================
void GPicto::setColor(QColor color) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
	m_color = color;
}
//================================================
#endif
//===============================================
