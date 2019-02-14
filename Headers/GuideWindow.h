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
#include "../Graph.cpp"

class Ui_GuideWindow
{
  public:
    Graph g;
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

    void setupUi(QMainWindow *GuideWindow);
    void retranslateUi(QMainWindow *GuideWindow);
    void setEvents();
};
