//===============================================
#include "GTableWidget.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GTableWidget::GTableWidget(QWidget* parent) : GWidget(parent) {
    setObjectName("GTableWidget");
        
    QTableWidget* lTableWidget = new QTableWidget;
    m_tableWidget = lTableWidget;
    lTableWidget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    lTableWidget->setCursor(Qt::PointingHandCursor);
    
    QVBoxLayout* lMainLatout = new QVBoxLayout;
    lMainLatout->addWidget(lTableWidget);
    lMainLatout->setAlignment(Qt::AlignTop);
    lMainLatout->setMargin(0);
    lMainLatout->setSpacing(0);
    
    setLayout(lMainLatout);
}
//===============================================
GTableWidget::~GTableWidget() {
    
}
//===============================================
// method
//===============================================
void GTableWidget::setOption(QString key, int data) {
    if(key == "rows") m_tableWidget->setRowCount(data);
    else if(key == "cols") m_tableWidget->setColumnCount(data);
    else if(key == "header_h_ls") m_tableWidget->horizontalHeader()->setStretchLastSection(data);
    else if(key == "header_v_ls") m_tableWidget->verticalHeader()->setStretchLastSection(data);
}
//===============================================
void GTableWidget::setOption(QString key) {
    if(key == "header_h_on") m_tableWidget->horizontalHeader()->show();
    else if(key == "header_h_off") m_tableWidget->horizontalHeader()->hide();
    else if(key == "header_v_on") m_tableWidget->verticalHeader()->show();
    else if(key == "header_v_off") m_tableWidget->verticalHeader()->hide();
}
//===============================================
void GTableWidget::addItem(int row, int col, QString text) {
    QTableWidgetItem* lItem = new QTableWidgetItem(text);
    lItem->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    m_tableWidget->setItem(row, col, lItem);
}
//===============================================
void GTableWidget::addItem(QString key, QString text, int icon) {

}
//===============================================
void GTableWidget::addItem(QLayout* layout) {

}
//===============================================
void GTableWidget::removeItem(int index) {

}
//===============================================
// slot
//===============================================
void GTableWidget::slotItemClick() {

}
//===============================================