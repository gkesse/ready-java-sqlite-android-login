//===============================================
#ifndef _GQCustomPlotQt_
#define _GQCustomPlotQt_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GQCustomPlotQt : public GWidget {    
    Q_OBJECT

public:
    GQCustomPlotQt(QWidget* parent = 0);
    ~GQCustomPlotQt();
        
public slots:
    void slotItemClick();
    void slotItemClick(QAction* action);

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_setting;
    QMenu* m_settingMenu;
    QCustomPlot* m_plot;
};
//===============================================
#endif
//===============================================