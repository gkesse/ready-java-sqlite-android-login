//===============================================
#include "GStyle.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
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
void GStyle::load(QString filename) {
	GDebug::Instance()->write(__CLASSNAME__, "::", __FUNCTION__, "()", 0);
	QFile lFile(filename);
	lFile.open(QFile::ReadOnly);
	QString lStyleSheet = QLatin1String(lFile.readAll());
	qApp->setStyleSheet(lStyleSheet);
}
//================================================
#endif
//===============================================
