//===============================================
#ifndef _GKeyValue_
#define _GKeyValue_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GKeyValue : public GWidget {    
    Q_OBJECT

public:
    GKeyValue(QWidget* parent = 0);
    ~GKeyValue();
    
public:
    int loadPage();
    void setClear(bool flag);
    void setTitle(QString text);
    void setTitleIcon(int icon);
    QString getName();
    QString getValue();
    
public slots:
    void slotItemClick();
    
private:
    QMap<QWidget*, QString> m_widgetId;
    GWidget* m_title;
    GWidget* m_name;
    GWidget* m_value;
    bool m_clearFlag;
};
//===============================================
#endif
//===============================================