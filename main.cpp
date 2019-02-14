#include "GuideWindow.cpp"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    Ui_GuideWindow ui;
    ui.setupUi(&w);
    ui.setEvents();
    w.show();
    return a.exec();
}
