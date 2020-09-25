#include "widget.h"
#include <QApplication>
#include <iostream>
using namespace std;
//int main(){
//    CSVReader *foo=new CSVReader;
//    foo->setData("/home/aldo/CLionProjects/Datos 2 - 2.0/Grafo2.txt");
//    foo->generarGrafo();
//    foo->grafo->floyd_warshall();
//    cout<<foo->grafo->distancia(0,1);
//}
int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Widget w;
    return a.exec();
}
