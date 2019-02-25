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
        pixmap = QPixmap(740, 250);
        pixmap.fill(Qt::white);
    }

    void paintEvent(QPaintEvent *)
    {
        QPainter p(this);
        p.drawPixmap(0, 0, 740, 250, pixmap);
    }

    void addVertex(int x, int y, int n)
    {
        Vertex *v = new Vertex();
        v->setParent(this);
        v->setGeometry(QRect(x, y, 24, 24));
        v->label->setText(QString::number(n));
        update();
    }

    void addEdge(int x1, int y1, int x2, int y2)
    {
        QPainter p(&pixmap);
        p.setPen(QPen(Qt::black, 2));
        p.drawLine(x1, y1, x2, y2);
        update();
    }

    void delEdge(int x1, int y1, int x2, int y2)
    {
        QPainter p(&pixmap);
        p.setPen(QPen(Qt::white, 2));
        p.drawLine(x1, y1, x2, y2);
        update();
    }

    void setActiveVertex(int x, int y, int n)
    {
        Vertex *v = new Vertex();
        v->setParent(this);
        v->setGeometry(QRect(x, y, 24, 24));
        v->label->setText(QString::number(n));
        v->label->setStyleSheet("color:red;");
        update();
    }

  private:
    QPixmap pixmap;
};