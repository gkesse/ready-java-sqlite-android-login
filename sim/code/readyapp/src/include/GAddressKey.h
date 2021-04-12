//===============================================
#ifndef _GAddressKey_
#define _GAddressKey_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GAddressKey : public GWidget {    
    Q_OBJECT

public:
    GAddressKey(QWidget* parent = 0);
    ~GAddressKey();
    
public:
    void setContent(QString text);

public slots:
    void slotItemClick();
    
private:
    QHBoxLayout* m_mainLayout;
    QMap<QWidget*, QString> m_widgetId;
};
//===============================================
#endif
//===============================================