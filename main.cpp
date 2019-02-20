#include "GuideWindow.cpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow window;
    Ui_GuideWindow ui;
    ui.setupUi(&window);
    ui.setLeftEvents();
    ui.setMainEvents();
    window.show();
    return a.exec();
}
