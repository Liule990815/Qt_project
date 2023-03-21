#include "qtclient.h"
#include "ui_qtclient.h"

Qtclient::Qtclient(QWidget *parent, Qt::WindowFlags flags) : QWidget(parent, flags),ui(new Ui::Qtclient)
{
    ui->setupUi(this);
    this->initTCP();

    //文件传送相关变量初始化
    ///每次发送数据大小为64kb
    perDataSize = 64*1024;
    totalBytes = 0;
    bytestoWrite = 0;
    bytesWritten = 0;
    bytesReceived = 0;
    filenameSize = 0;

    connect(this->ui,SIGNAL(clicked()),this,SLOT(selectFile()));
    connect(this->ui.pushButton_sendFile,SIGNAL(clicked()),this,SLOT(sendFile()));
}

Qtclient::~Qtclient()
{
    delete ui;
}
