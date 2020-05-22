//================================================
#ifndef _GWidget_
#define _GWidget_
//===============================================
#include "GInclude.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//================================================
class GWidget : public QFrame {
    Q_OBJECT

public:
    GWidget(QWidget* parent = 0);
    virtual ~GWidget();
    static GWidget* Create(string key);
    virtual void setLabel(QString label);
    virtual QString getText();
    virtual bool getCheck();
    virtual QTextEdit* textEdit();
    virtual QCustomPlot* plot();

public slots:
    virtual void slotWindowTitleChange(QString text);
    virtual void slotWindowIconChange(QIcon icon);
    virtual void slotWindowMaximize(int oldState, int newState);
    virtual void slotWindowFullScreen(int oldState, int newState);
    virtual void slotCheck(bool ok);

signals:
    void emitRun();
    void emitClear();
    void emitWindowPress(QPoint position);
    void emitWindowMove(QPoint position);
    void emitWindowMinimize();
    void emitWindowMaximize();
    void emitWindowClose();
    void emitWindowFullScreen();

protected:
    const char* __CLASSNAME__;
    /*
    QLabel* m_label;
    QLabel* m_icon;
    QLabel* m_title;
    QLineEdit* m_lineEidt;
    QTextEdit* m_textEdit;
    QPushButton* m_run;
    QPushButton* m_clear;
    QToolButton* m_minimize;
    QToolButton* m_maximize;
    QToolButton* m_close;
    QCheckBox* m_check;
    */
};
//================================================
#endif
//================================================
#endif
//================================================
