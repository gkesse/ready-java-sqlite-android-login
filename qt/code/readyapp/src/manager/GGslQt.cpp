//===============================================
#include "GGslQt.h"
#include "GWidget.h"
#include "GManager.h"
//===============================================
// constructor
//===============================================
GGslQt::GGslQt(QWidget* parent) : GWidget(parent) {
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
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Equation differentielle (Jacobienne)")->setData("ode_jacobian");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Equation differentielle (Direct)")->setData("ode_direct");
    lSettingMenu->addAction(GManager::Instance()->loadPicto(fa::book, lApp->picto_color), "Equation differentielle (Integrateur)")->setData("ode_integrator");
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
GGslQt::~GGslQt() {

}
//===============================================
// method
//===============================================
void GGslQt::slotItemClick() {
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
void GGslQt::slotItemClick(QAction* action) {
    sGApp* lApp = GManager::Instance()->getData()->app;
    QString lWidgetId = action->data().toString();

    if(lWidgetId == "ode_jacobian") {
        m_plot->clearGraphs();

        double mu = 10;
        gsl_odeiv2_system sys = {onFunction, onJacobian, 2, &mu};
        gsl_odeiv2_driver* d = gsl_odeiv2_driver_alloc_y_new (
        &sys, gsl_odeiv2_step_rk8pd, 1e-6, 1e-6, 0.0);
        int i;
        double t = 0.0, t1 = 100.0;
        double y[2] = { 1.0, 0.0 };

        QVector<double> x1(100), y1(100), y2(100); 

        for (i = 1; i <= 100; i++) {
            double ti = i * t1 / 100.0;
            int status = gsl_odeiv2_driver_apply (d, &t, ti, y);

            if (status != GSL_SUCCESS) {
                printf ("error, return value=%d\n", status);
                break;
            }

            x1[i - 1] = t;
            y1[i - 1] = y[0];
            y2[i - 1] = y[1];            
        }

        double xMin, xMax, yMin, yMax, yMin2, yMax2;
        
        xMin = GManager::Instance()->min(x1);
        xMax = GManager::Instance()->max(x1);
        yMin = GManager::Instance()->min(y1);
        yMin2 = GManager::Instance()->min(y2);
        yMin = qMin(yMin, yMin2);
        yMax = GManager::Instance()->max(y1);
        yMax2 = GManager::Instance()->max(y2);
        //yMax = qMax(yMax, yMax2);
        
        xMin -= 0.2; xMax += 0.2;
        yMin -= 0.2; yMax += 0.2;
        
        m_plot->addGraph();
        m_plot->addGraph();
        // on ajoute des donnees dans le graphe
        m_plot->graph(0)->setData(x1, y1);
        m_plot->graph(1)->setData(x1, y2);
        m_plot->graph(1)->setPen(QPen(Qt::red)); 
        // on definit le label de l'axe (x)
        m_plot->xAxis->setLabel("x");
        // on definit le label de l'axe (y)
        m_plot->yAxis->setLabel("y");
        // on definit les limites de l'axe (x)
        m_plot->xAxis->setRange(xMin, xMax);
        // on definit les limites de l'axe (y)
        m_plot->yAxis->setRange(yMin, yMax);
        // on redessine les graphes
        m_plot->replot();

        gsl_odeiv2_driver_free(d);         
    }
    else if(lWidgetId == "ode_direct") {
        
    }

    lApp->widget_id = lWidgetId;
}
//===============================================
int GGslQt::onFunction(double t, const double y[], double f[], void *params) {
    (void)(t);
    double mu = *(double*)params;
    f[0] = y[1];
    f[1] = -y[0] - mu*y[1]*(y[0]*y[0] - 1);
    return GSL_SUCCESS;
}
//===============================================
int GGslQt::onJacobian(double t, const double y[], double *dfdy, double dfdt[], void *params) {
    (void)(t);
    double mu = *(double *)params;
    gsl_matrix_view dfdy_mat = gsl_matrix_view_array (dfdy, 2, 2);
    gsl_matrix * m = &dfdy_mat.matrix;
    gsl_matrix_set (m, 0, 0, 0.0);
    gsl_matrix_set (m, 0, 1, 1.0);
    gsl_matrix_set (m, 1, 0, -2.0*mu*y[0]*y[1] - 1.0);
    gsl_matrix_set (m, 1, 1, -mu*(y[0]*y[0] - 1.0));
    return GSL_SUCCESS;
}
//===============================================
