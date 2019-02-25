#include "Headers/GuideWindow.h"

int v[PLACES];
// 设定最短路径动态演示
void Ui_GuideWindow::setPaint()
{
    w = new Widget();
    w->setParent(page_3);
    w->setGeometry(QRect(20, 400, 760, 260));
    for (int i = 0; i < 12; i++)
    {
        w->addVertex(i + 1);
    }
}

// 设定左侧切换事件
void Ui_GuideWindow::setLeftEvents()
{
    QObject::connect(button_left_1, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(0); });
    QObject::connect(button_left_2, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(1); });
    QObject::connect(button_left_3, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(2); });
    QObject::connect(button_left_4, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(3); });
    QObject::connect(button_left_5, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(4); });
    QObject::connect(button_left_6, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(5); });
    QObject::connect(button_left_7, &QAbstractButton::clicked, [=]() mutable { stackedWidget->setCurrentIndex(6); });
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
        w->addEdge(num1, num2);
    });
    // 删除景点
    QObject::connect(info_button_3, &QAbstractButton::clicked, [=]() mutable {
        int num = info_text_1->toPlainText().toInt();
        g.delInfo(num);
        for (int i = 0; i < PLACES; i++)
            w->delEdge(i + 1, num);
        for (int j = 0; j < PLACES; j++)
            w->delEdge(num, j + 1);
    });
    // 删除道路
    QObject::connect(info_button_4, &QAbstractButton::clicked, [=]() mutable {
        int num1 = info_text_4->toPlainText().toInt();
        int num2 = info_text_5->toPlainText().toInt();
        g.delPath(num1, num2);
        w->delEdge(num1, num2);
    });
    // 查询景点信息
    QObject::connect(search_button_1, &QAbstractButton::clicked, [=]() mutable {
        int num = search_text_1->toPlainText().toInt();
        string result = g.getInfo(num);
        search_text_2->setPlainText(QString::fromStdString(result));
    });
    // 查询道路信息
    QObject::connect(search_button_2, &QAbstractButton::clicked, [=]() mutable {
        int num1 = search_text_3->toPlainText().toInt();
        int num2 = search_text_4->toPlainText().toInt();
        string result = g.getPathInfo(num1, num2);
        search_text_5->setPlainText(QString::fromStdString(result));
    });
    // 查询最短路径
    QObject::connect(road_button_1, &QAbstractButton::clicked, [=]() mutable {
        int x = road_text_1->toPlainText().toInt();
        int y = road_text_2->toPlainText().toInt();
        string result = "";
        int sum = 0;
        for (int i = 0; i < PLACES; i++)
        {
            if (v[i] != 0 && v[i + 1] != 0)
                w->addEdge(v[i], v[i + 1]);
        }
        for (int i = 0; i < PLACES; i++)
            v[i] = 0;
        g.getPath(x, y, result, sum, v);
        result = "从 " + g.vertex[x].place + " 到 " + g.vertex[y].place + " 的最短路径为：" + result + "\n路径长度：" + to_string(sum);
        road_text_3->setPlainText(QString::fromStdString(result));
        for (int i = 0; i < PLACES; i++)
        {
            if (v[i] != 0 && v[i + 1] != 0)
                w->addActiveEdge(v[i], v[i + 1]);
        }
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
        result = "从 " + g.vertex[x].place + " 经过 " + g.vertex[y].place + " 到 " + g.vertex[z].place + " 的最短路径为：" + result;
        plenty_text_4->setPlainText(QString::fromStdString(result));
    });
    // 范例
    QObject::connect(demo_button_1, &QAbstractButton::clicked, [=]() mutable {
        setupDemo();
    });
}

