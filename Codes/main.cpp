#include "ui_guideWindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    Ui_GuideWindow ui;
    ui.setupUi(&w);
    w.show();
    return a.exec();
}
