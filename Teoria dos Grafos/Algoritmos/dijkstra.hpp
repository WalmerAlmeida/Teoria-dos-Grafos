#ifndef _DIJKSTRA_HPP_
#define _DIJKSTRA_HPP_

#include <queue>

#define MAX 1073741823

using namespace std;

int *dijkstra_algorithm(Graph *g, int ini_vertex) {

    int *distance, prev[g->n], i;
    distance = (int*)malloc((g->n) * (sizeof(int)));

    // fila de prioridades da biblioteca stl que possui uma max heap como padrão. porém aqui foi modificada para uma minheap
    priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > min_heap;

    for(i = 0; i < g->n; i++) {
        distance[i] = MAX;
        prev[i] = -1;
    }

    distance[ini_vertex] = 0;

    min_heap.push(make_pair(ini_vertex, distance[ini_vertex]));

    while(!min_heap.empty()) {
        pair<int, int> p = min_heap.top();
        int expanded_vertex = p.first;
        min_heap.pop();

        for(vector<pair<int, int>>::iterator it = g->edges[expanded_vertex].begin(); it != g->edges[expanded_vertex].end(); it++) {
            int adjacent_vertex = it->first;
            int edge_cost = it->second;
                
            if(distance[adjacent_vertex] > (distance[expanded_vertex] + edge_cost)) {
                distance[adjacent_vertex] = distance[expanded_vertex] + edge_cost;
                prev[adjacent_vertex] = expanded_vertex;
                min_heap.push(make_pair(adjacent_vertex, distance[adjacent_vertex]));
            }
        }
        
    }

    return distance;
}

#endif 