// 设定范例地图
void Ui_GuideWindow::setupDemo()
{
    g.setInfo(1, "正门", "山东大学齐鲁软件学院正门");
    g.setInfo(2, "教学楼", "上课上自习的地方");
    g.setInfo(3, "科研楼", "做科研的地方");
    g.setInfo(4, "实验楼", "上机实验以及社团实验室");
    g.setInfo(5, "教研楼", "教研楼");
    g.setInfo(6, "图书馆", "借书看书自习的地方");
    g.setInfo(7, "食堂", "吃饭的地方");
    g.setInfo(8, "篮球场", "打篮球打网球的地方");
    g.setInfo(9, "足球场", "踢足球的体育场，在校外");
    g.setInfo(10, "5号学生公寓", "学生公寓");
    g.setInfo(11, "1号学生公寓", "学生公寓");
    g.setInfo(12, "3号学生公寓", "学生公寓");
    g.setPath(1, 2, 9);
    w->addEdge(1, 2);
    g.setPath(1, 3, 11);
    w->addEdge(1, 3);
    g.setPath(1, 7, 13);
    w->addEdge(1, 7);
    g.setPath(2, 3, 6);
    w->addEdge(2, 3);
    g.setPath(2, 7, 9);
    w->addEdge(2, 7);
    g.setPath(2, 10, 12);
    w->addEdge(2, 10);
    g.setPath(3, 4, 3);
    w->addEdge(3, 4);
    g.setPath(3, 6, 8);
    w->addEdge(3, 6);
    g.setPath(5, 6, 2);
    w->addEdge(5, 6);
    g.setPath(7, 9, 30);
    w->addEdge(7, 9);
    g.setPath(7, 12, 10);
    w->addEdge(7, 12);
    g.setPath(8, 12, 6);
    w->addEdge(8, 12);
    g.setPath(10, 11, 7);
    w->addEdge(10, 11);
    g.setPath(11, 12, 7);
    w->addEdge(11, 12);
}

