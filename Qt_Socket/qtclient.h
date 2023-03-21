#ifndef QTCLIENT_H
#define QTCLIENT_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
namespace Ui {
class Qtclient;
}

class Qtclient : public QWidget
{
    Q_OBJECT

public:
    explicit Qtclient(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~Qtclient();
    void initTcp();
    void newConnect();

private slots:
    //连接服务器
    void connectServer();
    //与服务器断开连接
    void disconnectServer();
    //接收服务器发送的数据
    void receiveData();
    //向服务器发送数据
    void sendData();

    //浏览文件
    void selectFile();
    //发送文件
    void sendFile();
    //更新文件发送进度
    void updateFileProgress(qint64);
    //更新文件接收进度
    void updateFileProgress();

private:
    Ui::Qtclient *ui;
    QTcpSocket *tcpSocket;
    QTcpSocket *fileSocket;

    ///文件传送
    QFile *localFile;

    ///文件大小
    qint64 totalBytes;      //文件总字节数
    qint64 bytesWritten;    //已发送的字节数
    qint64 bytestoWrite;    //尚未发送的字节数
    qint64 filenameSize;    //文件名字的字节数
    qint64 bytesReceived;   //接收的字节数

    ///每次发送数据大小
    qint64 perDataSize;
    QString filename;

    ///数据缓冲区
    QByteArray inBlock;
    QByteArray outBlock;

    //系统时间
    QDateTime current_date_time;
    QString str_date_time;

};

#endif // QTCLIENT_H
