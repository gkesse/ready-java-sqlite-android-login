//===============================================
#ifndef _GOpenGLQt_
#define _GOpenGLQt_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GOpenGLQt : public GWidget {    
    Q_OBJECT

public:
    GOpenGLQt(QWidget* parent = 0);
    ~GOpenGLQt();
        
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