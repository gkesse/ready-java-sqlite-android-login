//===============================================
#ifndef _GDebug_
#define _GDebug_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GDebug : public GWidget {    
    Q_OBJECT

public:
    GDebug(QWidget* parent = 0);
    ~GDebug();
    
public slots:
    void slotItemClick();
    void slotItemClick(QAction* action);

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_setting;
    QMenu* m_settingMenu;
};
//===============================================
#endif
//===============================================