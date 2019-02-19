#include "Headers/GuideWindow.h"

// 设定左侧切换事件
void Ui_GuideWindow::setLeftEvents()
{
    QObject::connect(button_left_1, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(0); });
    QObject::connect(button_left_2, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(1); });
    QObject::connect(button_left_3, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(2); });
    QObject::connect(button_left_4, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(3); });
    QObject::connect(button_left_5, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(4); });
    QObject::connect(button_left_6, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(5); });
}

// 设定导游系统事件
void Ui_GuideWindow::setMainEvents()
{
    // 信息录入
    QObject::connect(info_button_1, &QAbstractButton::clicked, [=]() mutable {
        int num = info_text_1->toPlainText().toInt();
        string name = info_text_2->toPlainText().toStdString();
        string info = info_text_3->toPlainText().toStdString();
        g.setInfo(num, name, info);
    });
    // 道路录入
    QObject::connect(info_button_2, &QAbstractButton::clicked, [=]() mutable {
        int num1 = info_text_4->toPlainText().toInt();
        int num2 = info_text_5->toPlainText().toInt();
        int dis = info_text_6->toPlainText().toInt();
        g.setPath(num1, num2, dis);
    });
    // 删除景点
    QObject::connect(info_button_3, &QAbstractButton::clicked, [=]() mutable {
        int num = info_text_1->toPlainText().toInt();
        g.delInfo(num);
    });
    // 删除道路
    QObject::connect(info_button_4, &QAbstractButton::clicked, [=]() mutable {
        int num1 = info_text_4->toPlainText().toInt();
        int num2 = info_text_5->toPlainText().toInt();
        g.delPath(num1, num2);
    });
    // 查询景点信息
    QObject::connect(search_button_1, &QAbstractButton::clicked, [=]() mutable {
        int num = search_text_1->toPlainText().toInt();
        string result = g.getInfo(num);
        search_text_2->setPlainText(QString::fromStdString(result));
    });
    // 查询最短路径
    QObject::connect(road_button_1, &QAbstractButton::clicked, [=]() mutable {
        int x = road_text_1->toPlainText().toInt();
        int y = road_text_2->toPlainText().toInt();
        string result = "";
        g.getPath(x, y, result);
        result = "从 " + g.vertex[x].place + " 到 " + g.vertex[y].place + " 的最短路径为：\n" + result;
        road_text_3->setPlainText(QString::fromStdString(result));
    });
    // 查询所有路径
    QObject::connect(multi_button_1, &QAbstractButton::clicked, [=]() mutable {
        int x = multi_text_1->toPlainText().toInt();
        int y = multi_text_2->toPlainText().toInt();
        string result = "";
        g.getAllPath(x, y, true, result);
        result = "从 " + g.vertex[x].place + " 到 " + g.vertex[y].place + " 的所有路径为：\n" + result;
        multi_text_3->setPlainText(QString::fromStdString(result));
    });
    // 多景点
    QObject::connect(plenty_button_1, &QAbstractButton::clicked, [=]() mutable {
        int x = plenty_text_1->toPlainText().toInt();
        int y = plenty_text_2->toPlainText().toInt();
        int z = plenty_text_3->toPlainText().toInt();
        string result = "";
        g.multiPath(x, y, z, result);
        result = "从 " + g.vertex[x].place + " 经过 " + g.vertex[y].place + " 到 " + g.vertex[z].place + " 的最短路径为：\n" + result;
        plenty_text_4->setPlainText(QString::fromStdString(result));
    });
}

