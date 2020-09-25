#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QMessageBox>
#include <QTcpSocket>
#include "server.h"
namespace Ui { class Widget; }
class QTcpSocket;
class Server;
class Widget : public QWidget{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    /**
     * @brief mServer, la clase server
     * @brief mSocket, el socket conectado con el cliente
     * @brief ui, la clase del la interfaz
     */
    Server *mServer;
    QTcpSocket *mSocket;
    Ui::Widget *ui;
};
#endif // WIDGET_H
