#ifndef _KRUSKAL_HPP_
#define _KRUSKAL_HPP_

#include "Union_Find.hpp"

bool sortWeight(std::pair<int, std::pair<int, int>> a, std::pair<int, std::pair<int, int>> b){
    return (a.second).second < (b.second).second;
}

std::vector<std::pair<int, std::pair<int, int>>> createAllEdgesSet(Graph *g){
    std::vector<std::pair<int, std::pair<int, int>>> allEdges;
    for(int i = 0; i < g->n; i++){
		for(std::vector<std::pair<int, int>>::iterator it = g->edges[i].begin(); it != g->edges[i].end(); it++){
            allEdges.push_back(std::make_pair(i, std::make_pair((*it).first, (*it).second)));
		}
	}
    return allEdges;
}

std::vector<std::pair<int, int>> kruskal(Graph *g){
    std::vector<std::pair<int, int>> S;//conjunto vazio de arestas

    //cria um conjunto de todas as arestas chamado allEdges
    std::vector<std::pair<int, std::pair<int, int>>> allEdges = createAllEdgesSet(g);
    //ordena allEdges do menor peso ao maior peso.
    std::sort(allEdges.begin(), allEdges.end(), sortWeight);

    Union_Find *u = new Union_Find(g->n);
    for(int i = 0; i < g->n; i++){
        u->Make_Set(i);
	}
    //u->print();
    /*
    //print do allEdges
    for(int i = 0; i < 2*g->m; i++){
        printf("(%d, %d, %d)", allEdges[i].first, (allEdges[i].second).first, (allEdges[i].second).second);
	}*/
    
    for(int i = 0; i < 2*g->m; i++){
        if(u->Find(allEdges[i].first) != u->Find((allEdges[i].second).first)){
            S.push_back({allEdges[i].first, (allEdges[i].second).first});
            u->Union(u->Find(allEdges[i].first), u->Find((allEdges[i].second).first));
		}
	}
    //u->print();
    delete(u);
    //u->print();
    return S;
}

#endif 