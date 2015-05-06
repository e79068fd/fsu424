#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

int xScale = 20;
int yScale = 20;
int xNull = 0;
int yNull = 200;
int xMax = 20 * xScale;
int yMax = yNull * 2;
double step = 3.1415 / 1e2;
bool flagFunc1 = false;
bool flagFunc2 = false;
bool flagFunc3 = false;
bool flagFunc4 = false;
QPainterPath marking()
{
    QPainterPath canvas;
    canvas.moveTo(xNull, yNull);
    canvas.lineTo(xNull + xMax, yNull);
    for(int x = 0; x <= xMax; x += xScale)
    {
        canvas.moveTo(x, yNull - xScale / 4);
        canvas.lineTo(x, yNull + xScale / 4);
    }
    canvas.moveTo(xNull, 0);
    canvas.lineTo(xNull, yMax);
    for(int y = yNull; y >= 0; y -= yScale)
    {
        canvas.moveTo(xNull - yScale / 4, y);
        canvas.lineTo(xNull + yScale / 4, y);
    }
    for(int y = yNull; y <= yMax; y += yScale)
    {
        canvas.moveTo(xNull - yScale / 4, y);
        canvas.lineTo(xNull + yScale / 4, y);
    }
    return canvas;
}
QPainterPath func1()
{
    QPainterPath canvas;
    canvas.moveTo(xNull, yNull);
    double y;
    for(double x = 0; x < xMax / xScale + xScale; x += step)
    {
        y = -1 * cos(x);
        canvas.lineTo((int)(x * xScale) + xNull, (int)(y * yScale) + yNull);
    }
    canvas.moveTo(xNull, yNull);
    return canvas;
}
QPainterPath func2()
{
    QPainterPath canvas;
    canvas.moveTo(xNull, yNull);
    double y;
    for(double x = 0; x < xMax / xScale + xScale; x += step)
    {
        y = -1 * x * x;
        canvas.lineTo((int)(x * xScale) + xNull, (int)(y * yScale) + yNull);
    }
    canvas.moveTo(xNull, yNull);
    return canvas;
}
QPainterPath func3()
{
    QPainterPath canvas;
    canvas.moveTo(xNull, yNull);
    double y;
    for(double x = 0; x < 20; x += step)
    {
        if(x != 0)
        {
            y = -1 * 1 / x;
            canvas.lineTo((int)(x * xScale) + xNull, (int)(y * yScale) + yNull);
        }
        else
        {
            canvas.moveTo(xNull + 1, 0);
        }
    }
    return canvas;
}
QPainterPath func4()
{
    QPainterPath canvas;
    canvas.moveTo(xNull, yNull);
    double y;
    for(double x = 0; x < 20; x += step)
    {
        y = -1 * tan(x);
        if(y > -1e2)
            canvas.lineTo((int)(x * xScale) + xNull, (int)(y * yScale) + yNull);
        else
            canvas.moveTo((int)(x * xScale) + xNull, (int)(50 * yScale) + yNull);
    }
    return canvas;
}

void Widget::paintEvent(QPaintEvent *pe)
{
    QPainter painter(this);
    xMax = this->width();
    yMax = this->height();
    if(xMax > 20)
    {
        xNull = 0;
        xScale = xMax / 20;
    }
    if(yMax > 20)
    {
        yNull = yMax / 2;
        yScale = yMax / 20;
    }
    painter.fillRect(0, 0, xMax, yMax, Qt::white);
    if(flagFunc1)
    {
        painter.setPen(Qt::blue);
        painter.drawPath(func1());
    }
    if(flagFunc2)
    {
        painter.setPen(Qt::red);
        painter.drawPath(func2());
    }
    if(flagFunc3)
    {
        painter.setPen(Qt::green);
        painter.drawPath(func3());
    }
    if(flagFunc4)
    {
        painter.setPen(Qt::yellow);
        painter.drawPath(func4());
    }
    painter.setPen(Qt::black);
    painter.drawPath(marking());
}

void Widget::invertionFlag1()
{
    flagFunc1 = !flagFunc1;
    Widget::repaint();
}
void Widget::invertionFlag2()
{
    flagFunc2 = !flagFunc2;
    Widget::repaint();
}
void Widget::invertionFlag3()
{
    flagFunc3 = !flagFunc3;
    Widget::repaint();
}
void Widget::invertionFlag4()
{
    flagFunc4 = !flagFunc4;
    Widget::repaint();
}
void Widget::contextMenuEvent(QContextMenuEvent *pe)
{
    QMenu menu(this);
    qsignalmapper = new QSignalMapper(this);
    QAction *fl1 = menu.addAction("cos(x)");
    connect(fl1, SIGNAL(triggered()), this, SLOT(invertionFlag1()));
    QAction *fl2 = menu.addAction("x**2");
    connect(fl2, SIGNAL(triggered()), this, SLOT(invertionFlag2()));
    QAction *fl3 = menu.addAction("1/x");
    connect(fl3, SIGNAL(triggered()), this, SLOT(invertionFlag3()));
    QAction *fl4 = menu.addAction("tan(x)");
    connect(fl4, SIGNAL(triggered()), this, SLOT(invertionFlag4()));
    menu.exec(pe->globalPos());
}
