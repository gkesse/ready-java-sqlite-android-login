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
    void addPage(QString key, QString page, QString title);
    void showPage(QString key);
    void setCookies(QString key);
    QString getTitle(QString key);
    QString getPage(QString key);

private:
    QMap<QString, QString> m_widgetMap;
    QMap<QString, QString> m_titleMap;
};
//===============================================
#endif
//===============================================
