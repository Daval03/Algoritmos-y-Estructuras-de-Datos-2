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
    /**
     * @brief fileName Nombre de la ruta, del grafo
     */
    string fileName;
public:
    /**
     * @brief grafo Es la estrucuta de datos, predilecta para almacenar la informacion del txt
     */
    Graph *grafo=new Graph;
    /**
     * @brief generarGrafo Metodo para meter los datos del txt al grafo
     */
    void generarGrafo();
    /**
     * @brief CSVReader Constructor de la clase
     */
    CSVReader();
    /**
     * @brief setData Metodo para definir la ruta, para llegar al grafo
     * @param filename Ruta del grafo
     */
    void setData(string filename);
};
