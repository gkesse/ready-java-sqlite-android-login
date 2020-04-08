//================================================
#ifndef _GWidget_
#define _GWidget_
//================================================
#include "GInclude.h"
//================================================
class GWidget : public QFrame {
	Q_OBJECT

public:
	GWidget(QWidget* parent = 0);
	virtual ~GWidget();
	static GWidget* Create(string key);
	void setLabel(QString label);
	QString getText();

signals:
	void emitRun();
	void emitClear();

protected:
    const char* __CLASSNAME__;
    QLabel* m_label;
    QLineEdit* m_lineEidt;
    QPushButton* m_run;
    QPushButton* m_clear;
    QTextEdit* m_textEdit;
};
//================================================
#endif
//================================================
