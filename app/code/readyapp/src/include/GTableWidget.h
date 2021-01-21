//===============================================
#ifndef _GTableWidget_
#define _GTableWidget_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GTableWidget : public GWidget {    
    Q_OBJECT

public:
    GTableWidget(QWidget* parent = 0);
    ~GTableWidget();

public:
    void setOption(QString key, int data);
    void setOption(QString key);
    void addItem(int row, int col, QString text);
    void addItem(QString key, QString text, int icon);
    void addItem(QLayout* layout);
    void removeItem(int index);
    
public slots:
    void slotItemClick();
    
private:
    QTableWidget* m_tableWidget;
    QMap<QWidget*, QString> m_widgetId;
    QMap<int, QListWidgetItem*> m_rowId;
    int m_index;
};
//===============================================
#endif
//===============================================