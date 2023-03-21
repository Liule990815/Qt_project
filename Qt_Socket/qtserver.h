#ifndef QTSERVER_H
#define QTSERVER_H

#include <QDialog>

namespace Ui {
class Qtserver;
}

class Qtserver : public QDialog
{
    Q_OBJECT

public:
    explicit Qtserver(QWidget *parent = 0);
    ~Qtserver();

private:
    Ui::Qtserver *ui;
};

#endif // QTSERVER_H
