#include "mainwindow.h"
#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>

void sendTextToFile(QString* content, QDialog* dialog){
    // 弹出文件对话框，让用户选择保存路径和文件名
    QString filename = QFileDialog::getSaveFileName(
                nullptr, "Save File", QDir::homePath(), "Text Files (*.txt)");
    if (!filename.isEmpty())
    {
        // 创建文件对象并打开文件
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            // 创建文本流对象并绑定到文件对象
            QTextStream stream(&file);

            // 将文本写入文件
            stream << *content;

            // 关闭文件
            file.close();

            QMessageBox msgBox;
            // 设置消息弹窗的图标、标题和文本
            msgBox.setIcon(QMessageBox::Information);
            msgBox.setWindowTitle("Message");
            msgBox.setText("发送成功，是否还要继续发送？");
            // 添加一个按钮
            msgBox.addButton("YES", QMessageBox::AcceptRole);
            msgBox.addButton("NO", QMessageBox::RejectRole);
            int ret = msgBox.exec();
            if(ret == QMessageBox::RejectRole){
                dialog->close();
            }
        }
    }
    else{
        QMessageBox msgBox;
        // 设置消息弹窗的图标、标题和文本
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setWindowTitle("Message");
        msgBox.setText("发送失败，是否还要继续发送？");
        // 添加一个按钮
        msgBox.addButton("YES", QMessageBox::AcceptRole);
        msgBox.addButton("NO", QMessageBox::RejectRole);
        int ret = msgBox.exec();
        if(ret == QMessageBox::RejectRole){
            dialog->close();
        }
    }
}
void getText(QString* content, QLineEdit* edit){
    *content = edit->text();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget window;
    window.setWindowTitle("Main Window");
    window.resize(200, 100);
    // 创建一个按钮
    QPushButton button("Click me!", &window);
    button.setGeometry(50, 25, 100, 50);
    window.show();
    //链接按钮的clicked信号到槽函数
    QObject::connect(&button, &QPushButton::clicked, [&](){
        //创建一个新的窗口
        QDialog* dialog = new QDialog();
        QString* content = new QString();
        dialog->setWindowTitle("输入文本");
        QPushButton button1("发送", dialog);
        QLineEdit* edit = new QLineEdit("输入内容...", dialog);
        button1.setGeometry(50, 25, 100, 50);
        QObject::connect(&button1, &QPushButton::clicked, [&content, &edit](){
            getText(content, edit);
        });
        QObject::connect(&button1, &QPushButton::clicked, dialog, [&content, dialog](){
            sendTextToFile(content, dialog);
        });
        dialog->exec();
    });
    return a.exec();
}



