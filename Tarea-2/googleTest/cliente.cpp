#include "cliente.h"
Cliente::Cliente(){
    mSocket=new QTcpSocket();
}
void Cliente::Json(int origen,int final){
    QJsonObject Lista{
        {"Started-Flag",true},
        {"Origen",origen},
        {"Final",final}
    };
    QJsonArray jsarray {Lista};
    QJsonDocument jsDoc(jsarray);
    QString jsString = QString::fromLatin1(jsDoc.toJson());
    mSocket->write(jsString.toLatin1());
}
void Cliente::getInfo(int id){
    mSocket->connectToHost("localhost",id);
    connect(mSocket,&QTcpSocket::readyRead,[&](){//conectar el socket al server que esta listo
        QString str = mSocket->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toLatin1());
        QJsonArray jsonArray = jsonResponse.array();
        QJsonObject jsonObject = jsonArray.first().toObject();
        resp=jsonObject.value("Resultado").toInt();
        order=jsonObject.value("Order").toInt();
    });
}
