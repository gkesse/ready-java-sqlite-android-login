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
    lName->setObjectName("mode_label");
    lName->setLabel("Nom de la variable");
    lName->setLabelWidth(150);
    m_widgetId[lName] = "name";
    
    GWidget* lValue = GWidget::Create("lineedit");
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
// slot
//===============================================
void GKeyValue::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    emit emitItemClick();
}
//===============================================
