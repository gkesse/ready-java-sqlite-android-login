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
    static int onFunction(double t, const double y[], double f[], void *params);
    static int onJacobian(double t, const double y[], double *dfdy, double dfdt[], void *params);

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_setting;
    QMenu* m_settingMenu;
    QCustomPlot* m_plot;
};
//===============================================
#endif
//===============================================