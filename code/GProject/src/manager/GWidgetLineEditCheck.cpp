//===============================================
#include "GWidgetLineEditCheck.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWidgetLineEditCheck::GWidgetLineEditCheck(QWidget* parent) :
GWidget(parent) {
    __CLASSNAME__ = __FUNCTION__;
    setObjectName("GWidgetLineEditCheck");
    m_label = new QLabel("Label");
    m_label->setObjectName("GLabel");
    m_lineEidt = new QLineEdit;
    m_check = new QCheckBox;
    m_check->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->setMargin(0);
    lMainLayout->addWidget(m_label);
    lMainLayout->addWidget(m_lineEidt, 1);
    lMainLayout->addWidget(m_check);

    setLayout(lMainLayout);

    connect(m_check, SIGNAL(clicked(bool)), this, SLOT(slotCheck(bool)));

    slotCheck(false);
}
//===============================================
GWidgetLineEditCheck::~GWidgetLineEditCheck() {

}
//================================================
#endif
//===============================================
