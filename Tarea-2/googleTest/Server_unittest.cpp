#include "gtest/gtest.h"
#include "server.h"
namespace{
TEST(Server,Server_escuchando){
    Server *mServer=new Server();
    mServer->listen(QHostAddress::Any,55146);
    EXPECT_TRUE(mServer->isListening());
}/*
TEST(Server,Test_Json_con_el_grafo){
    Server *mServer=new Server();
    //mServer->listen(QHostAddress::Any,22331);
}*/
}
