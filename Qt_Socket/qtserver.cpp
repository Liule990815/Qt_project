#include "qtserver.h"
#include "ui_qtserver.h"

Qtserver::Qtserver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Qtserver)
{
    ui->setupUi(this);
}

Qtserver::~Qtserver()
{
    delete ui;
}
