//===============================================
#include <QApplication>
#include <QtWidgets>
//===============================================
int main(int argc, char** argv) {
    QApplication lApp(argc, argv);
    QWidget* lWindow = new QWidget;
    lWindow->resize(640, 480);
    lWindow->show();
    return lApp.exec();
}
//===============================================
