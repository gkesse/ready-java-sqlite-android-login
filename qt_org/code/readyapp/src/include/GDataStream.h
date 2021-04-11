//===============================================
#ifndef _GDataStream_
#define _GDataStream_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GDataStream : public GWidget {    
    Q_OBJECT

public:
    GDataStream(QWidget* parent = 0);
    ~GDataStream();
        
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