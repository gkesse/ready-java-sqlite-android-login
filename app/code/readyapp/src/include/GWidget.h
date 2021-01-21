//===============================================
#ifndef _GWidget_
#define _GWidget_
//===============================================
#include "GInclude.h"
//===============================================
class GWidget : public QFrame {
    Q_OBJECT
    
public:
    GWidget(QWidget* parent = 0);
    ~GWidget();
    static GWidget* Create(QString key, QWidget* parent = 0);

public:
    virtual void addPage(QString key, QString title, QWidget* widget, bool isDefault);
    virtual int loadPage();
    //
    virtual void addItem(QString key, QString text);
    virtual void addItem(QString key, QString text, int icon);
    virtual void addItem(int row, int col, QString text);
    virtual void addItem(QLayout* layout);
    //
    virtual void removeItem(int index);
    //
    virtual void setContent(QString text);
    virtual void setContent(QString key, QString text);
    virtual void setContent(QString key, int icon, QColor color);
    virtual void setContent(QString key, int data);
    //
    virtual void setOption(QString key, int data);
    virtual void setOption(QString key, QString data);
    //
    virtual void getData(QString key, QString& data);
    //
    virtual void resetContent();
    //
    virtual void clearContent();
    //
    virtual void fillContent();
    
public slots:
    virtual void slotItemClick();
    virtual void slotPageOpen();
    
signals:
    void emitItemClick();
};
//===============================================
#endif
//===============================================