#include <cstdlib>
#include <limits.h>
#include <cstdio>
#include <string>
using namespace std;

class Graph{
private:
    unsigned int size; /* Arcs */
    unsigned int order; /* Vertices */
    unsigned int i=0;
    typedef struct {
        unsigned int origen;
        unsigned int destino;
        int peso;
    }ConnectNode;
    ConnectNode *arcs;
    int **distances;
public:
    Graph ();
    void addEdge(unsigned int origen, unsigned int destino,int peso);
    void setData(int size,int order);
    void **floyd_warshall();
    int distancia(int origen, int destino);
    void FreeMemo();
};
