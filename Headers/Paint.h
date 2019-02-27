#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLabel>
#include <QPainter>
#include <QPixmap>
#include <QColor>
#include <QPen>

class Vertex : public QWidget
{
  public:
    QLabel *label;
    void paintEvent(QPaintEvent *)
    {
        QPainter p(this);
        p.setPen(QPen(Qt::black, 2));
        p.drawEllipse(0, 0, 24, 24);
    }
    Vertex()
    {
        label = new QLabel(this);
        label->setGeometry(QRect(0, 0, 24, 24));
        label->setAlignment(Qt::AlignCenter);
    }
};

class Widget : public QWidget
{
  public:
    Widget()
    {
        pixmap = QPixmap(760, 260);
        pixmap.fill(Qt::white);
    }

    void paintEvent(QPaintEvent *)
    {
        QPainter p(this);
        p.drawPixmap(0, 0, 760, 260, pixmap);
    }

    void addVertex(int n)
    {
        Vertex *v = new Vertex();
        v->setParent(this);
        v->setGeometry(QRect(14 * (n % 6) * (n % 6) + 20 * n + 40, 20 * (n % 2) * (n % 2) + 15 * n + 40, 24, 24));
        v->label->setText(QString::number(n));
        update();
    }

    void addEdge(int num1, int num2)
    {
        QPainter p(&pixmap);
        p.setPen(QPen(Qt::black, 2));
        p.drawLine(14 * (num1 % 6) * (num1 % 6) + 20 * num1 + 52, 20 * (num1 % 2) * (num1 % 2) + 15 * num1 + 52, 14 * (num2 % 6) * (num2 % 6) + 20 * num2 + 52, 20 * (num2 % 2) * (num2 % 2) + 15 * num2 + 52);
        update();
    }

    void delEdge(int num1, int num2)
    {
        QPainter p(&pixmap);
        p.setPen(QPen(Qt::white, 2));
        p.drawLine(14 * (num1 % 6) * (num1 % 6) + 20 * num1 + 52, 20 * (num1 % 2) * (num1 % 2) + 15 * num1 + 52, 14 * (num2 % 6) * (num2 % 6) + 20 * num2 + 52, 20 * (num2 % 2) * (num2 % 2) + 15 * num2 + 52);
        update();
    }

    void addActiveEdge(int num1, int num2)
    {
        QPainter p(&pixmap);
        p.setPen(QPen(Qt::red, 2));
        p.drawLine(14 * (num1 % 6) * (num1 % 6) + 20 * num1 + 52, 20 * (num1 % 2) * (num1 % 2) + 15 * num1 + 52, 14 * (num2 % 6) * (num2 % 6) + 20 * num2 + 52, 20 * (num2 % 2) * (num2 % 2) + 15 * num2 + 52);
        update();
    }

  private:
    QPixmap pixmap;
};
