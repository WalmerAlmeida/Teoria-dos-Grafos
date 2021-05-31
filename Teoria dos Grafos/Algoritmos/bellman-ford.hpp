#ifndef _BELLMAN_FORD_HPP_
#define _BELLMAN_FORD_HPP_

#define MAX 1073741823

int *Bellman_Ford(Graph *g, int ini_vertex){
    int *d, prev[g->n];
    d = (int*)malloc((g->n) * (sizeof(int)));

    for(int i = 0; i < g->n; i++){
        d[i] = MAX;
        prev[i] = -1;
    }
    d[ini_vertex] = 0;
    for(int l = 1; l <= (g->n - 1); l++){
        for(int k = 0; k < g->n; k++){
            for(std::vector<std::pair<int, int>>::iterator it = g->edges[k].begin(); it != g->edges[k].end(); it++){
                //(*it).first = vértice de destino e k = vértice de origem
                
                if(d[(*it).first] > d[k] + (*it).second){
                    d[(*it).first] = d[k] + (*it).second;
                    prev[(*it).first] = k;
                }
            }
        }
    }
    
    for(int k = 0; k < g->n; k++){
        for(std::vector<std::pair<int, int>>::iterator it = g->edges[k].begin(); it != g->edges[k].end(); it++){
            if(d[(*it).first] > d[k] + (*it).second){
                printf("\nPossui ciclo negativo\n");
            }
        }
    }
    printf("\nNão possui ciclo negativo\n");
    /*
    for (int i = 0; i < g->n; ++i)
        printf("Distância entre %d - vértice inicial(%d) = %d\n", i, ini_vertex, d[i]);
    */
    return d;
}

#endif 