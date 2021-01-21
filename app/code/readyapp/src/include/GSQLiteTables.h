//===============================================
#ifndef _GSQLiteTables_
#define _GSQLiteTables_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GSQLiteTables : public GWidget {    
    Q_OBJECT

public:
    GSQLiteTables(QWidget* parent = 0);
    ~GSQLiteTables();

public:
    int loadPage();
    void fillContent();
    
public slots:
    void slotItemClick();
    
private:
    QMap<QWidget*, QString> m_widgetId;
    QMap<int, QPushButton*> m_showId;
    GWidget* m_listBox;
};
//===============================================
#endif
//===============================================