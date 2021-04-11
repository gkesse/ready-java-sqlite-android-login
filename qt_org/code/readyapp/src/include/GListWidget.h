//===============================================
#ifndef _GListWidget_
#define _GListWidget_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GListWidget : public GWidget {    
    Q_OBJECT

public:
    GListWidget(QWidget* parent = 0);
    ~GListWidget();

public:
    void addItem(QString key, QString text);
    void addItem(QString key, QString text, int icon);
    void addItem(QLayout* layout);
    void removeItem(int index);
    
public slots:
    void slotItemClick();
    
private:
    QListWidget* m_listWidget;
    QMap<QWidget*, QString> m_widgetId;
    QMap<int, QListWidgetItem*> m_rowId;
    int m_index;
};
//===============================================
#endif
//===============================================