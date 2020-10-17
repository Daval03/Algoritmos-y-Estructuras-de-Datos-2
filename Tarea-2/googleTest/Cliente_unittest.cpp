#include "gtest/gtest.h"
#include "server.h"
#include "cliente.h"
namespace{
TEST(Cliente,PrepararJson){
    Cliente_PrepararJson_Test ha;
    Cliente *mCliente=new Cliente();
    EXPECT_FALSE(mCliente->mSocket->bytesAvailable());
}
TEST(Cliente,Integracion_completa_1){
    Server *mServer=new Server();
    mServer->listen(QHostAddress::Any,8245);

    Cliente *mCliente=new Cliente();
    mCliente->Json(0,3);

    mServer->get_send_Info();

    mCliente->getInfo(82345);
    EXPECT_EQ(0,mCliente->resp);

}
TEST(Cliente,Integracion_completa_2){
    Server *mServer=new Server();
    mServer->listen(QHostAddress::Any,42345);

    Cliente *mCliente=new Cliente();
    mCliente->Json(0,3);

    mServer->get_send_Info();

    mCliente->getInfo(82345);
    EXPECT_EQ(7,mCliente->resp);
}
TEST(Cliente,Integracion_completa_3){
    Server *mServer=new Server();
    mServer->listen(QHostAddress::Any,48845);

    Cliente *mCliente=new Cliente();
    mCliente->Json(0,1);

    mServer->get_send_Info();

//    mCliente->getInfo(82345);
    EXPECT_FALSE(mCliente->recibioInfo);
}


}
