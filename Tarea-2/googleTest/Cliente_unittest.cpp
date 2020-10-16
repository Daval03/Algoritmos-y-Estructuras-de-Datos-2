#include "gtest/gtest.h"
#include "server.h"
#include "cliente.h"
namespace{
TEST(Cliente,coneccion){
    Server *mServer=new Server();
    mServer->listen(QHostAddress::Any,22345);
    Cliente *mCliente=new Cliente();
    EXPECT_FALSE(mCliente->isOpen());
}
TEST(Cliente,PrepararJson){
    Cliente *mCliente=new Cliente();
    EXPECT_FALSE(mCliente->mSocket->bytesAvailable());
}
TEST(Cliente,Integracion_completa_1){
    Server *mServer=new Server();
    mServer->listen(QHostAddress::Any,82345);

    Cliente *mCliente=new Cliente();
    mCliente->Json(0,3);

    mServer->get_send_Info();
    mCliente->getInfo(82345);
    EXPECT_EQ(0,mCliente->resp);
    mServer->close();
    mCliente->close();
}
}
