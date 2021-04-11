//===============================================
#ifndef _GWindow_
#define _GWindow_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GWindow : public GWidget {    
    Q_OBJECT

public:
    GWindow(QWidget* parent = 0);
    ~GWindow();

protected:
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);
    
private:
    QMap<QWidget*, QString> m_widgetId;
    QSizeGrip* m_sizeGrip;
};
//===============================================
#endif
//===============================================