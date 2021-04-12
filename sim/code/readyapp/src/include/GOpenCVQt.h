//===============================================
#ifndef _GOpenCVQt_
#define _GOpenCVQt_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GOpenCVQt : public GWidget {    
    Q_OBJECT

public:
    GOpenCVQt(QWidget* parent = 0);
    ~GOpenCVQt();
    
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