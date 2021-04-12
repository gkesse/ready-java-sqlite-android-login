//===============================================
#ifndef _GPdfUi_
#define _GPdfUi_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GPdfUi : public GWidget {    
    Q_OBJECT

public:
    GPdfUi(QWidget* parent = 0);
    ~GPdfUi();

public:
    void addPage(QString key, QString title, QWidget* widget, bool isDefault = 0);
    
public slots:
    void slotItemClick();

private:
    QMap<QWidget*, QString> m_widgetId;
    QMap<QString, int> m_pageId;
    QMap<QString, QString> m_titleMap;
    QPushButton* m_title;
    QStackedWidget* m_pageMap;
    QTextEdit* m_textEdit;
    QTextBrowser* m_textBrowser;
};
//===============================================
#endif
//===============================================