// setupUi
void Ui_GuideWindow::setupUi(QMainWindow *GuideWindow)
{
    if (GuideWindow->objectName().isEmpty())
        GuideWindow->setObjectName(QString::fromUtf8("GuideWindow"));
    GuideWindow->resize(1000, 750);
    GuideWindow->setMinimumSize(QSize(1000, 750));
    QIcon icon;
    icon.addFile(QString::fromUtf8("Resources/main.png"), QSize(), QIcon::Normal, QIcon::Off);
    GuideWindow->setWindowIcon(icon);
    centralwidget = new QWidget(GuideWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setMinimumSize(QSize(1000, 750));
    TitleLabel = new QLabel(centralwidget);
    TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
    TitleLabel->setGeometry(QRect(0, 0, 1000, 64));
    QFont font;
    font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font.setPointSize(16);
    font.setBold(true);
    font.setWeight(75);
    TitleLabel->setFont(font);
    TitleLabel->setAlignment(Qt::AlignCenter);
    layoutWidget = new QWidget(centralwidget);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(0, 60, 202, 682));
    QFont font1;
    font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    layoutWidget->setFont(font1);
    Left_Choosing = new QVBoxLayout(layoutWidget);
    Left_Choosing->setSpacing(7);
    Left_Choosing->setObjectName(QString::fromUtf8("Left_Choosing"));
    Left_Choosing->setContentsMargins(0, 0, 0, 0);
    button_left_1 = new QPushButton(layoutWidget);
    button_left_1->setObjectName(QString::fromUtf8("button_left_1"));
    button_left_1->setMinimumSize(QSize(200, 60));
    QFont font2;
    font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font2.setBold(true);
    font2.setWeight(75);
    button_left_1->setFont(font2);
    QIcon icon1;
    icon1.addFile(QString::fromUtf8("Resources/writeinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_1->setIcon(icon1);
    button_left_1->setIconSize(QSize(48, 48));

    Left_Choosing->addWidget(button_left_1);

    button_left_2 = new QPushButton(layoutWidget);
    button_left_2->setObjectName(QString::fromUtf8("button_left_2"));
    button_left_2->setMinimumSize(QSize(200, 60));
    button_left_2->setFont(font2);
    QIcon icon2;
    icon2.addFile(QString::fromUtf8("Resources/searchinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_2->setIcon(icon2);
    button_left_2->setIconSize(QSize(48, 48));

    Left_Choosing->addWidget(button_left_2);

    button_left_3 = new QPushButton(layoutWidget);
    button_left_3->setObjectName(QString::fromUtf8("button_left_3"));
    button_left_3->setMinimumSize(QSize(200, 60));
    button_left_3->setFont(font2);
    QIcon icon3;
    icon3.addFile(QString::fromUtf8("Resources/findroad.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_3->setIcon(icon3);
    button_left_3->setIconSize(QSize(48, 48));

    Left_Choosing->addWidget(button_left_3);

    button_left_4 = new QPushButton(layoutWidget);
    button_left_4->setObjectName(QString::fromUtf8("button_left_4"));
    button_left_4->setMinimumSize(QSize(200, 60));
    button_left_4->setFont(font2);
    QIcon icon4;
    icon4.addFile(QString::fromUtf8("Resources/allroad.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_4->setIcon(icon4);
    button_left_4->setIconSize(QSize(48, 48));

    Left_Choosing->addWidget(button_left_4);

    button_left_5 = new QPushButton(layoutWidget);
    button_left_5->setObjectName(QString::fromUtf8("button_left_5"));
    button_left_5->setMinimumSize(QSize(200, 60));
    button_left_5->setFont(font2);
    QIcon icon5;
    icon5.addFile(QString::fromUtf8("Resources/multiplaces.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_5->setIcon(icon5);
    button_left_5->setIconSize(QSize(48, 48));

    Left_Choosing->addWidget(button_left_5);

    button_left_6 = new QPushButton(layoutWidget);
    button_left_6->setObjectName(QString::fromUtf8("button_left_6"));
    button_left_6->setMinimumSize(QSize(200, 60));
    button_left_6->setFont(font2);
    QIcon icon6;
    icon6.addFile(QString::fromUtf8("Resources/about.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_6->setIcon(icon6);
    button_left_6->setIconSize(QSize(48, 48));

    Left_Choosing->addWidget(button_left_6);

    pix_label_1 = new QLabel(layoutWidget);
    pix_label_1->setObjectName(QString::fromUtf8("pix_label_1"));
    pix_label_1->setMinimumSize(QSize(200, 200));
    pix_label_1->setFont(font1);
    pix_label_1->setPixmap(QPixmap(QString::fromUtf8("Resources/auth.jpg")));
    pix_label_1->setScaledContents(true);

    Left_Choosing->addWidget(pix_label_1);

    pix_label_2 = new QLabel(layoutWidget);
    pix_label_2->setObjectName(QString::fromUtf8("pix_label_2"));
    pix_label_2->setMinimumSize(QSize(200, 32));
    pix_label_2->setFont(font2);
    pix_label_2->setScaledContents(false);
    pix_label_2->setAlignment(Qt::AlignCenter);

    Left_Choosing->addWidget(pix_label_2);

    pix_label_3 = new QLabel(layoutWidget);
    pix_label_3->setObjectName(QString::fromUtf8("pix_label_3"));
    pix_label_3->setMinimumSize(QSize(200, 32));
    pix_label_3->setFont(font2);
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
    button_left_6->raise();
    stackedWidget = new QStackedWidget(centralwidget);
    stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
    stackedWidget->setGeometry(QRect(202, 70, 800, 680));
    stackedWidget->setFont(font1);
    page_1 = new QWidget();
    page_1->setObjectName(QString::fromUtf8("page_1"));
    info_title = new QLabel(page_1);
    info_title->setObjectName(QString::fromUtf8("info_title"));
    info_title->setGeometry(QRect(0, 0, 250, 40));
    QFont font3;
    font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font3.setPointSize(14);
    font3.setBold(true);
    font3.setWeight(75);
    info_title->setFont(font3);
    info_title->setAlignment(Qt::AlignCenter);
    info_label_1 = new QLabel(page_1);
    info_label_1->setObjectName(QString::fromUtf8("info_label_1"));
    info_label_1->setGeometry(QRect(0, 60, 150, 40));
    QFont font4;
    font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font4.setPointSize(11);
    info_label_1->setFont(font4);
    info_label_1->setAlignment(Qt::AlignCenter);
    info_label_2 = new QLabel(page_1);
    info_label_2->setObjectName(QString::fromUtf8("info_label_2"));
    info_label_2->setGeometry(QRect(0, 120, 150, 40));
    info_label_2->setFont(font4);
    info_label_2->setAlignment(Qt::AlignCenter);
    info_label_3 = new QLabel(page_1);
    info_label_3->setObjectName(QString::fromUtf8("info_label_3"));
    info_label_3->setGeometry(QRect(0, 180, 150, 40));
    info_label_3->setFont(font4);
    info_label_3->setAlignment(Qt::AlignCenter);
    info_text_1 = new QTextEdit(page_1);
    info_text_1->setObjectName(QString::fromUtf8("info_text_1"));
    info_text_1->setGeometry(QRect(150, 64, 410, 32));
    info_text_1->setFont(font1);
    info_text_2 = new QTextEdit(page_1);
    info_text_2->setObjectName(QString::fromUtf8("info_text_2"));
    info_text_2->setGeometry(QRect(150, 124, 630, 32));
    info_text_2->setFont(font1);
    info_text_3 = new QTextEdit(page_1);
    info_text_3->setObjectName(QString::fromUtf8("info_text_3"));
    info_text_3->setGeometry(QRect(150, 184, 630, 180));
    info_text_3->setFont(font1);
    info_button_1 = new QPushButton(page_1);
    info_button_1->setObjectName(QString::fromUtf8("info_button_1"));
    info_button_1->setGeometry(QRect(580, 390, 200, 40));
    QFont font5;
    font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font5.setPointSize(11);
    font5.setBold(true);
    font5.setWeight(75);
    info_button_1->setFont(font5);
    info_text_5 = new QTextEdit(page_1);
    info_text_5->setObjectName(QString::fromUtf8("info_text_5"));
    info_text_5->setGeometry(QRect(550, 514, 230, 32));
    info_text_5->setFont(font1);
    info_label_5 = new QLabel(page_1);
    info_label_5->setObjectName(QString::fromUtf8("info_label_5"));
    info_label_5->setGeometry(QRect(0, 510, 150, 40));
    info_label_5->setFont(font4);
    info_label_5->setAlignment(Qt::AlignCenter);
    info_text_4 = new QTextEdit(page_1);
    info_text_4->setObjectName(QString::fromUtf8("info_text_4"));
    info_text_4->setGeometry(QRect(150, 514, 230, 32));
    info_text_4->setFont(font1);
    info_label_4 = new QLabel(page_1);
    info_label_4->setObjectName(QString::fromUtf8("info_label_4"));
    info_label_4->setGeometry(QRect(400, 510, 150, 40));
    info_label_4->setFont(font4);
    info_label_4->setAlignment(Qt::AlignCenter);
    info_label_6 = new QLabel(page_1);
    info_label_6->setObjectName(QString::fromUtf8("info_label_6"));
    info_label_6->setGeometry(QRect(0, 570, 150, 40));
    info_label_6->setFont(font4);
    info_label_6->setAlignment(Qt::AlignCenter);
    info_text_6 = new QTextEdit(page_1);
    info_text_6->setObjectName(QString::fromUtf8("info_text_6"));
    info_text_6->setGeometry(QRect(150, 574, 630, 32));
    info_text_6->setFont(font1);
    info_button_2 = new QPushButton(page_1);
    info_button_2->setObjectName(QString::fromUtf8("info_button_2"));
    info_button_2->setGeometry(QRect(360, 620, 200, 40));
    info_button_2->setFont(font5);
    info_title_2 = new QLabel(page_1);
    info_title_2->setObjectName(QString::fromUtf8("info_title_2"));
    info_title_2->setGeometry(QRect(0, 450, 250, 40));
    info_title_2->setFont(font3);
    info_title_2->setAlignment(Qt::AlignCenter);
    info_button_3 = new QPushButton(page_1);
    info_button_3->setObjectName(QString::fromUtf8("info_button_3"));
    info_button_3->setGeometry(QRect(580, 60, 200, 40));
    info_button_3->setFont(font5);
    info_button_4 = new QPushButton(page_1);
    info_button_4->setObjectName(QString::fromUtf8("info_button_4"));
    info_button_4->setGeometry(QRect(580, 620, 200, 40));
    info_button_4->setFont(font5);
    stackedWidget->addWidget(page_1);
    page_2 = new QWidget();
    page_2->setObjectName(QString::fromUtf8("page_2"));
    search_title = new QLabel(page_2);
    search_title->setObjectName(QString::fromUtf8("search_title"));
    search_title->setGeometry(QRect(0, 0, 250, 40));
    search_title->setFont(font3);
    search_title->setAlignment(Qt::AlignCenter);
    search_label_1 = new QLabel(page_2);
    search_label_1->setObjectName(QString::fromUtf8("search_label_1"));
    search_label_1->setGeometry(QRect(0, 60, 150, 40));
    QFont font6;
    font6.setPointSize(11);
    search_label_1->setFont(font6);
    search_label_1->setAlignment(Qt::AlignCenter);
    search_text_1 = new QTextEdit(page_2);
    search_text_1->setObjectName(QString::fromUtf8("search_text_1"));
    search_text_1->setGeometry(QRect(150, 64, 410, 32));
    search_button_1 = new QPushButton(page_2);
    search_button_1->setObjectName(QString::fromUtf8("search_button_1"));
    search_button_1->setGeometry(QRect(580, 60, 200, 40));
    QFont font7;
    font7.setPointSize(11);
    font7.setBold(true);
    font7.setWeight(75);
    search_button_1->setFont(font7);
    search_text_2 = new QTextEdit(page_2);
    search_text_2->setObjectName(QString::fromUtf8("search_text_2"));
    search_text_2->setGeometry(QRect(20, 180, 760, 480));
    search_label_2 = new QLabel(page_2);
    search_label_2->setObjectName(QString::fromUtf8("search_label_2"));
    search_label_2->setGeometry(QRect(0, 120, 150, 40));
    search_label_2->setFont(font6);
    search_label_2->setAlignment(Qt::AlignCenter);
    stackedWidget->addWidget(page_2);
    page_3 = new QWidget();
    page_3->setObjectName(QString::fromUtf8("page_3"));
    road_title = new QLabel(page_3);
    road_title->setObjectName(QString::fromUtf8("road_title"));
    road_title->setGeometry(QRect(0, 0, 250, 40));
    road_title->setFont(font3);
    road_title->setAlignment(Qt::AlignCenter);
    road_label_1 = new QLabel(page_3);
    road_label_1->setObjectName(QString::fromUtf8("road_label_1"));
    road_label_1->setGeometry(QRect(0, 60, 150, 40));
    road_label_1->setFont(font6);
    road_label_1->setAlignment(Qt::AlignCenter);
    road_text_1 = new QTextEdit(page_3);
    road_text_1->setObjectName(QString::fromUtf8("road_text_1"));
    road_text_1->setGeometry(QRect(150, 64, 230, 32));
    road_text_2 = new QTextEdit(page_3);
    road_text_2->setObjectName(QString::fromUtf8("road_text_2"));
    road_text_2->setGeometry(QRect(550, 64, 230, 32));
    road_label_2 = new QLabel(page_3);
    road_label_2->setObjectName(QString::fromUtf8("road_label_2"));
    road_label_2->setGeometry(QRect(400, 60, 150, 40));
    road_label_2->setFont(font6);
    road_label_2->setAlignment(Qt::AlignCenter);
    road_text_3 = new QTextEdit(page_3);
    road_text_3->setObjectName(QString::fromUtf8("road_text_3"));
    road_text_3->setGeometry(QRect(20, 180, 760, 480));
    road_button_1 = new QPushButton(page_3);
    road_button_1->setObjectName(QString::fromUtf8("road_button_1"));
    road_button_1->setGeometry(QRect(580, 120, 200, 40));
    road_button_1->setFont(font7);
    road_label_3 = new QLabel(page_3);
    road_label_3->setObjectName(QString::fromUtf8("road_label_3"));
    road_label_3->setGeometry(QRect(0, 120, 150, 40));
    road_label_3->setFont(font6);
    road_label_3->setAlignment(Qt::AlignCenter);
    stackedWidget->addWidget(page_3);
    page_4 = new QWidget();
    page_4->setObjectName(QString::fromUtf8("page_4"));
    multi_title = new QLabel(page_4);
    multi_title->setObjectName(QString::fromUtf8("multi_title"));
    multi_title->setGeometry(QRect(0, 0, 250, 40));
    multi_title->setFont(font3);
    multi_title->setAlignment(Qt::AlignCenter);
    multi_text_1 = new QTextEdit(page_4);
    multi_text_1->setObjectName(QString::fromUtf8("multi_text_1"));
    multi_text_1->setGeometry(QRect(150, 64, 230, 32));
    multi_label_2 = new QLabel(page_4);
    multi_label_2->setObjectName(QString::fromUtf8("multi_label_2"));
    multi_label_2->setGeometry(QRect(400, 60, 150, 40));
    multi_label_2->setFont(font6);
    multi_label_2->setAlignment(Qt::AlignCenter);
    multi_button_1 = new QPushButton(page_4);
    multi_button_1->setObjectName(QString::fromUtf8("multi_button_1"));
    multi_button_1->setGeometry(QRect(580, 120, 200, 40));
    multi_button_1->setFont(font7);
    multi_label_1 = new QLabel(page_4);
    multi_label_1->setObjectName(QString::fromUtf8("multi_label_1"));
    multi_label_1->setGeometry(QRect(0, 60, 150, 40));
    multi_label_1->setFont(font6);
    multi_label_1->setAlignment(Qt::AlignCenter);
    multi_text_2 = new QTextEdit(page_4);
    multi_text_2->setObjectName(QString::fromUtf8("multi_text_2"));
    multi_text_2->setGeometry(QRect(550, 64, 230, 32));
    multi_text_3 = new QTextEdit(page_4);
    multi_text_3->setObjectName(QString::fromUtf8("multi_text_3"));
    multi_text_3->setGeometry(QRect(20, 180, 760, 490));
    multi_label_3 = new QLabel(page_4);
    multi_label_3->setObjectName(QString::fromUtf8("multi_label_3"));
    multi_label_3->setGeometry(QRect(0, 120, 150, 40));
    multi_label_3->setFont(font6);
    multi_label_3->setAlignment(Qt::AlignCenter);
    stackedWidget->addWidget(page_4);
    page_5 = new QWidget();
    page_5->setObjectName(QString::fromUtf8("page_5"));
    plenty_text_1 = new QTextEdit(page_5);
    plenty_text_1->setObjectName(QString::fromUtf8("plenty_text_1"));
    plenty_text_1->setGeometry(QRect(150, 64, 230, 32));
    plenty_text_4 = new QTextEdit(page_5);
    plenty_text_4->setObjectName(QString::fromUtf8("plenty_text_4"));
    plenty_text_4->setGeometry(QRect(20, 240, 760, 430));
    plenty_title = new QLabel(page_5);
    plenty_title->setObjectName(QString::fromUtf8("plenty_title"));
    plenty_title->setGeometry(QRect(0, 0, 250, 40));
    plenty_title->setFont(font3);
    plenty_title->setAlignment(Qt::AlignCenter);
    plenty_label_1 = new QLabel(page_5);
    plenty_label_1->setObjectName(QString::fromUtf8("plenty_label_1"));
    plenty_label_1->setGeometry(QRect(0, 60, 150, 40));
    plenty_label_1->setFont(font6);
    plenty_label_1->setAlignment(Qt::AlignCenter);
    plenty_label_2 = new QLabel(page_5);
    plenty_label_2->setObjectName(QString::fromUtf8("plenty_label_2"));
    plenty_label_2->setGeometry(QRect(400, 60, 150, 40));
    plenty_label_2->setFont(font6);
    plenty_label_2->setAlignment(Qt::AlignCenter);
    plenty_button_1 = new QPushButton(page_5);
    plenty_button_1->setObjectName(QString::fromUtf8("plenty_button_1"));
    plenty_button_1->setGeometry(QRect(580, 120, 200, 40));
    plenty_button_1->setFont(font7);
    plenty_text_2 = new QTextEdit(page_5);
    plenty_text_2->setObjectName(QString::fromUtf8("plenty_text_2"));
    plenty_text_2->setGeometry(QRect(550, 64, 230, 32));
    plenty_label_3 = new QLabel(page_5);
    plenty_label_3->setObjectName(QString::fromUtf8("plenty_label_3"));
    plenty_label_3->setGeometry(QRect(0, 120, 150, 40));
    plenty_label_3->setFont(font6);
    plenty_label_3->setAlignment(Qt::AlignCenter);
    plenty_text_3 = new QTextEdit(page_5);
    plenty_text_3->setObjectName(QString::fromUtf8("plenty_text_3"));
    plenty_text_3->setGeometry(QRect(150, 124, 230, 32));
    plenty_label_4 = new QLabel(page_5);
    plenty_label_4->setObjectName(QString::fromUtf8("plenty_label_4"));
    plenty_label_4->setGeometry(QRect(0, 180, 150, 40));
    plenty_label_4->setFont(font6);
    plenty_label_4->setAlignment(Qt::AlignCenter);
    stackedWidget->addWidget(page_5);
    page_6 = new QWidget();
    page_6->setObjectName(QString::fromUtf8("page_6"));
    about_title = new QLabel(page_6);
    about_title->setObjectName(QString::fromUtf8("about_title"));
    about_title->setGeometry(QRect(0, 0, 250, 40));
    about_title->setFont(font3);
    about_title->setAlignment(Qt::AlignCenter);
    stackedWidget->addWidget(page_6);
    IconLabel = new QLabel(centralwidget);
    IconLabel->setObjectName(QString::fromUtf8("IconLabel"));
    IconLabel->setGeometry(QRect(250, 2, 50, 50));
    IconLabel->setMinimumSize(QSize(50, 50));
    IconLabel->setFont(font1);
    IconLabel->setPixmap(QPixmap(QString::fromUtf8("Resources/main.png")));
    IconLabel->setScaledContents(true);
    IconLabel->setAlignment(Qt::AlignCenter);
    GuideWindow->setCentralWidget(centralwidget);

    retranslateUi(GuideWindow);

    stackedWidget->setCurrentIndex(5);

    QMetaObject::connectSlotsByName(GuideWindow);
}

// retranslateUi
void Ui_GuideWindow::retranslateUi(QMainWindow *GuideWindow)
{
    GuideWindow->setWindowTitle(QApplication::translate("GuideWindow", "\345\237\272\344\272\216Qt5\347\232\204\346\240\241\345\233\255\345\257\274\346\270\270\347\263\273\347\273\237 v2.1", nullptr));
    TitleLabel->setText(QApplication::translate("GuideWindow", "\345\237\272\344\272\216Qt5\347\232\204\346\240\241\345\233\255\345\257\274\346\270\270\347\263\273\347\273\237 v2.1", nullptr));
    button_left_1->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
    button_left_2->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
    button_left_3->setText(QApplication::translate("GuideWindow", "\346\234\200\347\237\255\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    button_left_4->setText(QApplication::translate("GuideWindow", "\346\211\200\346\234\211\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    button_left_5->setText(QApplication::translate("GuideWindow", "\345\244\232\346\231\257\347\202\271\346\237\245\350\257\242", nullptr));
    button_left_6->setText(QApplication::translate("GuideWindow", "\345\205\263\344\272\216", nullptr));
    pix_label_1->setText(QString());
    pix_label_2->setText(QApplication::translate("GuideWindow", "Powered by Y.Wang", nullptr));
    pix_label_3->setText(QApplication::translate("GuideWindow", "2019.2.18", nullptr));
    info_title->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\344\277\241\346\201\257\347\273\264\346\212\244", nullptr));
    info_label_1->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\347\274\226\345\217\267", nullptr));
    info_label_2->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\345\220\215\347\247\260", nullptr));
    info_label_3->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\347\256\200\344\273\213", nullptr));
    info_button_1->setText(QApplication::translate("GuideWindow", "\345\275\225\345\205\245\344\277\241\346\201\257", nullptr));
    info_label_5->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\350\265\267\347\202\271\347\274\226\345\217\267", nullptr));
    info_label_4->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\347\273\210\347\202\271\347\274\226\345\217\267", nullptr));
    info_label_6->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\351\225\277\345\272\246", nullptr));
    info_button_2->setText(QApplication::translate("GuideWindow", "\345\275\225\345\205\245\351\201\223\350\267\257", nullptr));
    info_title_2->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\344\277\241\346\201\257\347\273\264\346\212\244", nullptr));
    info_button_3->setText(QApplication::translate("GuideWindow", "\345\210\240\351\231\244\346\231\257\347\202\271\345\217\212\345\205\266\351\201\223\350\267\257", nullptr));
    info_button_4->setText(QApplication::translate("GuideWindow", "\345\210\240\351\231\244\351\201\223\350\267\257", nullptr));
    search_title->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
    search_label_1->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\347\274\226\345\217\267", nullptr));
    search_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\346\231\257\347\202\271\344\277\241\346\201\257", nullptr));
    search_label_2->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\347\273\223\346\236\234", nullptr));
    road_title->setText(QApplication::translate("GuideWindow", "\346\234\200\347\237\255\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    road_label_1->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\350\265\267\347\202\271", nullptr));
    road_label_2->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\347\273\210\347\202\271", nullptr));
    road_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
    road_label_3->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\347\273\223\346\236\234", nullptr));
    multi_title->setText(QApplication::translate("GuideWindow", "\346\211\200\346\234\211\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    multi_label_2->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\347\273\210\347\202\271", nullptr));
    multi_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\346\211\200\346\234\211\350\267\257\345\276\204", nullptr));
    multi_label_1->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\350\265\267\347\202\271", nullptr));
    multi_label_3->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\347\273\223\346\236\234", nullptr));
    plenty_title->setText(QApplication::translate("GuideWindow", "\345\244\232\346\231\257\347\202\271\346\237\245\350\257\242", nullptr));
    plenty_label_1->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271A", nullptr));
    plenty_label_2->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271B", nullptr));
    plenty_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\345\244\232\346\231\257\347\202\271\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
    plenty_label_3->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271C", nullptr));
    plenty_label_4->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\347\273\223\346\236\234", nullptr));
    about_title->setText(QApplication::translate("GuideWindow", "\345\205\263\344\272\216", nullptr));
    IconLabel->setText(QString());
}
