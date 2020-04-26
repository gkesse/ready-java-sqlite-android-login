//===============================================
#include "GWidgetPlot.h"
#include "GDebug.h"
//===============================================
#if defined(_GUSE_QT_ON_)
//===============================================
GWidgetPlot::GWidgetPlot(QWidget* parent) :
GWidget(parent) {
    __CLASSNAME__ = __FUNCTION__;
    setObjectName("GWidgetPlot");
    m_clear = new QPushButton("Clear");
    m_clear->setCursor(Qt::PointingHandCursor);
    m_customPlot = new QCustomPlot;

    QHBoxLayout* lTopLayout = new QHBoxLayout;
    lTopLayout->setAlignment(Qt::AlignLeft);
    lTopLayout->setMargin(0);
    lTopLayout->setMargin(0);
    lTopLayout->addWidget(m_clear);

    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->setMargin(0);
    lMainLayout->addLayout(lTopLayout);
    lMainLayout->addWidget(m_customPlot);

    setLayout(lMainLayout);

    //connect(m_clear, SIGNAL(clicked()), m_textEdit, SLOT(clear()));
}
//===============================================
GWidgetPlot::~GWidgetPlot() {

}
//================================================
QCustomPlot* GWidgetPlot::plot() {
	return m_customPlot;
}
//================================================
#endif
//===============================================
