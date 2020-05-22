//================================================
#ifndef _GWidgetTextEdit_
#define _GWidgetTextEdit_
//===============================================
#include "GWidget.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWidgetTextEdit : public GWidget {
public:
    GWidgetTextEdit(QWidget* parent = 0);
    ~GWidgetTextEdit();

public:
    QTextEdit* textEdit();

private:
    const char* __CLASSNAME__;
    QPushButton* m_clear;
    QTextEdit* m_textEdit;
};
//================================================
#endif
//================================================
#endif
//================================================
