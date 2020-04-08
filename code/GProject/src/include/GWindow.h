//================================================
#ifndef _GWindow_
#define _GWindow_
//================================================
#include "GInclude.h"
#include "GWidget.h"
//================================================
class GWindow : public QFrame {
	Q_OBJECT

public:
	GWindow(QWidget* parent = 0);
	virtual ~GWindow();
	static GWindow* Create(string key);

public slots:
	virtual void slotRun();

protected:
    const char* __CLASSNAME__;
    GWidget* m_expression;
    GWidget* m_textEdit;
};
//================================================
#endif
//================================================
