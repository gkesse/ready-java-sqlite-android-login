//===============================================
#ifndef _GMainWindow_
#define _GMainWindow_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GMainWindow : public GWidget {    
    Q_OBJECT

public:
    GMainWindow(QWidget* parent = 0);
    ~GMainWindow();
        
public slots:
    void slotItemClick();
    void slotItemClick(QAction* action);

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_setting;
    QMenu* m_settingMenu;
    QTextEdit* m_textEdit;
};
//===============================================
#endif
//===============================================