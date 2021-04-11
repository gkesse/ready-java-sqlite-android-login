//===============================================
#ifndef _GTitleBar_
#define _GTitleBar_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GTitleBar : public GWidget {    
    Q_OBJECT

public:
    GTitleBar(QWidget* parent = 0);
    ~GTitleBar();
    
public slots:
    void slotItemClick();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_maximize;
    QPushButton* m_fullscreen;
    QPushButton* m_login;
    QPoint m_pressPos;
    bool m_pressFlag;
};
//===============================================
#endif
//===============================================