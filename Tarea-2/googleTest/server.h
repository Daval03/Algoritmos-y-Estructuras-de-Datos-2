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

class Server : public QTcpServer{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void get_send_Info();
private:
    int respuesta=0;
    bool StartedFlag;
    int vertOrigen;
    int vertFinal;
    CSVReader *reader=new CSVReader;
    QTcpSocket *mSocket;
};
