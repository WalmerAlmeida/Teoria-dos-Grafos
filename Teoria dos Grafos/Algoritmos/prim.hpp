#ifndef _PRIM_HPP_
#define _PRIM_HPP_

#include <queue>

#define MAX 1073741823
using namespace std;

int *prim_algorithm(Graph *g, int ini_vertex) {

    int distance[g->n], visited[g->n], *prev, i;

    prev = (int*)malloc((g->n) * (sizeof(int)));

    // fila de prioridades da biblioteca stl que possui uma max heap como padrão. porém aqui foi modificada para uma minheap
    priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;
    
    for(i = 0; i < g->n; i++) {
        distance[i] = MAX;
        visited[i] = false;
        prev[i] = -1;
    }

    distance[ini_vertex] = 0;
    min_heap.push(make_pair(distance[ini_vertex], ini_vertex));
    
    while(!min_heap.empty()) {
        int expanded_vertex = min_heap.top().second;
        min_heap.pop();
    
        visited[expanded_vertex] = true;  

        for (vector<pair<int, int>>::iterator it = g->edges[expanded_vertex].begin(); it != g->edges[expanded_vertex].end(); ++it) {
            int v = it->first;
            int edge_cost = it->second;
    
            if (distance[v] > edge_cost && visited[v] == false) {
                distance[v] = edge_cost;
                prev[v] = expanded_vertex;
                min_heap.push(make_pair(distance[v], v));
            }
        }
    }
    /*
    for (int i = 0; i < g->n; ++i)
        printf("%d - %d | %d\n", i, prev[i], visited[i]);
    */
    return prev;
}

#endif 