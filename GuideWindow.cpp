#include "Headers/GuideWindow.h"

// 设定左侧切换事件
void Ui_GuideWindow::setLeftEvents()
{
    QObject::connect(button_left_1, &QAbstractButton::clicked,
                     [stackedWidget]() { stackedWidget->setCurrentIndex(0); });
    QObject::connect(button_left_2, &QAbstractButton::clicked,
                     [stackedWidget]() { stackedWidget->setCurrentIndex(1); });
    QObject::connect(button_left_3, &QAbstractButton::clicked,
                     [stackedWidget]() { stackedWidget->setCurrentIndex(2); });
    QObject::connect(button_left_4, &QAbstractButton::clicked,
                     [stackedWidget]() { stackedWidget->setCurrentIndex(3); });
    QObject::connect(button_left_5, &QAbstractButton::clicked,
                     [stackedWidget]() { stackedWidget->setCurrentIndex(4); });
}

// 设定导游系统事件
void Ui_GuideWindow::setMainEvents()
{
    QObject::connect(info_button_1, &QAbstractButton::clicked,
                     [info_text_1, info_text_2, info_text_3]() {
                         int num = info_text_1->toPlainText().toInt();
                         string name = info_text_2->toPlainText().toStdString();
                         string info = info_text_3->toPlainText().toStdString();
                         g.setInfo(num, name, info);
                     });
    QObject::connect(info_button_2, &QAbstractButton::clicked,
                     [info_text_4, info_text_5, info_text_6]() {
                         int num1 = info_text_4->toPlainText().toInt();
                         int num2 = info_text_5->toPlainText().toInt();
                         int dis = info_text_6->toPlainText().toInt();
                         g.setPath(num1, num2, dis);
                     });
    QObject::connect(search_button_1, &QAbstractButton::clicked,
                     [search_text_1, search_text_2]() mutable {
                         int num = search_text_1->toPlainText().toInt();
                         string result = "";
                         g.getInfo(num, result);
                         search_text_2->setPlainText(QString::fromStdString(result));
                     });
    QObject::connect(road_button_1, &QAbstractButton::clicked,
                     [road_text_1, road_text_2, road_text_3]() mutable {
                         int num1 = road_text_1->toPlainText().toInt();
                         int num2 = road_text_2->toPlainText().toInt();
                         string result = "";
                         g.getPath(num1, num2, result);
                         result = "从 " + g.vertex[x].place + " 到 " + g.vertex[y].place + " 的最短路径为：\n" + result;
                         road_text_3->setPlainText(QString::fromStdString(result));
                     });
    QObject::connect(multi_button_1, &QAbstractButton::clicked,
                     [multi_text_1, multi_text_2, multi_text_3]() mutable {
                         int num1 = multi_text_1->toPlainText().toInt();
                         int num2 = multi_text_2->toPlainText().toInt();
                         string result = "";
                         g.getAllPath(num1, num2, true, result);
                         result = "从 " + g.vertex[x].place + " 到 " + g.vertex[y].place + " 的所有路径为：\n" + result;
                         multi_text_3->setPlainText(QString::fromStdString(result));
                     });
    QObject::connect(plenty_button_1, &QAbstractButton::clicked,
                     [plenty_text_1, plenty_text_2, plenty_text_3, plenty_text_4]() mutable {
                         int num1 = plenty_text_1->toPlainText().toInt();
                         int num2 = plenty_text_2->toPlainText().toInt();
                         int num3 = plenty_text_3->toPlainText().toInt();
                         string result = "";
                         g.multiPath(num1, num2, num3, result);
                         result = "从 " + g.vertex[x].place + " 经过 " + g.vertex[y].place + " 到 " + g.vertex[z].place + " 的最短路径为：\n" + result;
                         plenty_text_4->setPlainText(QString::fromStdString(result));
                     });
}

