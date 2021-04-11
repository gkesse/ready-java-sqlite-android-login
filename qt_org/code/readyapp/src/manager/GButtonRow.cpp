//===============================================
#include "GButtonRow.h"
#include "GManager.h"
//===============================================
GButtonRow::GButtonRow(QWidget* parent) : GWidget(parent) {
    setObjectName("GButtonRow");
        
    QHBoxLayout* lMainLayout = new QHBoxLayout;
    m_mainLayout = lMainLayout;
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(10);

    setLayout(lMainLayout);    
}
//===============================================
GButtonRow::~GButtonRow() {
    
}
//===============================================
// method
//===============================================
void GButtonRow::addItem(QString key, QString text) {
    QPushButton* lButton = new QPushButton;
    lButton->setObjectName("button");
    lButton->setText(text);
    lButton->setCursor(Qt::PointingHandCursor);
    m_widgetId[lButton] = key;
    
    m_mainLayout->addWidget(lButton);
    
    connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
void GButtonRow::addItem(QString key, QString text, int icon) {
    QPushButton* lButton = new QPushButton;
    lButton->setObjectName("button");
    lButton->setIcon(GManager::Instance()->loadPicto(icon));
    lButton->setText(text);
    lButton->setCursor(Qt::PointingHandCursor);
    m_widgetId[lButton] = key;
    
    m_mainLayout->addWidget(lButton);
    
    connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
void GButtonRow::setAlignment(int alignment) {
    m_mainLayout->setAlignment((Qt::AlignmentFlag)alignment);
}
//===============================================
// slot
//===============================================
void GButtonRow::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    emit emitItemClick();
}
//===============================================
