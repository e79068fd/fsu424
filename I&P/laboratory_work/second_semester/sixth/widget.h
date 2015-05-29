#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QTextStream>
#include <string>
#include <QFileDialog>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_buttonAdd_clicked();

    void on_buttonDelete_clicked();

    void on_buttonOpen_clicked();

    void on_buttonSave_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