// setupUi
void Ui_GuideWindow::setupUi(QMainWindow *GuideWindow)
{
    if (GuideWindow->objectName().isEmpty())
        GuideWindow->setObjectName(QString::fromUtf8("GuideWindow"));
    GuideWindow->resize(800, 600);
    QIcon icon;
    icon.addFile(QString::fromUtf8("Resources/main.png"), QSize(), QIcon::Normal, QIcon::Off);
    GuideWindow->setWindowIcon(icon);
    centralwidget = new QWidget(GuideWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    TitleLabel = new QLabel(centralwidget);
    TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
    TitleLabel->setGeometry(QRect(0, 0, 800, 50));
    QFont font;
    font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font.setPointSize(12);
    font.setBold(true);
    font.setWeight(75);
    TitleLabel->setFont(font);
    TitleLabel->setAlignment(Qt::AlignCenter);
    layoutWidget = new QWidget(centralwidget);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(0, 50, 182, 545));
    Left_Choosing = new QVBoxLayout(layoutWidget);
    Left_Choosing->setObjectName(QString::fromUtf8("Left_Choosing"));
    Left_Choosing->setContentsMargins(0, 0, 0, 0);
    button_left_1 = new QPushButton(layoutWidget);
    button_left_1->setObjectName(QString::fromUtf8("button_left_1"));
    button_left_1->setMinimumSize(QSize(180, 50));
    QIcon icon1;
    icon1.addFile(QString::fromUtf8("Resources/writeinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_1->setIcon(icon1);
    button_left_1->setIconSize(QSize(40, 40));

    Left_Choosing->addWidget(button_left_1);

    button_left_2 = new QPushButton(layoutWidget);
    button_left_2->setObjectName(QString::fromUtf8("button_left_2"));
    button_left_2->setMinimumSize(QSize(180, 50));
    QIcon icon2;
    icon2.addFile(QString::fromUtf8("Resources/searchinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_2->setIcon(icon2);
    button_left_2->setIconSize(QSize(40, 40));

    Left_Choosing->addWidget(button_left_2);

    button_left_3 = new QPushButton(layoutWidget);
    button_left_3->setObjectName(QString::fromUtf8("button_left_3"));
    button_left_3->setMinimumSize(QSize(180, 50));
    QIcon icon3;
    icon3.addFile(QString::fromUtf8("Resources/findroad.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_3->setIcon(icon3);
    button_left_3->setIconSize(QSize(40, 40));

    Left_Choosing->addWidget(button_left_3);

    button_left_4 = new QPushButton(layoutWidget);
    button_left_4->setObjectName(QString::fromUtf8("button_left_4"));
    button_left_4->setMinimumSize(QSize(180, 50));
    button_left_4->setIcon(icon3);
    button_left_4->setIconSize(QSize(40, 40));

    Left_Choosing->addWidget(button_left_4);

    button_left_5 = new QPushButton(layoutWidget);
    button_left_5->setObjectName(QString::fromUtf8("button_left_5"));
    button_left_5->setMinimumSize(QSize(180, 50));
    QIcon icon4;
    icon4.addFile(QString::fromUtf8("Resources/multiplaces.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_5->setIcon(icon4);
    button_left_5->setIconSize(QSize(40, 40));

    Left_Choosing->addWidget(button_left_5);

    pix_label_1 = new QLabel(layoutWidget);
    pix_label_1->setObjectName(QString::fromUtf8("pix_label_1"));
    pix_label_1->setMinimumSize(QSize(180, 180));
    pix_label_1->setPixmap(QPixmap(QString::fromUtf8("Resources/auth.jpg")));
    pix_label_1->setScaledContents(true);

    Left_Choosing->addWidget(pix_label_1);

    pix_label_2 = new QLabel(layoutWidget);
    pix_label_2->setObjectName(QString::fromUtf8("pix_label_2"));
    pix_label_2->setMinimumSize(QSize(150, 32));
    QFont font1;
    font1.setBold(true);
    font1.setWeight(75);
    pix_label_2->setFont(font1);
    pix_label_2->setScaledContents(false);
    pix_label_2->setAlignment(Qt::AlignCenter);

    Left_Choosing->addWidget(pix_label_2);

    pix_label_3 = new QLabel(layoutWidget);
    pix_label_3->setObjectName(QString::fromUtf8("pix_label_3"));
    pix_label_3->setMinimumSize(QSize(150, 32));
    pix_label_3->setFont(font1);
    pix_label_3->setScaledContents(false);
    pix_label_3->setAlignment(Qt::AlignCenter);

    Left_Choosing->addWidget(pix_label_3);

    pix_label_2->raise();
    button_left_1->raise();
    button_left_2->raise();
    button_left_3->raise();
    button_left_4->raise();
    pix_label_1->raise();
    button_left_5->raise();
    pix_label_3->raise();
    stackedWidget = new QStackedWidget(centralwidget);
    stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
    stackedWidget->setGeometry(QRect(200, 50, 600, 530));
    page_1 = new QWidget();
    page_1->setObjectName(QString::fromUtf8("page_1"));
    info_title = new QLabel(page_1);
    info_title->setObjectName(QString::fromUtf8("info_title"));
    info_title->setGeometry(QRect(0, 0, 250, 40));
    QFont font2;
    font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font2.setPointSize(14);
    font2.setBold(true);
    font2.setWeight(75);
    info_title->setFont(font2);
    info_title->setAlignment(Qt::AlignCenter);
    info_label_1 = new QLabel(page_1);
    info_label_1->setObjectName(QString::fromUtf8("info_label_1"));
    info_label_1->setGeometry(QRect(0, 60, 100, 40));
    QFont font3;
    font3.setPointSize(11);
    info_label_1->setFont(font3);
    info_label_1->setAlignment(Qt::AlignCenter);
    info_label_2 = new QLabel(page_1);
    info_label_2->setObjectName(QString::fromUtf8("info_label_2"));
    info_label_2->setGeometry(QRect(300, 60, 100, 40));
    info_label_2->setFont(font3);
    info_label_2->setAlignment(Qt::AlignCenter);
    info_label_3 = new QLabel(page_1);
    info_label_3->setObjectName(QString::fromUtf8("info_label_3"));
    info_label_3->setGeometry(QRect(0, 120, 100, 40));
    info_label_3->setFont(font3);
    info_label_3->setAlignment(Qt::AlignCenter);
    info_text_1 = new QTextEdit(page_1);
    info_text_1->setObjectName(QString::fromUtf8("info_text_1"));
    info_text_1->setGeometry(QRect(100, 64, 180, 32));
    info_text_2 = new QTextEdit(page_1);
    info_text_2->setObjectName(QString::fromUtf8("info_text_2"));
    info_text_2->setGeometry(QRect(400, 64, 180, 32));
    info_text_3 = new QTextEdit(page_1);
    info_text_3->setObjectName(QString::fromUtf8("info_text_3"));
    info_text_3->setGeometry(QRect(100, 124, 480, 200));
    info_button_1 = new QPushButton(page_1);
    info_button_1->setObjectName(QString::fromUtf8("info_button_1"));
    info_button_1->setGeometry(QRect(400, 340, 180, 40));
    QFont font4;
    font4.setPointSize(11);
    font4.setBold(true);
    font4.setWeight(75);
    info_button_1->setFont(font4);
    info_text_5 = new QTextEdit(page_1);
    info_text_5->setObjectName(QString::fromUtf8("info_text_5"));
    info_text_5->setGeometry(QRect(400, 404, 180, 32));
    info_label_5 = new QLabel(page_1);
    info_label_5->setObjectName(QString::fromUtf8("info_label_5"));
    info_label_5->setGeometry(QRect(0, 400, 100, 40));
    info_label_5->setFont(font3);
    info_label_5->setAlignment(Qt::AlignCenter);
    info_text_4 = new QTextEdit(page_1);
    info_text_4->setObjectName(QString::fromUtf8("info_text_4"));
    info_text_4->setGeometry(QRect(100, 404, 180, 32));
    info_label_4 = new QLabel(page_1);
    info_label_4->setObjectName(QString::fromUtf8("info_label_4"));
    info_label_4->setGeometry(QRect(300, 400, 100, 40));
    info_label_4->setFont(font3);
    info_label_4->setAlignment(Qt::AlignCenter);
    info_label_6 = new QLabel(page_1);
    info_label_6->setObjectName(QString::fromUtf8("info_label_6"));
    info_label_6->setGeometry(QRect(0, 460, 100, 40));
    info_label_6->setFont(font3);
    info_label_6->setAlignment(Qt::AlignCenter);
    info_text_6 = new QTextEdit(page_1);
    info_text_6->setObjectName(QString::fromUtf8("info_text_6"));
    info_text_6->setGeometry(QRect(100, 464, 180, 32));
    info_button_2 = new QPushButton(page_1);
    info_button_2->setObjectName(QString::fromUtf8("info_button_2"));
    info_button_2->setGeometry(QRect(400, 460, 180, 40));
    info_button_2->setFont(font4);
    stackedWidget->addWidget(page_1);
    page_2 = new QWidget();
    page_2->setObjectName(QString::fromUtf8("page_2"));
    search_title = new QLabel(page_2);
    search_title->setObjectName(QString::fromUtf8("search_title"));
    search_title->setGeometry(QRect(0, 0, 250, 40));
    search_title->setFont(font2);
    search_title->setAlignment(Qt::AlignCenter);
    search_label_1 = new QLabel(page_2);
    search_label_1->setObjectName(QString::fromUtf8("search_label_1"));
    search_label_1->setGeometry(QRect(0, 60, 100, 40));
    search_label_1->setFont(font3);
    search_label_1->setAlignment(Qt::AlignCenter);
    search_text_1 = new QTextEdit(page_2);
    search_text_1->setObjectName(QString::fromUtf8("search_text_1"));
    search_text_1->setGeometry(QRect(100, 64, 280, 32));
    search_button_1 = new QPushButton(page_2);
    search_button_1->setObjectName(QString::fromUtf8("search_button_1"));
    search_button_1->setGeometry(QRect(400, 60, 180, 40));
    search_button_1->setFont(font4);
    search_text_2 = new QTextEdit(page_2);
    search_text_2->setObjectName(QString::fromUtf8("search_text_2"));
    search_text_2->setGeometry(QRect(0, 120, 580, 410));
    stackedWidget->addWidget(page_2);
    page_3 = new QWidget();
    page_3->setObjectName(QString::fromUtf8("page_3"));
    road_title = new QLabel(page_3);
    road_title->setObjectName(QString::fromUtf8("road_title"));
    road_title->setGeometry(QRect(0, 0, 250, 40));
    road_title->setFont(font2);
    road_title->setAlignment(Qt::AlignCenter);
    road_label_1 = new QLabel(page_3);
    road_label_1->setObjectName(QString::fromUtf8("road_label_1"));
    road_label_1->setGeometry(QRect(0, 60, 100, 40));
    road_label_1->setFont(font3);
    road_label_1->setAlignment(Qt::AlignCenter);
    road_text_1 = new QTextEdit(page_3);
    road_text_1->setObjectName(QString::fromUtf8("road_text_1"));
    road_text_1->setGeometry(QRect(100, 64, 180, 32));
    road_text_2 = new QTextEdit(page_3);
    road_text_2->setObjectName(QString::fromUtf8("road_text_2"));
    road_text_2->setGeometry(QRect(400, 64, 180, 32));
    road_label_2 = new QLabel(page_3);
    road_label_2->setObjectName(QString::fromUtf8("road_label_2"));
    road_label_2->setGeometry(QRect(300, 60, 100, 40));
    road_label_2->setFont(font3);
    road_label_2->setAlignment(Qt::AlignCenter);
    road_text_3 = new QTextEdit(page_3);
    road_text_3->setObjectName(QString::fromUtf8("road_text_3"));
    road_text_3->setGeometry(QRect(0, 180, 580, 350));
    road_button_1 = new QPushButton(page_3);
    road_button_1->setObjectName(QString::fromUtf8("road_button_1"));
    road_button_1->setGeometry(QRect(400, 120, 180, 40));
    road_button_1->setFont(font4);
    stackedWidget->addWidget(page_3);
    page_4 = new QWidget();
    page_4->setObjectName(QString::fromUtf8("page_4"));
    multi_title = new QLabel(page_4);
    multi_title->setObjectName(QString::fromUtf8("multi_title"));
    multi_title->setGeometry(QRect(0, 0, 250, 40));
    multi_title->setFont(font2);
    multi_title->setAlignment(Qt::AlignCenter);
    multi_text_1 = new QTextEdit(page_4);
    multi_text_1->setObjectName(QString::fromUtf8("multi_text_1"));
    multi_text_1->setGeometry(QRect(100, 64, 180, 32));
    multi_label_2 = new QLabel(page_4);
    multi_label_2->setObjectName(QString::fromUtf8("multi_label_2"));
    multi_label_2->setGeometry(QRect(300, 60, 100, 40));
    multi_label_2->setFont(font3);
    multi_label_2->setAlignment(Qt::AlignCenter);
    multi_button_1 = new QPushButton(page_4);
    multi_button_1->setObjectName(QString::fromUtf8("multi_button_1"));
    multi_button_1->setGeometry(QRect(400, 120, 180, 40));
    multi_button_1->setFont(font4);
    multi_label_1 = new QLabel(page_4);
    multi_label_1->setObjectName(QString::fromUtf8("multi_label_1"));
    multi_label_1->setGeometry(QRect(0, 60, 100, 40));
    multi_label_1->setFont(font3);
    multi_label_1->setAlignment(Qt::AlignCenter);
    multi_text_2 = new QTextEdit(page_4);
    multi_text_2->setObjectName(QString::fromUtf8("multi_text_2"));
    multi_text_2->setGeometry(QRect(400, 64, 180, 32));
    multi_text_3 = new QTextEdit(page_4);
    multi_text_3->setObjectName(QString::fromUtf8("multi_text_3"));
    multi_text_3->setGeometry(QRect(0, 180, 580, 350));
    stackedWidget->addWidget(page_4);
    page_5 = new QWidget();
    page_5->setObjectName(QString::fromUtf8("page_5"));
    plenty_text_1 = new QTextEdit(page_5);
    plenty_text_1->setObjectName(QString::fromUtf8("plenty_text_1"));
    plenty_text_1->setGeometry(QRect(100, 64, 180, 32));
    plenty_text_3 = new QTextEdit(page_5);
    plenty_text_3->setObjectName(QString::fromUtf8("plenty_text_3"));
    plenty_text_3->setGeometry(QRect(0, 240, 580, 290));
    plenty_title = new QLabel(page_5);
    plenty_title->setObjectName(QString::fromUtf8("plenty_title"));
    plenty_title->setGeometry(QRect(0, 0, 250, 40));
    plenty_title->setFont(font2);
    plenty_title->setAlignment(Qt::AlignCenter);
    plenty_label_1 = new QLabel(page_5);
    plenty_label_1->setObjectName(QString::fromUtf8("plenty_label_1"));
    plenty_label_1->setGeometry(QRect(0, 60, 100, 40));
    plenty_label_1->setFont(font3);
    plenty_label_1->setAlignment(Qt::AlignCenter);
    plenty_label_2 = new QLabel(page_5);
    plenty_label_2->setObjectName(QString::fromUtf8("plenty_label_2"));
    plenty_label_2->setGeometry(QRect(0, 120, 100, 40));
    plenty_label_2->setFont(font3);
    plenty_label_2->setAlignment(Qt::AlignCenter);
    plenty_button_1 = new QPushButton(page_5);
    plenty_button_1->setObjectName(QString::fromUtf8("plenty_button_1"));
    plenty_button_1->setGeometry(QRect(400, 180, 180, 40));
    plenty_button_1->setFont(font4);
    plenty_text_2 = new QTextEdit(page_5);
    plenty_text_2->setObjectName(QString::fromUtf8("plenty_text_2"));
    plenty_text_2->setGeometry(QRect(100, 124, 180, 32));
    plenty_label_3 = new QLabel(page_5);
    plenty_label_3->setObjectName(QString::fromUtf8("plenty_label_3"));
    plenty_label_3->setGeometry(QRect(0, 180, 100, 40));
    plenty_label_3->setFont(font3);
    plenty_label_3->setAlignment(Qt::AlignCenter);
    plenty_text_4 = new QTextEdit(page_5);
    plenty_text_4->setObjectName(QString::fromUtf8("plenty_text_4"));
    plenty_text_4->setGeometry(QRect(100, 184, 180, 32));
    stackedWidget->addWidget(page_5);
    IconLabel = new QLabel(centralwidget);
    IconLabel->setObjectName(QString::fromUtf8("IconLabel"));
    IconLabel->setGeometry(QRect(200, 1, 48, 48));
    IconLabel->setMinimumSize(QSize(48, 48));
    IconLabel->setPixmap(QPixmap(QString::fromUtf8("Resources/main.png")));
    IconLabel->setScaledContents(true);
    IconLabel->setAlignment(Qt::AlignCenter);
    GuideWindow->setCentralWidget(centralwidget);

    retranslateUi(GuideWindow);

    stackedWidget->setCurrentIndex(0);

    QMetaObject::connectSlotsByName(GuideWindow);
}

// retranslateUi
void Ui_GuideWindow::retranslateUi(QMainWindow *GuideWindow)
{
    GuideWindow->setWindowTitle(QApplication::translate("GuideWindow", "\345\237\272\344\272\216Qt5\347\232\204\346\240\241\345\233\255\345\257\274\346\270\270\347\263\273\347\273\237 v2.0", nullptr));
    TitleLabel->setText(QApplication::translate("GuideWindow", "\345\237\272\344\272\216Qt5\347\232\204\346\240\241\345\233\255\345\257\274\346\270\270\347\263\273\347\273\237 v2.0", nullptr));
    button_left_1->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
    button_left_2->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
    button_left_3->setText(QApplication::translate("GuideWindow", "\346\234\200\347\237\255\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    button_left_4->setText(QApplication::translate("GuideWindow", "\346\211\200\346\234\211\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    button_left_5->setText(QApplication::translate("GuideWindow", "\345\244\232\346\231\257\347\202\271\346\237\245\350\257\242", nullptr));
    pix_label_1->setText(QString());
    pix_label_2->setText(QApplication::translate("GuideWindow", "Powered by Y.Wang", nullptr));
    pix_label_3->setText(QApplication::translate("GuideWindow", "2019.2.18", nullptr));
    info_title->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
    info_label_1->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\347\274\226\345\217\267", nullptr));
    info_label_2->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\345\220\215\347\247\260", nullptr));
    info_label_3->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\347\256\200\344\273\213", nullptr));
    info_button_1->setText(QApplication::translate("GuideWindow", "\345\275\225\345\205\245\344\277\241\346\201\257", nullptr));
    info_label_5->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\350\265\267\347\202\271", nullptr));
    info_label_4->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\347\273\210\347\202\271", nullptr));
    info_label_6->setText(QApplication::translate("GuideWindow", "\351\225\277\345\272\246", nullptr));
    info_button_2->setText(QApplication::translate("GuideWindow", "\345\275\225\345\205\245\351\201\223\350\267\257", nullptr));
    search_title->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
    search_label_1->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\345\220\215\347\247\260", nullptr));
    search_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\346\231\257\347\202\271\344\277\241\346\201\257", nullptr));
    road_title->setText(QApplication::translate("GuideWindow", "\346\234\200\347\237\255\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    road_label_1->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\350\265\267\347\202\271", nullptr));
    road_label_2->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\347\273\210\347\202\271", nullptr));
    road_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
    multi_title->setText(QApplication::translate("GuideWindow", "\346\211\200\346\234\211\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    multi_label_2->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\347\273\210\347\202\271", nullptr));
    multi_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\346\211\200\346\234\211\350\267\257\345\276\204", nullptr));
    multi_label_1->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\350\265\267\347\202\271", nullptr));
    plenty_title->setText(QApplication::translate("GuideWindow", "\345\244\232\346\231\257\347\202\271\346\237\245\350\257\242", nullptr));
    plenty_label_1->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271A", nullptr));
    plenty_label_2->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271B", nullptr));
    plenty_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\345\244\232\346\231\257\347\202\271\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
    plenty_label_3->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271C", nullptr));
    IconLabel->setText(QString());
}