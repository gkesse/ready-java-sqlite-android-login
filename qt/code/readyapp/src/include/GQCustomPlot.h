//===============================================
#ifndef _GQCustomPlot_
#define _GQCustomPlot_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GQCustomPlot : public GWidget {    
    Q_OBJECT

public:
    GQCustomPlot(QWidget* parent = 0);
    ~GQCustomPlot();
        
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