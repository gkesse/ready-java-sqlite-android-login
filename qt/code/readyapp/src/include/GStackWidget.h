//===============================================
#ifndef _GStackWidget_
#define _GStackWidget_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GStackWidget : public GWidget {    
    Q_OBJECT

public:
    GStackWidget(QWidget* parent = 0);
    ~GStackWidget();

public:
    void addPage(QString key, QString title, QWidget* widget, bool isDefault = 0);
    void setPage(QString key);
    GWidget* getPage(QString key);
    QWidget* getWidget(QString key);
    QString getTitle(QString key);
    
protected:
    QSize sizeHint() const;
    QSize minimumSizeHint() const;
    
private:
    QStackedWidget* m_workspace;
    QMap<QString, int> m_pageId;
    QMap<QString, QString> m_titleMap;
};
//===============================================
#endif
//===============================================