//===============================================
#include "GFileDialog.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GFileDialog::GFileDialog(QWidget *parent, Qt::WindowFlags flags) : 
QFileDialog(parent, flags) {
    setObjectName("GFileDialog");
}
//===============================================
GFileDialog::~GFileDialog() {
    
}
//===============================================
// callback
//===============================================
void GFileDialog::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton) {
        setCursor(QCursor(Qt::SizeAllCursor));
        m_pressPos = event->pos();
        m_pressFlag = true;
    }
}
//===============================================
void GFileDialog::mouseReleaseEvent(QMouseEvent *event) {
    setCursor(QCursor(Qt::ArrowCursor));
    m_pressFlag = false;
}
//===============================================
void GFileDialog::mouseMoveEvent(QMouseEvent *event) {
    if(m_pressFlag == true) {
        QPoint lGlobalPos = event->globalPos();
        QPoint lDiffPos = lGlobalPos - m_pressPos;
        move(lDiffPos);
    }    
}
//===============================================
