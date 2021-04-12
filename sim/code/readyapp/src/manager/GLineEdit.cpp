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
void GLineEdit::setLabel(QString text) {
    m_label->setText(text);
    m_label->setVisible(true);
}
//===============================================
void GLineEdit::setLabelWidth(int width) {
    m_label->setStyleSheet(QString("\
    QPushButton {\n\
        min-width: %1px;\n\
    }\n\
    ").arg(width));
}
//===============================================
void GLineEdit::setLabelIcon(int icon, QColor color) {
    m_label->setIcon(GManager::Instance()->loadPicto(icon, color)); 
}
//===============================================
void GLineEdit::setGoToIcon(int icon, QColor color) {
    m_goto->setIcon(GManager::Instance()->loadPicto(icon, color)); 
    m_goto->setVisible(true);
}
//===============================================
void GLineEdit::setIcon(int icon, QColor color) {
    m_icon->setIcon(GManager::Instance()->loadPicto(icon, color)); 
    m_icon->setVisible(true);
}
//===============================================
void GLineEdit::setText(QString text) {
    m_edit->setText(text); 
}
//===============================================
void GLineEdit::setEchoMode(int mode) {
    m_edit->setEchoMode((QLineEdit::EchoMode)mode);
}
//===============================================
void GLineEdit::setReadOnly(bool flag) {
    m_edit->setReadOnly(flag);
}
//===============================================
QString GLineEdit::getText() {
    return m_edit->text();
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
