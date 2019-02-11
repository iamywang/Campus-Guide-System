/********************************************************************************
** Form generated from reading UI file 'GUIDE.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef GUIDE_H
#define GUIDE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuideWindow
{
  public:
    QWidget *centralwidget;
    QLabel *TitleLabel;
    QWidget *layoutWidget;
    QVBoxLayout *Left_Choosing;
    QPushButton *button_left_1;
    QPushButton *button_left_2;
    QPushButton *button_left_3;
    QPushButton *button_left_4;
    QLabel *pix_label_1;
    QLabel *pix_label_2;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QLabel *info_title;
    QLabel *info_label_1;
    QLabel *info_label_2;
    QLabel *info_label_3;
    QTextEdit *info_text_1;
    QTextEdit *info_text_2;
    QTextEdit *info_text_3;
    QPushButton *info_button_1;
    QTextEdit *info_text_5;
    QLabel *info_label_5;
    QTextEdit *info_text_4;
    QLabel *info_label_4;
    QLabel *info_label_6;
    QTextEdit *info_text_6;
    QPushButton *info_button_2;
    QWidget *page_2;
    QLabel *search_title;
    QLabel *search_label_1;
    QTextEdit *search_text_1;
    QPushButton *search_button_1;
    QTextEdit *search_text_2;
    QWidget *page_3;
    QLabel *road_title;
    QLabel *road_label_1;
    QTextEdit *road_text_1;
    QTextEdit *road_text_2;
    QLabel *road_label_2;
    QTextEdit *road_text_3;
    QPushButton *road_button_1;
    QWidget *page_4;
    QLabel *multi_title;
    QTextEdit *multi_text_1;
    QLabel *multi_label_2;
    QPushButton *multi_button_1;
    QLabel *multi_label_1;
    QTextEdit *multi_text_2;
    QTextEdit *multi_text_3;
    QLabel *IconLabel;

    void setupUi(QMainWindow *GuideWindow)
    {
        if (GuideWindow->objectName().isEmpty())
            GuideWindow->setObjectName(QString::fromUtf8("GuideWindow"));
        GuideWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Resources/multiplaces.png"), QSize(), QIcon::Normal, QIcon::Off);
        GuideWindow->setWindowIcon(icon);
        centralwidget = new QWidget(GuideWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TitleLabel = new QLabel(centralwidget);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(0, 0, 800, 50));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        TitleLabel->setFont(font);
        TitleLabel->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, 61, 182, 449));
        Left_Choosing = new QVBoxLayout(layoutWidget);
        Left_Choosing->setObjectName(QString::fromUtf8("Left_Choosing"));
        Left_Choosing->setContentsMargins(0, 0, 0, 0);
        button_left_1 = new QPushButton(layoutWidget);
        button_left_1->setObjectName(QString::fromUtf8("button_left_1"));
        button_left_1->setMinimumSize(QSize(180, 50));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../Resources/writeinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_left_1->setIcon(icon1);
        button_left_1->setIconSize(QSize(40, 40));

        Left_Choosing->addWidget(button_left_1);

        button_left_2 = new QPushButton(layoutWidget);
        button_left_2->setObjectName(QString::fromUtf8("button_left_2"));
        button_left_2->setMinimumSize(QSize(180, 50));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../Resources/searchinfo.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_left_2->setIcon(icon2);
        button_left_2->setIconSize(QSize(40, 40));

        Left_Choosing->addWidget(button_left_2);

        button_left_3 = new QPushButton(layoutWidget);
        button_left_3->setObjectName(QString::fromUtf8("button_left_3"));
        button_left_3->setMinimumSize(QSize(180, 50));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../Resources/findroad.png"), QSize(), QIcon::Normal, QIcon::Off);
        button_left_3->setIcon(icon3);
        button_left_3->setIconSize(QSize(40, 40));

        Left_Choosing->addWidget(button_left_3);

        button_left_4 = new QPushButton(layoutWidget);
        button_left_4->setObjectName(QString::fromUtf8("button_left_4"));
        button_left_4->setMinimumSize(QSize(180, 50));
        button_left_4->setIcon(icon);
        button_left_4->setIconSize(QSize(40, 40));

        Left_Choosing->addWidget(button_left_4);

        pix_label_1 = new QLabel(layoutWidget);
        pix_label_1->setObjectName(QString::fromUtf8("pix_label_1"));
        pix_label_1->setMinimumSize(QSize(180, 180));
        pix_label_1->setPixmap(QPixmap(QString::fromUtf8("../Resources/auth.jpg")));
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

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(200, 50, 600, 530));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        info_title = new QLabel(page_1);
        info_title->setObjectName(QString::fromUtf8("info_title"));
        info_title->setGeometry(QRect(0, 0, 250, 40));
        QFont font2;
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
        IconLabel = new QLabel(centralwidget);
        IconLabel->setObjectName(QString::fromUtf8("IconLabel"));
        IconLabel->setGeometry(QRect(180, 1, 61, 48));
        IconLabel->setMinimumSize(QSize(48, 48));
        IconLabel->setPixmap(QPixmap(QString::fromUtf8("../Resources/multiplaces.png")));
        IconLabel->setScaledContents(true);
        IconLabel->setAlignment(Qt::AlignCenter);
        GuideWindow->setCentralWidget(centralwidget);

        retranslateUi(GuideWindow);

        stackedWidget->setCurrentIndex(0);

        QMetaObject::connectSlotsByName(GuideWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GuideWindow)
    {
        GuideWindow->setWindowTitle(QApplication::translate("GuideWindow", "\345\237\272\344\272\216Qt5\347\232\204\346\240\241\345\233\255\345\257\274\346\270\270\347\263\273\347\273\237 v1.0", nullptr));
        TitleLabel->setText(QApplication::translate("GuideWindow", "\345\237\272\344\272\216Qt5\347\232\204\346\240\241\345\233\255\345\257\274\346\270\270\347\263\273\347\273\237 v1.0", nullptr));
        button_left_1->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\345\275\225\345\205\245", nullptr));
        button_left_2->setText(QApplication::translate("GuideWindow", "\344\277\241\346\201\257\346\237\245\350\257\242", nullptr));
        button_left_3->setText(QApplication::translate("GuideWindow", "\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
        button_left_4->setText(QApplication::translate("GuideWindow", "\345\244\232\346\231\257\347\202\271\346\237\245\350\257\242", nullptr));
        pix_label_1->setText(QString());
        pix_label_2->setText(QApplication::translate("GuideWindow", "Powered by Y.Wang", nullptr));
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
        road_title->setText(QApplication::translate("GuideWindow", "\350\267\257\345\276\204\346\237\245\350\257\242", nullptr));
        road_label_1->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\350\265\267\347\202\271", nullptr));
        road_label_2->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\347\273\210\347\202\271", nullptr));
        road_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\350\267\257\345\276\204", nullptr));
        multi_title->setText(QApplication::translate("GuideWindow", "\345\244\232\346\231\257\347\202\271\346\237\245\350\257\242", nullptr));
        multi_label_2->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\347\273\210\347\202\271", nullptr));
        multi_button_1->setText(QApplication::translate("GuideWindow", "\346\237\245\350\257\242\350\267\257\345\276\204", nullptr));
        multi_label_1->setText(QApplication::translate("GuideWindow", "\351\201\223\350\267\257\350\265\267\347\202\271", nullptr));
        IconLabel->setText(QString());
    } // retranslateUi
};

namespace Ui
{
class GuideWindow : public Ui_GuideWindow
{
};
} // namespace Ui

QT_END_NAMESPACE

#endif // GUIDE_H
