//===============================================
#include "GDemo.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GDemo::GDemo(QWidget* parent) : GWidget(parent) {    
    setObjectName("none");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    GWidget* lListBox = GWidget::Create("listbox");
    
    lListBox->addItem("home/demo/opencv", "OpenCV", fa::book);
    lListBox->addItem("home/demo/opengl", "OpenGL", fa::book);
    lListBox->addItem("home/demo/gsl", "GSL", fa::book); 
    lListBox->addItem("home/demo/qt", "Qt", fa::book);
    lListBox->addItem("home/demo/qcustomplot", "QCustomPlot", fa::book); lApp->login_home = qobject_cast<QPushButton*>(lApp->widget);

    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lListBox);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
    
    connect(lListBox, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
}
//===============================================
GDemo::~GDemo() {
    
}
//===============================================
// slot
//===============================================
void GDemo::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    GManager::Instance()->setPage(lApp->widget_id);
}
//===============================================
