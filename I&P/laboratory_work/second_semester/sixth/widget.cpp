#include "widget.h"
#include "ui_widget.h"

QStandardItemModel *model = new QStandardItemModel;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList horizontalHeader;
    horizontalHeader.append("Имя исполнителя");
    horizontalHeader.append("Количество проданных дисков");

    model->setHorizontalHeaderLabels(horizontalHeader);
    ui->table->setModel(model);
    ui->table->resizeColumnsToContents();
    ui->table->resizeRowsToContents();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_buttonAdd_clicked()
{
    QStandardItem *item;

    item = new QStandardItem(QString(""));
    model->setItem(model->rowCount(), 0, item);
    ui->table->setModel(model);
}

void Widget::on_buttonDelete_clicked()
{
    model->removeRow(ui->table->currentIndex().row());
    ui->table->setModel(model);
}

void Widget::on_buttonOpen_clicked()
{
    //----------------------------------------
    model->clear();

    QStringList horizontalHeader;
    horizontalHeader.append("Имя исполнителя");
    horizontalHeader.append("Количество проданных дисков");

    model->setHorizontalHeaderLabels(horizontalHeader);
    ui->table->setModel(model);
    ui->table->resizeColumnsToContents();
    ui->table->resizeRowsToContents();
    //----------------------------------------
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", "");
    QFile file(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in(&file);
    QStandardItem *item;
    QString tmp;
    while(!in.atEnd())
    {
        in>>tmp; //name
        item = new QStandardItem(tmp);
        model->setItem(model->rowCount(), 0, item);
        in>>tmp; //count
        item = new QStandardItem(tmp);
        model->setItem(model->rowCount() - 1, 1, item);
    }
    ui->table->setModel(model);
    file.close();
}

void Widget::on_buttonSave_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), "", "");
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file);
    for(int i = 0; i < model->rowCount(); i++)
    {
        out<<model->item(i, 0)->text()<<" "<<model->item(i, 1)->text()<<"\n";
    }
    file.close();
}

