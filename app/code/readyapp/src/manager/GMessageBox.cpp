//===============================================
#include "GMessageBox.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GMessageBox::GMessageBox(QMessageBox::Icon icon, const QString &title, const QString &text, QMessageBox::StandardButtons buttons, QWidget *parent, Qt::WindowFlags f) :
QMessageBox(icon, title, text, buttons, parent, f) {
    setObjectName("GMessageBox");
}
//===============================================
GMessageBox::GMessageBox(QWidget* parent) : QMessageBox(parent) {
    setObjectName("GMessageBox");
}
//===============================================
GMessageBox::~GMessageBox() {
    
}
//===============================================
// callback
//===============================================
void GMessageBox::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        setCursor(QCursor(Qt::SizeAllCursor));
        m_pressPos = event->pos();
        m_pressFlag = true;
    }
}
//===============================================
void GMessageBox::mouseReleaseEvent(QMouseEvent *event) {
    setCursor(QCursor(Qt::ArrowCursor));
    m_pressFlag = false;
}
//===============================================
void GMessageBox::mouseMoveEvent(QMouseEvent *event) {
    if(m_pressFlag == true) {
        QPoint lGlobalPos = event->globalPos();
        QPoint lDiffPos = lGlobalPos - m_pressPos;
        move(lDiffPos);
    }    
}
//===============================================
