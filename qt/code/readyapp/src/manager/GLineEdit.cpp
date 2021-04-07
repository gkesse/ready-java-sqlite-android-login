//===============================================
#include "GLineEdit.h"
#include "GManager.h"
//===============================================
GLineEdit::GLineEdit(QWidget* parent) : GWidget(parent) {
    setObjectName("GLineEdit");
        
    QPushButton* lLabel = new QPushButton;
    m_label = lLabel;
    lLabel->setObjectName("label");
    lLabel->setVisible(false);
    m_widgetId[lLabel] = "label";
    
    QPushButton* lIcon = new QPushButton;
    m_icon = lIcon;
    lIcon->setObjectName("icon");
    lIcon->setVisible(false);
    lIcon->setCursor(Qt::PointingHandCursor);
    m_widgetId[lIcon] = "icon";
    
    QLineEdit* lEdit = new QLineEdit;
    m_edit = lEdit;
    lEdit->setObjectName("edit");
    m_widgetId[lEdit] = "edit";
    
    QPushButton* lGoTo = new QPushButton;
    m_goto = lGoTo;
    lGoTo->setObjectName("goto");
    lGoTo->setVisible(false);
    lGoTo->setCursor(Qt::PointingHandCursor);
    m_widgetId[lGoTo] = "goto";
        
    QHBoxLayout* lFieldLayout = new QHBoxLayout;
    lFieldLayout->addWidget(lIcon);
    lFieldLayout->addWidget(lEdit, 1);
    lFieldLayout->addWidget(lGoTo);
    lFieldLayout->setMargin(0);
    lFieldLayout->setSpacing(5);

    QFrame* lField = new QFrame;
    lField->setObjectName("field");
    lField->setLayout(lFieldLayout);
    
    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->addWidget(lLabel);
    lMainLayout->addWidget(lField, 1);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(10);

    setLayout(lMainLayout);
    
    connect(lIcon, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lEdit, SIGNAL(returnPressed()), this, SLOT(slotItemClick()));
    connect(lGoTo, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GLineEdit::~GLineEdit() {
    
}
//===============================================
// method
//===============================================
void GLineEdit::setContent(QString key, QString text) {
    if(key == "edit") {m_edit->setText(text); if(text == "") {m_goto->setVisible(false);}}
    else if(key == "label") {m_label->setText(text); m_label->setVisible(true);}
}
//===============================================
void GLineEdit::setContent(QString key, int icon, QColor color) {
    if(key == "icon") {m_icon->setIcon(GManager::Instance()->loadPicto(icon, color)); m_icon->setVisible(true);}
    else if(key == "goto") {m_goto->setIcon(GManager::Instance()->loadPicto(icon, color)); m_goto->setVisible(true);}
    else if(key == "label") {m_label->setIcon(GManager::Instance()->loadPicto(icon, color)); m_label->setVisible(true);}
}
//===============================================
void GLineEdit::setContent(QString key, int data) {
    if(key == "icon") {m_icon->setVisible(data);}
    else if(key == "goto") {m_goto->setVisible(data);}
}
//===============================================
void GLineEdit::setOption(QString key, int mode) {
    if(key == "echomode") {m_edit->setEchoMode((QLineEdit::EchoMode)mode);}
    else if(key == "readonly") {m_edit->setReadOnly((bool)mode);}
}
//===============================================
void GLineEdit::getData(QString key, QString& data) {
    if(key == "edit") {data = m_edit->text();}
}
//===============================================
// slot
//===============================================
void GLineEdit::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    emit emitItemClick();
}
//===============================================
