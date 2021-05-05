//===============================================
#ifndef _GGslQt_
#define _GGslQt_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GGslQt : public GWidget {    
    Q_OBJECT

public:
    GGslQt(QWidget* parent = 0);
    ~GGslQt();
        
public slots:
    void slotItemClick();
    void slotItemClick(QAction* action);

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_setting;
    QMenu* m_settingMenu;
    GWidget* m_workspace;
};
//===============================================
#endif
//===============================================