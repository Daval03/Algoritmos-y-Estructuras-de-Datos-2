#include "gtest/gtest.h"
#include "graph.h"
namespace{
TEST(Graph,El_algoritmo_floyd_warshall){
    Graph *foo=new Graph();
    foo->setData(3,3);
    foo->addEdge(0,1,1);
    foo->addEdge(1,2,3);
    foo->addEdge(0,2,5);
    foo->floyd_warshall();
    EXPECT_EQ(4,foo->distancia(0,2));
    EXPECT_EQ(2,foo->distancia(0,1));
    EXPECT_EQ(3,foo->distancia(1,2));
}
TEST(Graph,getVertice){
    Graph *foo=new Graph();
    foo->setData(3,3);
    EXPECT_EQ(3,foo->getOrder());
}
}
