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

public:
    void addPage(QString key, QString title, QWidget* widget, bool isDefault = 0);

protected:
    void resizeEvent(QResizeEvent *event);
    
private:
    QMap<QWidget*, QString> m_widgetId;
    QSizeGrip* m_sizeGrip;
};
//===============================================
#endif
//===============================================