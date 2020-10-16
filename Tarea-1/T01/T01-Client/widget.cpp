#include "widget.h"
#include "ui_widget.h"
/**
 * @brief Widget::Widget lee el socket, y muestra la info
 * @param parent, un null_prt
 */
Widget::Widget(QWidget *parent):QWidget(parent),ui(new Ui::Widget){
    ui->setupUi(this);
    mSocket=new QTcpSocket(this);
    mSocket->connectToHost("localhost",12345);
    connect(mSocket,&QTcpSocket::readyRead,[&](){//conectar el socket al server que esta listo
        QString str = mSocket->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toLatin1());
        QJsonArray jsonArray = jsonResponse.array();
        QJsonObject jsonObject = jsonArray.first().toObject();
        resp=jsonObject.value("Resultado").toInt();
        order=jsonObject.value("Order").toInt();
        this->StartedFlag=false;
        mostrarDatos();
    });
}
/**
 * @brief Widget::~Widget destruye la ui
 */
Widget::~Widget(){
    delete ui;
}
/**
 * @brief Widget::on_Run_clicked Boton para cargar el json y cargarlo en el socket, con la info necesaria
 */
void Widget::on_Run_clicked(){
    vertOrigen=ui->NVertice->value();
    vertFinal=ui->NVertice_2->value();
    QJsonObject Lista{
        {"Started-Flag",StartedFlag},
        {"Origen",vertOrigen},
        {"Final",vertFinal}
    };
    QJsonArray jsarray {Lista};
    QJsonDocument jsDoc(jsarray);
    QString jsString = QString::fromLatin1(jsDoc.toJson());
    qDebug()<<jsDoc;
    mSocket->write(jsString.toLatin1());
}
/**
 * @brief Widget::mostrarDatos Metodo para visualizar las respuestas dadas por el server
 */
void Widget::mostrarDatos(){
    if(vertOrigen>=order || vertFinal>=order){
        ui->cuadro->addItem("Error nodo inexistente");
    }else{
        resultado=resultado.append(to_string(vertOrigen)+" al nodo "+to_string(vertFinal)+" es: "+to_string(resp));
        ui->cuadro->addItem(QString::fromStdString(resultado));
        resultado="La ruta mas corta del nodo ";
    }
}
/**
 * @brief Widget::on_Quitar_clicked Boton para desmantelar la interfaz
*/
void Widget::on_Quitar_clicked(){
    QApplication::quit();
}
