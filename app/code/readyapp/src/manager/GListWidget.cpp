//===============================================
#include "GListWidget.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GListWidget::GListWidget(QWidget* parent) : GWidget(parent) {
    setObjectName("GListWidget");
        
    QListWidget* lListWidget = new QListWidget;
    m_listWidget = lListWidget;
    lListWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    lListWidget->setCursor(Qt::PointingHandCursor);
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lListWidget);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GListWidget::~GListWidget() {
    
}
//===============================================
// method
//===============================================
void GListWidget::addItem(QString key, QString text) {
    QPushButton* lButton = new QPushButton(m_listWidget);
    lButton->setObjectName("row");
    lButton->setText(text);
    m_widgetId[lButton] = key;

    QListWidgetItem* lItem = new QListWidgetItem(m_listWidget);
    m_rowId[m_index++] = lItem;
    
    m_listWidget->addItem(lItem);
    m_listWidget->setItemWidget(lItem, lButton);

    connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
void GListWidget::addItem(QString key, QString text, int icon) {
    sGApp* lApp = GManager::Instance()->getData()->app;

    QPushButton* lButton = new QPushButton(m_listWidget);
    lButton->setObjectName("row");
    lButton->setText(text);
    lButton->setIcon(GManager::Instance()->loadPicto(icon, lApp->picto_color));
    m_widgetId[lButton] = key;

    QListWidgetItem* lItem = new QListWidgetItem(m_listWidget);
     m_rowId[m_index++] = lItem;
   
    m_listWidget->addItem(lItem);
    m_listWidget->setItemWidget(lItem, lButton);

    connect(lButton, SIGNAL(clicked()), this, SLOT(slotItemClick()));
}
//===============================================
void GListWidget::addItem(QLayout* layout) {
    QFrame* lRow = new QFrame(m_listWidget);
    lRow->setObjectName("row");
    lRow->setLayout(layout);

    QListWidgetItem* lItem = new QListWidgetItem(m_listWidget);
    m_rowId[m_index++] = lItem;
    
    m_listWidget->addItem(lItem);
    m_listWidget->setItemWidget(lItem, lRow);
}
//===============================================
void GListWidget::removeItem(int index) {
    QListWidgetItem* lItem = m_rowId[index];
    m_listWidget->removeItemWidget(lItem);
    delete lItem;
}
//===============================================
// slot
//===============================================
void GListWidget::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    lApp->widget_id = m_widgetId[lWidget];
    emit emitItemClick();
}
//===============================================