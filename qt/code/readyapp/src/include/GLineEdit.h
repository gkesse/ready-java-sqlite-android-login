//===============================================
#ifndef _GLineEdit_
#define _GLineEdit_
//===============================================
#include "GInclude.h"
#include "GWidget.h"
//===============================================
class GLineEdit : public GWidget {    
    Q_OBJECT

public:
    GLineEdit(QWidget* parent = 0);
    ~GLineEdit();

public:
    void setContent(QString key, QString text);
    void setContent(QString key, int icon, QColor color);
    void setContent(QString key, int data);
    void setOption(QString key, int mode);
    void getData(QString key, QString& data);
    
public slots:
    void slotItemClick();

private:
    QMap<QWidget*, QString> m_widgetId;
    QPushButton* m_label;
    QPushButton* m_icon;
    QPushButton* m_goto;
    QLineEdit* m_edit;
};
//===============================================
#endif
//===============================================