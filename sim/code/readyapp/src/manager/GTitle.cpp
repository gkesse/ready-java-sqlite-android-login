//===============================================
#include "GTitle.h"
#include "GManager.h"
//===============================================
GTitle::GTitle(QWidget* parent) : GWidget(parent) {
    setObjectName("GTitle");
        
    QPushButton* lTitle = new QPushButton;
    m_title = lTitle;
    lTitle->setObjectName("title");
    lTitle->setText("Ajouter un titre");
    m_widgetId[lTitle] = "title";
    
    QPushButton* lClose = new QPushButton;
    lClose->setIcon(GManager::Instance()->loadPicto(fa::times));
    lClose->setCursor(Qt::PointingHandCursor);
    m_widgetId[lClose] = "close";

    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->addWidget(lTitle, 1);
    lMainLayout->addWidget(lClose);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);

    setLayout(lMainLayout);
    
    connect(lTitle, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lClose, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
GTitle::~GTitle() {
    
}
//===============================================
// method
//===============================================
void GTitle::setTitle(QString text) {
    m_title->setText(text);
}
//===============================================
void GTitle::setTitleIcon(int icon) {
    m_title->setIcon(GManager::Instance()->loadPicto(icon));
}
//===============================================
// slot
//===============================================
void GTitle::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    emit emitItemClick();
}
//===============================================
