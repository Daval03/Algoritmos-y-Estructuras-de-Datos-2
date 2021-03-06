#include "server.h"
Server::Server(QObject *parent) : QTcpServer(parent){}
void Server::get_send_Info(){
    mSocket=nullptr;
    connect(this, &Server::newConnection,[&](){
        mSocket= nextPendingConnection();
        connect(mSocket,&QTcpSocket::readyRead,[&](){
            QString str = mSocket->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(str.toLatin1());
            QJsonArray jsonArray = jsonResponse.array();
            QJsonObject jsonObject = jsonArray.first().toObject();
            vertOrigen=jsonObject.value("Origen").toInt();
            vertFinal=jsonObject.value("Final").toInt();
            StartedFlag=jsonObject.value("Started-Flag").toBool();
            if(StartedFlag){
                reader->setData("/home/aldo/Documentos/Algoritmos-y-Estructuras-de-Datos-2/Tarea-1/T01/T01-Server/Grafo.txt");
                reader->generarGrafo();
                reader->grafo->floyd_warshall();
            }if(vertOrigen<reader->grafo->getOrder() && vertFinal<reader->grafo->getOrder()){
                respuesta=reader->grafo->distancia(vertOrigen,vertFinal);
            }QJsonObject Lista{
                {"Resultado",respuesta},
                {"Order",reader->grafo->getOrder()}
            };QJsonArray jsarray {Lista};
            QJsonDocument jsDoc(jsarray);
            QString jsString = QString::fromLatin1(jsDoc.toJson());
            qDebug()<<jsDoc;
            mSocket->write(jsString.toLatin1());
        });
    });
}
