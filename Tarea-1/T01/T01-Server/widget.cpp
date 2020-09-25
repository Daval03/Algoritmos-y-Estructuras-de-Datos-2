#include "widget.h"
#include "ui_widget.h"
/**
 * @brief Widget::Widget
 * @param parent, un null_ptr
 */
Widget::Widget(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::Widget){
    ui->setupUi(this);
    mServer=new Server(this);
    mServer->listen(QHostAddress::Any,12345);
    qDebug()<<"Server iniciado";
}
Widget::~Widget(){
    delete ui;
}
