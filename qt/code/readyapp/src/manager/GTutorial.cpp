//===============================================
#include "GTutorial.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GTutorial::GTutorial(QWidget* parent) : GWidget(parent) {    
    setObjectName("none");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    GWidget* lListBox = GWidget::Create("listbox");
    
    lListBox->addItem("home/tuto/qt", "Qt", fa::windows);
    lListBox->addItem("home/tuto/opencv", "OpenCV", fa::camera);
    lListBox->addItem("home/tuto/opengl", "OpenGL", fa::camera);
    lListBox->addItem("home/tuto/gsl", "GSL", fa::book); 
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lListBox);
    lMainLayout->setAlignment(Qt::AlignTop);
    lMainLayout->setMargin(0);
    lMainLayout->setSpacing(0);
    
    setLayout(lMainLayout);
    
    connect(lListBox, SIGNAL(emitItemClick()), this, SLOT(slotItemClick()));
}
//===============================================
GTutorial::~GTutorial() {
    
}
//===============================================
// slot
//===============================================
void GTutorial::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    GManager::Instance()->setPage(lApp->widget_id);
}
//===============================================
