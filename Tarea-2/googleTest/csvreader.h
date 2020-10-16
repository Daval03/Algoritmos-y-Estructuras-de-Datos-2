#ifndef CSVREADER_H
#define CSVREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <graph.h>
using namespace std;
class CSVReader{
private:
    string fileName;
public:
    CSVReader();
    Graph *grafo=new Graph;
    void generarGrafo();
    void setData(string filename);
};

#endif // CSVREADER_H
