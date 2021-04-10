//===============================================
#ifndef _GTitle_
#define _GTitle_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GTitle : public GWidget {    
    Q_OBJECT

public:
    GTitle(QWidget* parent = 0);
    ~GTitle();
    
public:
    void setTitle(QString text);
    void setTitleIcon(int icon);
    
public slots:
    void slotItemClick();
    
private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_title;
    QPushButton* m_close;
};
//===============================================
#endif
//===============================================