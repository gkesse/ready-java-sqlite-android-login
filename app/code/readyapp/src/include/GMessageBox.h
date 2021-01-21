//===============================================
#ifndef _GMessageBox_
#define _GMessageBox_
//===============================================
#include "GInclude.h"
//===============================================
class GMessageBox : public QMessageBox {
    Q_OBJECT
    
public:
    GMessageBox(QMessageBox::Icon icon, const QString &title, const QString &text, QMessageBox::StandardButtons buttons = NoButton, QWidget *parent = 0, Qt::WindowFlags f = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    GMessageBox(QWidget* parent = 0);
    ~GMessageBox();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    QPoint m_pressPos;
    bool m_pressFlag;
};
//===============================================
#endif
//===============================================