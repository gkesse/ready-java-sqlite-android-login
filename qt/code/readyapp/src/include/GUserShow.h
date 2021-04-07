//===============================================
#ifndef _GUserShow_
#define _GUserShow_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GUserShow : public GWidget {    
    Q_OBJECT

public:
    GUserShow(QWidget* parent = 0);
    ~GUserShow();

public:
    int loadPage();
    void deleteTable(QString table, int index);
    
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