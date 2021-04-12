//===============================================
#ifndef _GUserAdd_
#define _GUserAdd_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GUserAdd : public GWidget {    
    Q_OBJECT

public:
    GUserAdd(QWidget* parent = 0);
    ~GUserAdd();
    
public:
    void resetContent();
    
public slots:
    void slotItemClick();

private:
    QMap<QWidget*, QString> m_widgetId;
    GWidget* m_username;
    GWidget* m_password;
    GWidget* m_confirm;
    QLabel* m_message;
};
//===============================================
#endif
//===============================================