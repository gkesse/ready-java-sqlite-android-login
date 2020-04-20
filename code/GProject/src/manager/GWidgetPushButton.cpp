//===============================================
#include "GWidgetPushButton.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWidgetPushButton::GWidgetPushButton(QWidget* parent) :
GWidget(parent) {
    __CLASSNAME__ = __FUNCTION__;
    setObjectName("GWidgetPushButton");
    m_label = new QLabel("Label");
    m_label->setObjectName("GLabel");
    m_run = new QPushButton("Run");
    m_run->setCursor(Qt::PointingHandCursor);

    QHBoxLayout* lMainLayout = new QHBoxLayout;
    lMainLayout->setMargin(0);
    lMainLayout->setAlignment(Qt::AlignLeft);
    lMainLayout->addWidget(m_label);
    lMainLayout->addWidget(m_run);

    setLayout(lMainLayout);

    connect(m_run, SIGNAL(clicked()), this, SIGNAL(emitRun()));
}
//===============================================
GWidgetPushButton::~GWidgetPushButton() {

}
//================================================
#endif
//===============================================
