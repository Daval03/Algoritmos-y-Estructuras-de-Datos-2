#include "gtest/gtest.h"
#include "csvreader.h"
namespace{
TEST(CSVReader,Floyd_warshall_del_txt){
    CSVReader *reader=new CSVReader;
    reader->setData("/home/aldo/Documentos/Algoritmos-y-Estructuras-de-Datos-2/Tarea-1/T01/T01-Server/Grafo.txt");
    reader->generarGrafo();
    reader->grafo->floyd_warshall();
    EXPECT_EQ(0,reader->grafo->distancia(0,3));
    EXPECT_EQ(1,reader->grafo->distancia(3,2));
}
TEST(CSVReader,Orden_grafo_txt){
    CSVReader *reader=new CSVReader;
    reader->setData("/home/aldo/Documentos/Algoritmos-y-Estructuras-de-Datos-2/Tarea-1/T01/T01-Server/Grafo.txt");
    reader->generarGrafo();
    EXPECT_EQ(4,reader->grafo->getOrder());
}
}
