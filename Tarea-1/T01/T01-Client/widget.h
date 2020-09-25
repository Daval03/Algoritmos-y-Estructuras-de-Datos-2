#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QTcpSocket>
#include <QTextStream>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <string>
#include <sstream>
using namespace std;
namespace Ui { class Widget; }
class QTcpSocket;
class Widget : public QWidget{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    /**
     * @brief on_Run_clicked, mandar el json al server
     */
    void on_Run_clicked();
    void on_Quitar_clicked();

private:
    /**
     * @brief order Son los nodos totales del grafo
     */
    int order;
    /**
     * @brief StartedFlag Bandera para saber cuando inicializar el grafo por primera vez
     */
    bool StartedFlag=true;
    /**
     * @brief vertOrigen Nodo de origen
     * @brief vertFinal Nodo de destino
     */
    int vertOrigen;
    int vertFinal;
    /**
     * @brief mostrarDatos Metodo para mostrar la info en la interfaz
     */
    void mostrarDatos();
    /**
     * @brief resp, la info del json y el vertice de origen que se usara para las comparaciones
     */
    int resp;
    /**
     * @brief numRuta,ruta,vertice info de interfaz
     */
    string resultado="La ruta mas corta del nodo ";
    /**
     * @brief ui, la clase de interfaz
     */
    Ui::Widget *ui;
    /**
     * @brief mSocket la clase del socket
     */
    QTcpSocket *mSocket;

};
#endif // WIDGET_H
