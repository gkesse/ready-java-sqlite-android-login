//================================================
#ifndef _GWidgetLineEdit_
#define _GWidgetLineEdit_
//================================================
#include "GWidget.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWidgetLineEdit : public GWidget {
public:
	GWidgetLineEdit(QWidget* parent = 0);
	~GWidgetLineEdit();

public:
	void setLabel(QString label);
	QString getText();

private:
	const char* __CLASSNAME__;
	QLabel* m_label;
	QLineEdit* m_lineEidt;

};
//================================================
#endif
//================================================
#endif
//================================================
