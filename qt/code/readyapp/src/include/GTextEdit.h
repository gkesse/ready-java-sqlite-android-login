//===============================================
#ifndef _GTextEdit_
#define _GTextEdit_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GTextEdit : public GWidget {    
    Q_OBJECT

public:
    GTextEdit(QWidget* parent = 0);
    ~GTextEdit();

public:
    void setText(QString text);
    void append(QString text);
    
public slots:
    void slotItemClick();
    
private:
    QMap<QWidget*, QString> m_widgetId;
    QTextEdit* m_textEdit;
};
//===============================================
#endif
//===============================================