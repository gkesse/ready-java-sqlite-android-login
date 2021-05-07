//===============================================
#include <QApplication>
#include <qcustomplot.h>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    
    // on cree les donnees
    QVector<double> x(101), y(101); 
    for (int i= 0; i < 101; i++) {
        x[i] = i/50.0 - 1; 
        y[i] = x[i]*x[i];  
    }
    
    // on cree le gestionnaire de trace
    QCustomPlot* lCustomPlot = new QCustomPlot;
    // on ajoute un graphe
    lCustomPlot->addGraph();
    // on ajoute des donnees dans le graphe
    lCustomPlot->graph(0)->setData(x, y);
    // on definit le label de l'axe (x)
    lCustomPlot->xAxis->setLabel("x");
    // on definit le label de l'axe (y)
    lCustomPlot->yAxis->setLabel("y");
    // on definit les limites de l'axe (x)
    lCustomPlot->xAxis->setRange(-1, 1);
    // on definit les limites de l'axe (y)
    lCustomPlot->yAxis->setRange(0, 1);
    
    lCustomPlot->setWindowTitle("ReadyApp");
    lCustomPlot->resize(400, 200);
    lCustomPlot->show();
    
    return app.exec();
}
//===============================================
