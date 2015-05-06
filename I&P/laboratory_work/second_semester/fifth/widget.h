#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QtGui>
#include <QMenu>
#include <cmath>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void paintEvent(QPaintEvent *pe);

    void contextMenuEvent(QContextMenuEvent *pe);

signals:
    void triggered(const QString &func);

public slots:
    void invertionFlag1();
    void invertionFlag2();
    void invertionFlag3();
    void invertionFlag4();
private:
    Ui::Widget *ui;
    QSignalMapper *qsignalmapper;

};

#endif // WIDGET_H
