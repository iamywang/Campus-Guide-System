#include "Headers/GuideWindow.h"

void Ui_GuideWindow::setEvents()
{
    QObject::connect(button_left_1, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(0); });
    QObject::connect(button_left_2, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(1); });
    QObject::connect(button_left_3, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(2); });
    QObject::connect(button_left_4, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(3); });
    QObject::connect(info_button_1, &QAbstractButton::clicked, [=]() mutable {});
    QObject::connect(info_button_2, &QAbstractButton::clicked, [=]() mutable {});
    QObject::connect(search_button_1, &QAbstractButton::clicked, [=]() mutable {});
    QObject::connect(road_button_1, &QAbstractButton::clicked,[=]() mutable {});
    QObject::connect(multi_button_1, &QAbstractButton::clicked,[=]() mutable {});
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;
    Ui_GuideWindow ui;
    ui.setupUi(&w);
    w.show();
    return a.exec();
}
