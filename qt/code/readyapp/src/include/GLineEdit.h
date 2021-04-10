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
    void setLabel(QString text);
    void setLabelWidth(int width);
    void setLabelIcon(int icon, QColor color = "white");
    void setGoToIcon(int icon, QColor color = "white");
    void setIcon(int icon, QColor color = "white");
    void setText(QString text);
    void setEchoMode(QLineEdit::EchoMode mode);
    void setReadOnly(bool flag);
    QString getText();
    
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