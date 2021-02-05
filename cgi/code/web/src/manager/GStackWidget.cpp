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
void GStackWidget::addPage(QString key, QString page, QString title) {
    m_widgetMap[key] = page;
    m_titleMap[key] = title;
}
//===============================================
void GStackWidget::showPage(QString key) {
    QString lPageId = m_widgetMap[key];
    GWidget::Create(lPageId)->print();
}
//===============================================
QString GStackWidget::getTitle(QString key) {
    return m_titleMap[key];
}
//===============================================
