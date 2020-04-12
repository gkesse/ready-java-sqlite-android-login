//================================================
#ifndef _GPicto_
#define _GPicto_
//================================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GPicto {
private:
	GPicto();

public:
	~GPicto();
	static GPicto* Instance();
	QIcon process(const char* key, ...);

private:
    QIcon getPicto(int picto, QColor color);
    void setColor(QColor color);

private:
    const char* __CLASSNAME__;
	static GPicto* m_instance;
	QtAwesome* m_picto;
	QColor m_color;
};
//================================================
#endif
//================================================
#endif
//================================================
