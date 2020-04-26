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
    m_customPlot->setBackground(Qt::transparent);
    //
    m_customPlot->xAxis->setBasePen(QPen(QColor("#b2cec3")));
    m_customPlot->xAxis->setLabelColor("#b2cec3");
    m_customPlot->xAxis->setSubTickPen(QPen(QColor("#b2cec3")));
    m_customPlot->xAxis->setTickLabelColor("#b2cec3");
    m_customPlot->xAxis->setTickPen(QPen(QColor("#b2cec3")));
    m_customPlot->xAxis->grid()->setPen(QPen(QColor("#b2cec3"), 1, Qt::DotLine));
    //
    m_customPlot->yAxis->setBasePen(QPen(QColor("#b2cec3")));
    m_customPlot->yAxis->setLabelColor("#b2cec3");
    m_customPlot->yAxis->setSubTickPen(QPen(QColor("#b2cec3")));
    m_customPlot->yAxis->setTickLabelColor("#b2cec3");
    m_customPlot->yAxis->setTickPen(QPen(QColor("#b2cec3")));
    m_customPlot->yAxis->grid()->setPen(QPen(QColor("#b2cec3"), 1, Qt::DotLine));

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
