//===============================================
#include "GKeyValue.h"
#include "GManager.h"
//===============================================
GKeyValue::GKeyValue(QWidget* parent) : GWidget(parent) {
    setObjectName("GKeyValue");
    
    QFrame* lContent = new QFrame;
    
    GWidget* lTitle = GWidget::Create("title");
    m_title = lTitle;
    lTitle->setVisible(false);
    m_widgetId[lTitle] = "title";
    
    GWidget* lName = GWidget::Create("lineedit");
    m_name = lName;
    lName->setObjectName("mode_label");
    lName->setLabel("Nom de la variable");
    lName->setLabelWidth(150);
    m_widgetId[lName] = "name";
    
    GWidget* lValue = GWidget::Create("lineedit");
    m_value = lValue;
    lValue->setObjectName("mode_label");
    lValue->setLabel("Valeur de la variable");
    lValue->setLabelWidth(150);
    m_widgetId[lValue] = "value";
    
    GWidget* lButtons = GWidget::Create("buttonrow");
    lButtons->setAlignment(Qt::AlignRight);
    lButtons->addItem("cancel", "Annuler");
    lButtons->addItem("add", "Ajouter");
    m_widgetId[lButtons] = "buttons";
    
    QVBoxLayout* lContentLayout = new QVBoxLayout;
    lContentLayout->addWidget(lTitle);
    lContentLayout->addWidget(lName);
    lContentLayout->addWidget(lValue);
    lContentLayout->addWidget(lButtons);
    lContentLayout->setMargin(10);
    lContentLayout->setSpacing(10);
    
    lContent->setLayout(lContentLayout);    
    lContent->setMaximumWidth(400);    
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lContent);
    lMainLayout->setAlignment(Qt::AlignCenter);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);    

    m_clearFlag = false;

    connect(lTitle, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(lName, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(lValue, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
    connect(lButtons, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
}
//===============================================
GKeyValue::~GKeyValue() {
    
}
//===============================================
// method
//===============================================
int GKeyValue::loadPage() {
    if(m_clearFlag == true) {
        m_name->setText("");
        m_value->setText("");
    }
    return 1;
}
//===============================================
void GKeyValue::setClear(bool flag) {
    m_clearFlag = flag;
}
//===============================================
void GKeyValue::setTitle(QString text) {
    m_title->setTitle(text);
    m_title->setVisible(true);
}
//===============================================
void GKeyValue::setTitleIcon(int icon) {
    m_title->setTitleIcon(icon);
    m_title->setVisible(true);
}
//===============================================
void GKeyValue::setName(QString text) {
    m_name->setText(text);
}
//===============================================
void GKeyValue::setValue(QString text) {
    m_value->setText(text);
}
//===============================================
void GKeyValue::setNameLabel(QString text) {
    m_name->setLabel(text);
}
//===============================================
void GKeyValue::setValueLabel(QString text) {
    m_value->setLabel(text);
}
//===============================================
QString GKeyValue::getName() {
    return m_name->getText();
}
//===============================================
QString GKeyValue::getValue() {
    return m_value->getText();
}
//===============================================
// slot
//===============================================
void GKeyValue::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    if((lWidgetId == "name" || lWidgetId == "value") 
    && (lApp->widget_id == "edit")) {
        lApp->widget_id = lWidgetId;
    }
    emit emitItemClick();
}
//===============================================
