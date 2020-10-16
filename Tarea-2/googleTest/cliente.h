#ifndef CLIENTE_H
#define CLIENTE_H

#include <QTcpSocket>
#include <QTextStream>
#include <iostream>
#include <QDebug>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <string>
#include <sstream>
using namespace std;

class QTcpSocket;
namespace Ui {class Widget;}
class Cliente:public QTcpSocket{
public:
    Cliente();
    void Json(int origen,int final);
    QTcpSocket *mSocket;
    int order;
    int resp;
    void getInfo(int id);
};

#endif // CLIENTE_H
