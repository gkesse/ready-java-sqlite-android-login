//===============================================
#include <QApplication>
#include <QtWidgets>
//===============================================
int main(int argc, char** argv) {
    QApplication app(argc, argv);
    
    QWidget* lWindow = new QWidget;
    
    QLabel* lLabel = new QLabel(lWindow);
    lLabel->setText("Bonjour tout le monde");
    lLabel->move(150, 90);
    lWindow->show();
    lWindow->resize(400, 200);
    lWindow->setWindowTitle("ReadyApp");
    
    return app.exec();
}
//===============================================
