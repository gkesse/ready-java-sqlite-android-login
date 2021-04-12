//===============================================
#ifndef _GButtonRow_
#define _GButtonRow_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GButtonRow : public GWidget {    
    Q_OBJECT

public:
    GButtonRow(QWidget* parent = 0);
    ~GButtonRow();
    
public:
    void addItem(QString key, QString text);
    void addItem(QString key, QString text, int icon);
    void setAlignment(int alignment);
    
public slots:
    void slotItemClick();
    
private:
    QMap<QWidget*, QString> m_widgetId;
    QHBoxLayout* m_mainLayout;
};
//===============================================
#endif
//===============================================