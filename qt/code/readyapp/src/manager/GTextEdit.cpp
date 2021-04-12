//===============================================
#include "GTextEdit.h"
#include "GManager.h"
//===============================================
GTextEdit::GTextEdit(QWidget* parent) : GWidget(parent) {
    setObjectName("GTextEdit");

    QTextEdit* lTextEdit = new QTextEdit;
    m_textEdit = lTextEdit;
    lTextEdit->setObjectName("terminal");
    lTextEdit->setReadOnly(true);
    m_widgetId[lTextEdit] = "textedit";
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lTextEdit);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);    
}
//===============================================
GTextEdit::~GTextEdit() {
    
}
//===============================================
// method
//===============================================
void GTextEdit::setText(QString text) {
    m_textEdit->setText(text);
}
//===============================================
void GTextEdit::append(QString text) {
    m_textEdit->append(text);
}
//===============================================
// slot
//===============================================
void GTextEdit::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    lApp->widget_id = lWidgetId;
}
//===============================================