// setupUi
void Ui_GuideWindow::setupUi(QMainWindow *GuideWindow)
{
    if (GuideWindow->objectName().isEmpty())
        GuideWindow->setObjectName(QString::fromUtf8("GuideWindow"));
    GuideWindow->resize(1000, 750);
    GuideWindow->setMinimumSize(QSize(1000, 750));
    QFont font;
    font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    GuideWindow->setFont(font);
    QIcon icon;
    icon.addFile(QString::fromUtf8("Resources/main.png"), QSize(), QIcon::Normal, QIcon::Off);
    GuideWindow->setWindowIcon(icon);
    GuideWindow->setToolTipDuration(1);
    centralwidget = new QWidget(GuideWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setMinimumSize(QSize(1000, 750));
    TitleLabel = new QLabel(centralwidget);
    TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
    TitleLabel->setGeometry(QRect(0, 0, 1000, 64));
    QFont font1;
    font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font1.setPointSize(16);
    font1.setBold(true);
    font1.setWeight(75);
    TitleLabel->setFont(font1);
    TitleLabel->setAlignment(Qt::AlignCenter);
    stackedWidget = new QStackedWidget(centralwidget);
    stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
    stackedWidget->setGeometry(QRect(200, 70, 800, 680));
    stackedWidget->setFont(font);
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
    info_label_1->setGeometry(QRect(0, 60, 150, 40));
    QFont font3;
    font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font3.setPointSize(11);
    info_label_1->setFont(font3);
    info_label_1->setAlignment(Qt::AlignCenter);
    info_label_2 = new QLabel(page_1);
    info_label_2->setObjectName(QString::fromUtf8("info_label_2"));
    info_label_2->setGeometry(QRect(0, 120, 150, 40));
    info_label_2->setFont(font3);
    info_label_2->setAlignment(Qt::AlignCenter);
    info_label_3 = new QLabel(page_1);
    info_label_3->setObjectName(QString::fromUtf8("info_label_3"));
    info_label_3->setGeometry(QRect(0, 180, 150, 40));
    info_label_3->setFont(font3);
    info_label_3->setAlignment(Qt::AlignCenter);
    info_text_1 = new QTextEdit(page_1);
    info_text_1->setObjectName(QString::fromUtf8("info_text_1"));
    info_text_1->setGeometry(QRect(150, 64, 410, 32));
    info_text_1->setFont(font);
    info_text_2 = new QTextEdit(page_1);
    info_text_2->setObjectName(QString::fromUtf8("info_text_2"));
    info_text_2->setGeometry(QRect(150, 124, 630, 32));
    info_text_2->setFont(font);
    info_text_3 = new QTextEdit(page_1);
    info_text_3->setObjectName(QString::fromUtf8("info_text_3"));
    info_text_3->setGeometry(QRect(150, 184, 630, 180));
    info_text_3->setFont(font);
    info_button_1 = new QPushButton(page_1);
    info_button_1->setObjectName(QString::fromUtf8("info_button_1"));
    info_button_1->setGeometry(QRect(580, 390, 200, 40));
    QFont font4;
    font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font4.setPointSize(11);
    font4.setBold(true);
    font4.setWeight(75);
    info_button_1->setFont(font4);
    info_text_5 = new QTextEdit(page_1);
    info_text_5->setObjectName(QString::fromUtf8("info_text_5"));
    info_text_5->setGeometry(QRect(550, 514, 230, 32));
    info_text_5->setFont(font);
    info_label_5 = new QLabel(page_1);
    info_label_5->setObjectName(QString::fromUtf8("info_label_5"));
    info_label_5->setGeometry(QRect(0, 510, 150, 40));
    info_label_5->setFont(font3);
    info_label_5->setAlignment(Qt::AlignCenter);
    info_text_4 = new QTextEdit(page_1);
    info_text_4->setObjectName(QString::fromUtf8("info_text_4"));
    info_text_4->setGeometry(QRect(150, 514, 230, 32));
    info_text_4->setFont(font);
    info_label_4 = new QLabel(page_1);
    info_label_4->setObjectName(QString::fromUtf8("info_label_4"));
    info_label_4->setGeometry(QRect(400, 510, 150, 40));
    info_label_4->setFont(font3);
    info_label_4->setAlignment(Qt::AlignCenter);
    info_label_6 = new QLabel(page_1);
    info_label_6->setObjectName(QString::fromUtf8("info_label_6"));
    info_label_6->setGeometry(QRect(0, 570, 150, 40));
    info_label_6->setFont(font3);
    info_label_6->setAlignment(Qt::AlignCenter);
    info_text_6 = new QTextEdit(page_1);
    info_text_6->setObjectName(QString::fromUtf8("info_text_6"));
    info_text_6->setGeometry(QRect(150, 574, 630, 32));
    info_text_6->setFont(font);
    info_button_2 = new QPushButton(page_1);
    info_button_2->setObjectName(QString::fromUtf8("info_button_2"));
    info_button_2->setGeometry(QRect(360, 620, 200, 40));
    info_button_2->setFont(font4);
    info_title_2 = new QLabel(page_1);
    info_title_2->setObjectName(QString::fromUtf8("info_title_2"));
    info_title_2->setGeometry(QRect(0, 450, 250, 40));
    info_title_2->setFont(font2);
    info_title_2->setAlignment(Qt::AlignCenter);
    info_button_3 = new QPushButton(page_1);
    info_button_3->setObjectName(QString::fromUtf8("info_button_3"));
    info_button_3->setGeometry(QRect(580, 60, 200, 40));
    info_button_3->setFont(font4);
    info_button_4 = new QPushButton(page_1);
    info_button_4->setObjectName(QString::fromUtf8("info_button_4"));
    info_button_4->setGeometry(QRect(580, 620, 200, 40));
    info_button_4->setFont(font4);
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
    search_label_1->setGeometry(QRect(0, 60, 150, 40));
    QFont font5;
    font5.setPointSize(11);
    search_label_1->setFont(font5);
    search_label_1->setAlignment(Qt::AlignCenter);
    search_text_1 = new QTextEdit(page_2);
    search_text_1->setObjectName(QString::fromUtf8("search_text_1"));
    search_text_1->setGeometry(QRect(150, 64, 410, 32));
    search_button_1 = new QPushButton(page_2);
    search_button_1->setObjectName(QString::fromUtf8("search_button_1"));
    search_button_1->setGeometry(QRect(580, 60, 200, 40));
    QFont font6;
    font6.setPointSize(11);
    font6.setBold(true);
    font6.setWeight(75);
    search_button_1->setFont(font6);
    search_text_2 = new QTextEdit(page_2);
    search_text_2->setObjectName(QString::fromUtf8("search_text_2"));
    search_text_2->setGeometry(QRect(20, 180, 760, 180));
    search_label_2 = new QLabel(page_2);
    search_label_2->setObjectName(QString::fromUtf8("search_label_2"));
    search_label_2->setGeometry(QRect(0, 120, 150, 40));
    search_label_2->setFont(font5);
    search_label_2->setAlignment(Qt::AlignCenter);
    search_title_2 = new QLabel(page_2);
    search_title_2->setObjectName(QString::fromUtf8("search_title_2"));
    search_title_2->setGeometry(QRect(0, 380, 250, 40));
    search_title_2->setFont(font2);
    search_title_2->setAlignment(Qt::AlignCenter);
    search_label_3 = new QLabel(page_2);
    search_label_3->setObjectName(QString::fromUtf8("search_label_3"));
    search_label_3->setGeometry(QRect(0, 440, 150, 40));
    search_label_3->setFont(font5);
    search_label_3->setAlignment(Qt::AlignCenter);
    search_label_4 = new QLabel(page_2);
    search_label_4->setObjectName(QString::fromUtf8("search_label_4"));
    search_label_4->setGeometry(QRect(400, 440, 150, 40));
    search_label_4->setFont(font5);
    search_label_4->setAlignment(Qt::AlignCenter);
    search_text_3 = new QTextEdit(page_2);
    search_text_3->setObjectName(QString::fromUtf8("search_text_3"));
    search_text_3->setGeometry(QRect(150, 444, 230, 32));
    search_text_4 = new QTextEdit(page_2);
    search_text_4->setObjectName(QString::fromUtf8("search_text_4"));
    search_text_4->setGeometry(QRect(550, 444, 230, 32));
    search_button_2 = new QPushButton(page_2);
    search_button_2->setObjectName(QString::fromUtf8("search_button_2"));
    search_button_2->setGeometry(QRect(580, 500, 200, 40));
    search_button_2->setFont(font6);
    search_label_5 = new QLabel(page_2);
    search_label_5->setObjectName(QString::fromUtf8("search_label_5"));
    search_label_5->setGeometry(QRect(0, 500, 150, 40));
    search_label_5->setFont(font5);
    search_label_5->setAlignment(Qt::AlignCenter);
    search_text_5 = new QTextEdit(page_2);
    search_text_5->setObjectName(QString::fromUtf8("search_text_5"));
    search_text_5->setGeometry(QRect(20, 560, 760, 100));
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
    road_label_1->setGeometry(QRect(0, 60, 150, 40));
    road_label_1->setFont(font5);
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
    road_label_2->setFont(font5);
    road_label_2->setAlignment(Qt::AlignCenter);
    road_text_3 = new QTextEdit(page_3);
    road_text_3->setObjectName(QString::fromUtf8("road_text_3"));
    road_text_3->setGeometry(QRect(20, 180, 760, 200));
    road_button_1 = new QPushButton(page_3);
    road_button_1->setObjectName(QString::fromUtf8("road_button_1"));
    road_button_1->setGeometry(QRect(580, 120, 200, 40));
    road_button_1->setFont(font6);
    road_label_3 = new QLabel(page_3);
    road_label_3->setObjectName(QString::fromUtf8("road_label_3"));
    road_label_3->setGeometry(QRect(0, 120, 150, 40));
    road_label_3->setFont(font5);
    road_label_3->setAlignment(Qt::AlignCenter);
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
    multi_text_1->setGeometry(QRect(150, 64, 230, 32));
    multi_label_2 = new QLabel(page_4);
    multi_label_2->setObjectName(QString::fromUtf8("multi_label_2"));
    multi_label_2->setGeometry(QRect(400, 60, 150, 40));
    multi_label_2->setFont(font5);
    multi_label_2->setAlignment(Qt::AlignCenter);
    multi_button_1 = new QPushButton(page_4);
    multi_button_1->setObjectName(QString::fromUtf8("multi_button_1"));
    multi_button_1->setGeometry(QRect(580, 120, 200, 40));
    multi_button_1->setFont(font6);
    multi_label_1 = new QLabel(page_4);
    multi_label_1->setObjectName(QString::fromUtf8("multi_label_1"));
    multi_label_1->setGeometry(QRect(0, 60, 150, 40));
    multi_label_1->setFont(font5);
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
    multi_label_3->setFont(font5);
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
    plenty_title->setFont(font2);
    plenty_title->setAlignment(Qt::AlignCenter);
    plenty_label_1 = new QLabel(page_5);
    plenty_label_1->setObjectName(QString::fromUtf8("plenty_label_1"));
    plenty_label_1->setGeometry(QRect(0, 60, 150, 40));
    plenty_label_1->setFont(font5);
    plenty_label_1->setAlignment(Qt::AlignCenter);
    plenty_label_2 = new QLabel(page_5);
    plenty_label_2->setObjectName(QString::fromUtf8("plenty_label_2"));
    plenty_label_2->setGeometry(QRect(400, 60, 150, 40));
    plenty_label_2->setFont(font5);
    plenty_label_2->setAlignment(Qt::AlignCenter);
    plenty_button_1 = new QPushButton(page_5);
    plenty_button_1->setObjectName(QString::fromUtf8("plenty_button_1"));
    plenty_button_1->setGeometry(QRect(580, 120, 200, 40));
    plenty_button_1->setFont(font6);
    plenty_text_2 = new QTextEdit(page_5);
    plenty_text_2->setObjectName(QString::fromUtf8("plenty_text_2"));
    plenty_text_2->setGeometry(QRect(550, 64, 230, 32));
    plenty_label_3 = new QLabel(page_5);
    plenty_label_3->setObjectName(QString::fromUtf8("plenty_label_3"));
    plenty_label_3->setGeometry(QRect(0, 120, 150, 40));
    plenty_label_3->setFont(font5);
    plenty_label_3->setAlignment(Qt::AlignCenter);
    plenty_text_3 = new QTextEdit(page_5);
    plenty_text_3->setObjectName(QString::fromUtf8("plenty_text_3"));
    plenty_text_3->setGeometry(QRect(150, 124, 230, 32));
    plenty_label_4 = new QLabel(page_5);
    plenty_label_4->setObjectName(QString::fromUtf8("plenty_label_4"));
    plenty_label_4->setGeometry(QRect(0, 180, 150, 40));
    plenty_label_4->setFont(font5);
    plenty_label_4->setAlignment(Qt::AlignCenter);
    stackedWidget->addWidget(page_5);
    page_6 = new QWidget();
    page_6->setObjectName(QString::fromUtf8("page_6"));
    about_title = new QLabel(page_6);
    about_title->setObjectName(QString::fromUtf8("about_title"));
    about_title->setGeometry(QRect(0, 0, 250, 40));
    about_title->setFont(font2);
    about_title->setAlignment(Qt::AlignCenter);
    about_label_1 = new QLabel(page_6);
    about_label_1->setObjectName(QString::fromUtf8("about_label_1"));
    about_label_1->setGeometry(QRect(20, 60, 760, 620));
    QFont font7;
    font7.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font7.setPointSize(9);
    about_label_1->setFont(font7);
    about_label_1->setTextFormat(Qt::RichText);
    about_label_1->setAlignment(Qt::AlignLeading | Qt::AlignLeft | Qt::AlignTop);
    stackedWidget->addWidget(page_6);
    page_7 = new QWidget();
    page_7->setObjectName(QString::fromUtf8("page_7"));
    demo_title = new QLabel(page_7);
    demo_title->setObjectName(QString::fromUtf8("demo_title"));
    demo_title->setGeometry(QRect(0, 0, 250, 40));
    demo_title->setFont(font2);
    demo_title->setAlignment(Qt::AlignCenter);
    demo_button_1 = new QPushButton(page_7);
    demo_button_1->setObjectName(QString::fromUtf8("demo_button_1"));
    demo_button_1->setGeometry(QRect(580, 620, 200, 40));
    demo_button_1->setFont(font4);
    demo_label_2 = new QLabel(page_7);
    demo_label_2->setObjectName(QString::fromUtf8("demo_label_2"));
    demo_label_2->setGeometry(QRect(20, 550, 760, 40));
    QFont font8;
    font8.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font8.setPointSize(11);
    font8.setBold(false);
    font8.setWeight(50);
    demo_label_2->setFont(font8);
    demo_label_2->setAlignment(Qt::AlignCenter);
    demo_label_1 = new QLabel(page_7);
    demo_label_1->setObjectName(QString::fromUtf8("demo_label_1"));
    demo_label_1->setGeometry(QRect(20, 70, 760, 430));
    demo_label_1->setFont(font5);
    demo_label_1->setAutoFillBackground(false);
    demo_label_1->setPixmap(QPixmap(QString::fromUtf8("Resources/map.png")));
    demo_label_1->setScaledContents(true);
    demo_label_1->setAlignment(Qt::AlignCenter);
    stackedWidget->addWidget(page_7);
    IconLabel = new QLabel(centralwidget);
    IconLabel->setObjectName(QString::fromUtf8("IconLabel"));
    IconLabel->setGeometry(QRect(250, 2, 50, 50));
    IconLabel->setMinimumSize(QSize(50, 50));
    IconLabel->setFont(font);
    IconLabel->setPixmap(QPixmap(QString::fromUtf8("Resources/main.png")));
    IconLabel->setScaledContents(true);
    IconLabel->setAlignment(Qt::AlignCenter);
    button_left_7 = new QPushButton(centralwidget);
    button_left_7->setObjectName(QString::fromUtf8("button_left_7"));
    button_left_7->setGeometry(QRect(0, 420, 200, 60));
    button_left_7->setMinimumSize(QSize(0, 0));
    QFont font9;
    font9.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
    font9.setBold(true);
    font9.setWeight(75);
    button_left_7->setFont(font9);
    QIcon icon1;
    icon1.addFile(QString::fromUtf8("Resources/sdu.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_7->setIcon(icon1);
    button_left_7->setIconSize(QSize(48, 48));
    button_left_2 = new QPushButton(centralwidget);
    button_left_2->setObjectName(QString::fromUtf8("button_left_2"));
    button_left_2->setGeometry(QRect(0, 140, 200, 60));
    button_left_2->setMinimumSize(QSize(0, 0));
    button_left_2->setFont(font9);
    QIcon icon2;
    icon2.addFile(QString::fromUtf8("Resources/searchinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_2->setIcon(icon2);
    button_left_2->setIconSize(QSize(48, 48));
    button_left_1 = new QPushButton(centralwidget);
    button_left_1->setObjectName(QString::fromUtf8("button_left_1"));
    button_left_1->setGeometry(QRect(0, 70, 200, 60));
    button_left_1->setMinimumSize(QSize(0, 0));
    button_left_1->setFont(font9);
    QIcon icon3;
    icon3.addFile(QString::fromUtf8("Resources/writeinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_1->setIcon(icon3);
    button_left_1->setIconSize(QSize(48, 48));
    button_left_3 = new QPushButton(centralwidget);
    button_left_3->setObjectName(QString::fromUtf8("button_left_3"));
    button_left_3->setGeometry(QRect(0, 210, 200, 60));
    button_left_3->setMinimumSize(QSize(0, 0));
    button_left_3->setFont(font9);
    QIcon icon4;
    icon4.addFile(QString::fromUtf8("Resources/findroad.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_3->setIcon(icon4);
    button_left_3->setIconSize(QSize(48, 48));
    button_left_4 = new QPushButton(centralwidget);
    button_left_4->setObjectName(QString::fromUtf8("button_left_4"));
    button_left_4->setGeometry(QRect(0, 280, 200, 60));
    button_left_4->setMinimumSize(QSize(0, 0));
    button_left_4->setFont(font9);
    QIcon icon5;
    icon5.addFile(QString::fromUtf8("Resources/allroad.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_4->setIcon(icon5);
    button_left_4->setIconSize(QSize(48, 48));
    button_left_6 = new QPushButton(centralwidget);
    button_left_6->setObjectName(QString::fromUtf8("button_left_6"));
    button_left_6->setGeometry(QRect(0, 490, 200, 60));
    button_left_6->setMinimumSize(QSize(0, 0));
    button_left_6->setFont(font9);
    QIcon icon6;
    icon6.addFile(QString::fromUtf8("Resources/about.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_6->setIcon(icon6);
    button_left_6->setIconSize(QSize(48, 48));
    button_left_5 = new QPushButton(centralwidget);
    button_left_5->setObjectName(QString::fromUtf8("button_left_5"));
    button_left_5->setGeometry(QRect(0, 350, 200, 60));
    button_left_5->setMinimumSize(QSize(0, 0));
    button_left_5->setFont(font9);
    QIcon icon7;
    icon7.addFile(QString::fromUtf8("Resources/multiplaces.png"), QSize(), QIcon::Normal, QIcon::Off);
    button_left_5->setIcon(icon7);
    button_left_5->setIconSize(QSize(48, 48));
    pix_label_1 = new QLabel(centralwidget);
    pix_label_1->setObjectName(QString::fromUtf8("pix_label_1"));
    pix_label_1->setGeometry(QRect(10, 560, 180, 180));
    pix_label_1->setMinimumSize(QSize(0, 0));
    pix_label_1->setFont(font);
    pix_label_1->setPixmap(QPixmap(QString::fromUtf8("Resources/auth.jpg")));
    pix_label_1->setScaledContents(true);
    pix_label_2 = new QLabel(centralwidget);
    pix_label_2->setObjectName(QString::fromUtf8("pix_label_2"));
    pix_label_2->setGeometry(QRect(10, 680, 180, 60));
    pix_label_2->setMinimumSize(QSize(0, 0));
    pix_label_2->setFont(font9);
    pix_label_2->setScaledContents(false);
    pix_label_2->setAlignment(Qt::AlignCenter);
    GuideWindow->setCentralWidget(centralwidget);

    retranslateUi(GuideWindow);

    setPaint();

    stackedWidget->setCurrentIndex(5);

    QMetaObject::connectSlotsByName(GuideWindow);
}

// retranslateUi
void Ui_GuideWindow::retranslateUi(QMainWindow *GuideWindow)
{
    GuideWindow->setWindowTitle(QApplication::translate("GuideWindow", "\345\237\272\344\272\216Qt5\347\232\204\346\240\241\345\233\255\345\257\274\346\270\270\347\263\273\347\273\237 v2.1.5", nullptr));
    TitleLabel->setText(QApplication::translate("GuideWindow", "\345\237\272\344\272\216Qt5\347\232\204\346\240\241\345\233\255\345\257\274\346\270\270\347\263\273\347\273\237 v2.1.5", nullptr));
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
    search_title->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
    search_label_1->setText(QApplication::translate("GuideWindow", "\346\231\257\347\202\271\347\274\226\345\217\267", nullptr));
    search_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\346\231\257\347\202\271\344\277\241\346\201\257", nullptr));
    search_label_2->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\347\273\223\346\236\234", nullptr));
    search_title_2->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
    search_label_3->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\350\265\267\347\202\271\347\274\226\345\217\267", nullptr));
    search_label_4->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\347\273\210\347\202\271\347\274\226\345\217\267", nullptr));
    search_button_2->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\351\201\223\350\267\257\344\277\241\346\201\257", nullptr));
    search_label_5->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\347\273\223\346\236\234", nullptr));
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
    plenty_label_1->setText(QApplication::translate("GuideWindow", "\350\265\267\347\202\271\346\231\257\347\202\271", nullptr));
    plenty_label_2->setText(QApplication::translate("GuideWindow", "\344\270\255\351\227\264\351\241\266\347\202\271A", nullptr));
    plenty_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\345\244\232\346\231\257\347\202\271\346\234\200\347\237\255\350\267\257\345\276\204", nullptr));
    plenty_label_3->setText(QApplication::translate("GuideWindow", "\344\270\255\351\227\264\351\241\266\347\202\271B", nullptr));
    plenty_label_4->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\347\273\223\346\236\234", nullptr));
    about_title->setText(QApplication::translate("GuideWindow", "\345\205\263\344\272\216", nullptr));
    about_label_1->setText(QApplication::translate("GuideWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; text-decoration: underline; color:#5500ff;\">\346\233\264\346\226\260\345\206\205\345\256\271</span></p><p align=\"center\">------------------------------------------------------------------------------------------------------------------</p><p align=\"justify\"><span style=\" font-size:10pt; font-weight:600;\">2019.2.25 </span><span style=\" font-size:10pt; font-weight:600; color:#ff0000;\">Version 2.1.5</span></p><p align=\"justify\">1. \346\226\260\345\242\236\351\201\223\350\267\257\344\277\241\346\201\257\346\237\245\350\257\242\345\212\237\350\203\275\357\274\214\350\276\223\345\205\245\351\201\223\350\267\257\350\265\267\347\202\271\345\222\214\347\273\210\347\202\271\345\215\263\345\217\257\346\237\245\350\257\242\351\201\223\350\267\257\345\205\267\344\275\223\344\277\241\346\201\257</p><p align=\"justify\">2. \346\226\260\345\242\236\350\214\203\344\276\213\345\234\260\345\233\276\357\274\214\346\224\257\346\214\201"
                                                                  "\344\270\200\351\224\256\345\275\225\345\205\245\345\267\262\346\234\211\350\214\203\344\276\213\344\277\241\346\201\257</p><p align=\"justify\">3. \346\226\260\345\242\236\346\234\200\347\237\255\350\267\257\345\276\204\346\237\245\350\257\242\344\273\245\345\217\212\346\211\200\346\234\211\350\267\257\345\276\204\346\237\245\350\257\242\346\230\276\347\244\272\350\267\257\345\276\204\346\200\273\351\225\277\345\272\246</p><p align=\"justify\">4. \351\207\215\346\226\260\350\260\203\346\225\264\345\244\232\346\231\257\347\202\271\346\237\245\350\257\242\345\212\237\350\203\275</p><p align=\"justify\">5. \345\275\225\345\205\245\350\214\203\344\276\213\345\234\260\345\233\276\345\220\216\357\274\214\345\275\225\345\205\245\350\267\257\345\276\204\343\200\201\346\237\245\350\257\242\346\234\200\347\237\255\350\267\257\345\276\204\346\227\266\357\274\214\345\234\250\350\214\203\344\276\213\345\233\276\347\211\207\344\270\212\345\235\207\344\274\232\346\230\276\347\244\272\350\267\257\345\276\204\347\272\277\346\235"
                                                                  "\241</p><p align=\"justify\">6. \345\234\250\346\211\200\346\234\211\346\266\211\345\217\212\350\267\257\345\276\204\346\237\245\350\257\242\347\232\204\347\225\214\351\235\242\346\226\260\345\242\236\346\230\276\347\244\272\350\267\257\345\276\204\346\231\257\347\202\271\347\274\226\345\217\267\345\212\237\350\203\275\357\274\214\344\271\237\345\260\261\346\230\257\345\220\214\346\227\266\346\230\276\347\244\272\347\274\226\345\217\267\345\222\214\345\220\215\347\247\260</p><p align=\"center\">------------------------------------------------------------------------------------------------------------------</p><p align=\"justify\"><span style=\" font-size:10pt; font-weight:600;\">2019.2.19 </span><span style=\" font-size:10pt; font-weight:600; color:#ff0000;\">Version 2.1</span></p><p align=\"justify\">1. \347\225\214\351\235\242\351\207\215\346\226\260\345\270\203\345\261\200</p><p align=\"justify\">2. \346\226\260\345\242\236\345\205\263\344\272\216\347\225\214\351\235\242</p><p align=\"justify\">3. \344\277"
                                                                  "\256\345\244\215\346\227\240\346\263\225\346\230\276\347\244\272\350\267\257\345\276\204\347\232\204bug</p><p align=\"justify\">4. \345\233\276\346\240\207\350\260\203\346\225\264</p><p align=\"justify\">5. \346\231\257\347\202\271\344\277\241\346\201\257\345\210\240\351\231\244\345\212\237\350\203\275\357\274\214\345\217\257\344\273\245\345\210\240\351\231\244\350\277\231\346\235\241\347\274\226\345\217\267\347\232\204\346\231\257\347\202\271\344\277\241\346\201\257\345\217\212\345\205\266\346\211\200\346\234\211\347\233\270\345\205\263\351\201\223\350\267\257\344\277\241\346\201\257</p><p align=\"justify\">6. \351\201\223\350\267\257\344\277\241\346\201\257\345\210\240\351\231\244\345\212\237\350\203\275\357\274\214\346\240\271\346\215\256\351\201\223\350\267\257\350\265\267\347\202\271\344\270\216\347\273\210\347\202\271\345\210\240\351\231\244\346\225\264\346\235\241\351\201\223\350\267\257\344\277\241\346\201\257</p><p align=\"center\">----------------------------------------------------------------------"
                                                                  "--------------------------------------------</p></body></html>",
                                                   nullptr));
    demo_title->setText(QApplication::translate("GuideWindow", "\350\214\203\344\276\213\345\234\260\345\233\276", nullptr));
    demo_button_1->setText(QApplication::translate("GuideWindow", "\345\275\225\345\205\245\350\214\203\344\276\213\345\234\260\345\233\276", nullptr));
    demo_label_2->setText(QApplication::translate("GuideWindow", "\345\275\225\345\205\245\350\214\203\344\276\213\345\234\260\345\233\276\345\220\216\357\274\214\345\275\225\345\205\245\350\267\257\345\276\204\343\200\201\346\237\245\350\257\242\346\234\200\347\237\255\350\267\257\345\276\204\346\227\266\357\274\214\345\234\250\345\233\276\347\211\207\344\270\212\345\235\207\344\274\232\346\230\276\347\244\272\350\267\257\345\276\204\347\272\277\346\235\241\343\200\202", nullptr));
    demo_label_1->setText(QString());
    IconLabel->setText(QString());
    button_left_7->setText(QApplication::translate("GuideWindow", "\350\214\203\344\276\213\345\234\260\345\233\276", nullptr));
    button_left_2->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
    button_left_1->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
    button_left_3->setText(QApplication::translate("GuideWindow", "\346\234\200\347\237\255\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    button_left_4->setText(QApplication::translate("GuideWindow", "\346\211\200\346\234\211\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
    button_left_6->setText(QApplication::translate("GuideWindow", "\345\205\263\344\272\216", nullptr));
    button_left_5->setText(QApplication::translate("GuideWindow", "\345\244\232\346\231\257\347\202\271\346\237\245\350\257\242", nullptr));
    pix_label_1->setText(QString());
    pix_label_2->setText(QApplication::translate("GuideWindow", "<html><head/><body><p align=\"center\"><span style=\" color:#ffffff;\">Powered by Y.Wang</span></p><p align=\"center\"><span style=\" color:#ffffff;\">2019.2.25</span></p></body></html>", nullptr));
}
