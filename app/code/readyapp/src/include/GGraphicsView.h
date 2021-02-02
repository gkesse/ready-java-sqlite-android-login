//===============================================
#ifndef _GGraphicsView_
#define _GGraphicsView_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GGraphicsView : public GWidget {    
    Q_OBJECT

public:
    GGraphicsView(QWidget* parent = 0);
    ~GGraphicsView();
    
public slots:
    void slotItemClick();
    void slotItemClick(QAction* action);

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_setting;
    QMenu* m_settingMenu;
    QGraphicsScene* m_scene;
    QGraphicsView* m_workspace;
};
//===============================================
#endif
//===============================================