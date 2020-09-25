#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <string>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <csvreader.h>
using namespace std;
/**
 * @file server.h
 * @version 2.0
 * @title Server de la aplicacion
 * @date 1/3/20
 */
class QTcpSocket;
/**
 * @brief The Server class
 */
class Server : public QTcpServer{
    Q_OBJECT
public:
    /**
     * @brief Server
     * @param parent
     */
    explicit Server(QObject *parent = nullptr);
private:
    /**
     * @brief respuesta las rutas mas cortas que nos da el grafo
     */
    int respuesta;
    /**
     * @brief compVertice Vertice que se usara de referencia para calcular las rutas mas cortas
     */
    bool StartedFlag;
    int vertOrigen;
    int vertFinal;
    /**
     * @brief reader, me genera el grafo y el algoritmo
     * @param La ruta del txt, donde esta el grafo
     * @return las rutas mas cortas
     */
    CSVReader *reader=new CSVReader;
    /**
     * @brief mSocket
     * @return jSON del server
     */
    QTcpSocket *mSocket;
};

#endif // SERVER_H
