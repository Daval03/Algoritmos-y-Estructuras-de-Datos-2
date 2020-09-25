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
    Graph *grafo=new Graph;
    void generarGrafo();
    CSVReader();
    void setData(string filename);
};
