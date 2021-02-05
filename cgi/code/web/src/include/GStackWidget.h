//===============================================
#ifndef _GStackWidget_
#define _GStackWidget_
//===============================================
#include "GWidget.h"
//===============================================
class GStackWidget : public GWidget {
public:
    GStackWidget();
    ~GStackWidget();
    // method
    void addPage(QString key, QString page);
    void showPage(QString key);

private:
    QMap<QString, QString> m_widgetMap;
};
//===============================================
#endif
//===============================================
