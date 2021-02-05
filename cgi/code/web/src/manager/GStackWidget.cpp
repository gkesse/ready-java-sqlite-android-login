//===============================================
#include "GStackWidget.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
GStackWidget::GStackWidget() {

}
//===============================================
GStackWidget::~GStackWidget() {
    
}
//===============================================
// method
//===============================================
void GStackWidget::addPage(QString key, QString page) {
    m_widgetMap[key] = page;
}
//===============================================
void GStackWidget::showPage(QString key) {
    QString lPageId = m_widgetMap[key];
    GWidget::Create(lPageId)->print();
}
//===============================================
