//===============================================
#include "GQCustomPlotQt.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GQCustomPlotQt::GQCustomPlotQt(QWidget* parent) : GWidget(parent) {
    setObjectName("none");
    
    sGApp* lApp = GManager::Instance()->getData()->app;
    
    QPushButton* lSetting = new QPushButton;
    m_setting = lSetting;
    lSetting->setObjectName("button2");
    lSetting->setIcon(GManager::Instance()->loadPicto(fa::cog, lApp->picto_color));
    lSetting->setText("Paramètres");
    lSetting->setCursor(Qt::PointingHandCursor);
    m_widgetId[lSetting] = "setting";
        
    QHBoxLayout* lHeaderLayout = new QHBoxLayout;
    lHeaderLayout->addWidget(lSetting);
    lHeaderLayout->setAlignment(Qt::AlignLeft);
    lHeaderLayout->setMargin(0);
    lHeaderLayout->setSpacing(10);

    QMenu* lSettingMenu = new QMenu(this);
    m_settingMenu = lSettingMenu;
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "1 courbe")->setData("1_curve");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "2 courbes")->setData("2_curve");
    lSettingMenu->setCursor(Qt::PointingHandCursor);
        
    QCustomPlot* lPlot = new QCustomPlot; 
    m_plot = lPlot;
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addLayout(lHeaderLayout);
    lMainLayout->addWidget(lPlot);
    lMainLayout->setMargin(10);
    lMainLayout->setSpacing(10);

    setLayout(lMainLayout);
    
    connect(lSetting, SIGNAL(clicked()), this, SLOT(slotItemClick()));
    connect(lSettingMenu, SIGNAL(triggered(QAction*)), this, SLOT(slotItemClick(QAction*)));
}
//===============================================
GQCustomPlotQt::~GQCustomPlotQt() {

}
//===============================================
// method
//===============================================
void GQCustomPlotQt::slotItemClick() {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QWidget* lWidget = qobject_cast<QWidget*>(sender());
    QString lWidgetId = m_widgetId[lWidget];
    
    if(lWidgetId == "setting") {
        QPoint lPos = QCursor::pos();
        m_settingMenu->exec(lPos);
    }

    lApp->widget_id = m_widgetId[lWidget];
}
//===============================================
void GQCustomPlotQt::slotItemClick(QAction* action) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QString lWidgetId = action->data().toString();

    if(lWidgetId == "1_curve") {
        // on supprime les graphes
        m_plot->clearGraphs();
        
        // on cree les donnees
        QVector<double> x(101), y(101); 
        for (int i= 0; i < 101; i++) {
            x[i] = i/50.0 - 1; 
            y[i] = x[i]*x[i];  
        }
        
        // on ajoute un graphe
        m_plot->addGraph();
        // on ajoute des donnees dans le graphe
        m_plot->graph(0)->setData(x, y);
        // on definit le label de l'axe (x)
        m_plot->xAxis->setLabel("x");
        // on definit le label de l'axe (y)
        m_plot->yAxis->setLabel("y");
        // on definit les limites de l'axe (x)
        m_plot->xAxis->setRange(-1, 1);
        // on definit les limites de l'axe (y)
        m_plot->yAxis->setRange(0, 1);
        // on redessine les graphes
        m_plot->replot();
    }
    else if(lWidgetId == "2_curve") {
        m_plot->clearGraphs();
        
        m_plot->addGraph();
        // on definit la couleur du graph
        m_plot->graph(0)->setPen(QPen(Qt::blue)); 
        // on definit la couleur de la zone entre
        // le graphe et la valeur 0
        m_plot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); 
        m_plot->addGraph();
        m_plot->graph(1)->setPen(QPen(Qt::red)); 

        QVector<double> x(250), y0(250), y1(250);
        for (int i=0; i<250; ++i) {
            x[i] = i;
            y0[i] = qExp(-i/150.0)*qCos(i/10.0); 
            y1[i] = qExp(-i/150.0);              
        }

        // on affiche le 2eme axe (x)
        m_plot->xAxis2->setVisible(true);
        // on affiche les labels des ticks du 2eme axe (x)
        m_plot->xAxis2->setTickLabels(true);
        // on affiche le 2eme axe (y)
        m_plot->yAxis2->setVisible(true);
        // on affiche les labels des ticks du 2eme axe (y)
        m_plot->yAxis2->setTickLabels(true);

        // on definit la connexion entre le 1er et le 2eme axe (x)
        // en cas de changement des limites
        connect(m_plot->xAxis, SIGNAL(rangeChanged(QCPRange)), m_plot->xAxis2, SLOT(setRange(QCPRange)));
        // on definit la connexion entre le 1er et le 2eme axe (y)
        // en cas de changement des limites
        connect(m_plot->yAxis, SIGNAL(rangeChanged(QCPRange)), m_plot->yAxis2, SLOT(setRange(QCPRange)));

        m_plot->graph(0)->setData(x, y0);
        m_plot->graph(1)->setData(x, y1);

        m_plot->graph(0)->rescaleAxes();
        m_plot->graph(1)->rescaleAxes(true);
        // on definit les intercations avec le graphe
        // on active le deplacement des graphes (iRangeDrag)
        // on active le zoom des graphes (iRangeZoom)
        // on active la selection des graphex (iRangeZoom)
        m_plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
        m_plot->replot();
    }
    
    lApp->widget_id = lWidgetId;
}
//===============================================
