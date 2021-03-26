//===============================================
#include <QApplication>
#include <QtWidgets>
//===============================================
int main(int argc, char** argv) {
    QApplication lApp(argc, argv);
    
    QWidget* lWindow = new QWidget;
    
    QLabel* lLabel = new QLabel;
    lLabel->setText("Bonjour tout le monde");
    lLabel->setAlignment(Qt::AlignCenter);
    
    QVBoxLayout* lMainLayout = new QVBoxLayout;
    lMainLayout->addWidget(lLabel);
    
    lWindow->setLayout(lMainLayout);
    lWindow->resize(400, 200);
    lWindow->setWindowTitle("ReadyApp");
    
    lWindow->show();
    return lApp.exec();
}
//===============================================
