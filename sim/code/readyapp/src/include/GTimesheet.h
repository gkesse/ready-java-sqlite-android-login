//===============================================
#ifndef _GTimesheet_
#define _GTimesheet_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GTimesheet : public GWidget {    
    Q_OBJECT

public:
    GTimesheet(QWidget* parent = 0);
    ~GTimesheet();

public:
    int loadPage();

public slots:
    void slotItemClick();
    void slotItemClick(QAction* action);
    
private:
    QPushButton* m_setting;
    QMenu* m_settingMenu;
    QTextEdit* m_debug;
    QMap<QWidget*, QString> m_widgetId;
};
//===============================================
#endif
//===============================================