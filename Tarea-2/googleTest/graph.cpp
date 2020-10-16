#include "graph.h"
Graph::Graph(){}
void Graph::setData(int size, int order) {
    this->size=size;
    this->order=order;
    this->arcs=static_cast<ConnectNode *>(malloc(size * sizeof(ConnectNode)));
}
void Graph::addEdge(unsigned int origen, unsigned int destino,int peso) {
    unsigned int *pos=&i;
    arcs[*pos].origen = origen;
    arcs[*pos].destino = destino;
    arcs[*pos].peso = peso;
    (*pos)++;
}
void ** Graph::floyd_warshall() {
    unsigned int i, j, k;
    int **distances = static_cast<int **>(malloc(order * sizeof(int *)));
    for (i = 0; i < order; i++) {
        distances[i] = static_cast<int *>(malloc(order * sizeof(int)));
        for (j = 0; j < order; j++) {
            if (i == j){
                distances[i][j] = 0;
            }else {
                distances[i][j] = INT_MAX;
            }
        }
    }
    /* Calcula la distancia para cada coneccion directa de los nodos */
    for (i = 0; i < size; i++) {
        distances[arcs[i].origen][arcs[i].destino] = arcs[i].peso;
    }
    /* Calcula el resto de las distancias para los nodos indirectos */
    for (i = 0; i < order; i++) {
        for (j = 0; j < order; j++) {
            for (k = 0; k < order; k++) {
                const int djk = distances[j][k];
                const int dji = distances[j][i];
                const int dik = distances[i][k];
                if (dji != INT_MAX && dik != INT_MAX
                    && djk > dji + dik){
                    distances[j][k] = dji + dik;
                }
            }
        }
    }this->distances=distances;
}
int Graph::distancia(int origen, int destino){
    return distances[origen][destino];
}
int Graph::getOrder(){
    return order;
}
