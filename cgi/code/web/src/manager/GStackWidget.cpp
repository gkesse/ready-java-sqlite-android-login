//===============================================
#include "GStackWidget.h"
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
    QString lPageId = getPage(key);
    GWidget::Create(lPageId)->print();
}
//===============================================
void GStackWidget::setCookies(QString key) {
    QString lPageId = getPage(key);
    GWidget::Create(lPageId)->setCookies();
}
//===============================================
QString GStackWidget::getTitle(QString key) {
    return m_titleMap.value(key, "");
}
//===============================================
QString GStackWidget::getPage(QString key) {
    return m_widgetMap.value(key, "");
}
//===============================================
