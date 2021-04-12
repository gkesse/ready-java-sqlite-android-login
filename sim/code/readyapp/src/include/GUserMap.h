//===============================================
#ifndef _GUserMap_
#define _GUserMap_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GUserMap : public GWidget {    
    Q_OBJECT

public:
    GUserMap(QWidget* parent = 0);
    ~GUserMap();

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