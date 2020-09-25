#include <cstdlib>
#include <limits.h>
#include <cstdio>
#include <string>
using namespace std;

class Graph{
private:
    /**
     * @brief size Numero de conexiones de nodos
    */
    unsigned int size;
    /**
     * @brief order Cuantos nodos hay
     */
    unsigned int order;
    unsigned int i=0;
    typedef struct {
        unsigned int origen;
        unsigned int destino;
        int peso;
    }ConnectNode;
    /**
     * @brief arcs Estructura del nodo
     */
    ConnectNode *arcs;
    /**
     * @brief distances "Matriz" donde se almacenaran las respuestas
     */
    int **distances;
public:
    /**
     * @brief getOrder Metodo para obtener los nodos totales del grafo
     * @return un numero
     */
    int getOrder();
    /**
     * @brief Graph Estrutura de datos
     */
    Graph ();
    /**
     * @brief addEdge Metodo para hacer una conexion entre nodos
     * @param origen Nodo de inicio (int)
     * @param destino Nodo final (int)
     * @param peso El peso de la conexion (int)
     */
    void addEdge(unsigned int origen, unsigned int destino,int peso);
    /**
     * @brief setData Metodo para inicializar los valores del grafo
     * @param size numero de conexiones
     * @param order numero de nodos
     */
    void setData(int size,int order);
    /**
     * @brief floyd_warshall Metodo para calcular las rutas mas cortas entre los nodos
     * @return Nada
     */
    void **floyd_warshall();
    /**
     * @brief distancia Metodo para obtener la ruta mas corta entre 2 nodos
     * @param origen Nodo de inicio (int)
     * @param destino Nodo final (int)
     * @return el valor de la ruta mas corta
     */
    int distancia(int origen, int destino);
};
