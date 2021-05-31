#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include "graph.hpp"
#include "Algoritmos/kruskal.hpp"
#include "Algoritmos/prim.hpp"
#include "Algoritmos/dijkstra.hpp"
#include "Algoritmos/bellman-ford.hpp"

#define MAX 1073741823

Graph *GraphReading(char *fileName, char *tipoDeGrafo){
    //n = número de vértices
    //m = número de arestas
	FILE *graphtxt = fopen(fileName, "r");
    //printf("%s\n", tipoDeGrafo);
	int vertex1, vertex2, weight, n, m;

    fscanf(graphtxt, "%d %d", &n, &m);
    Graph *g = new Graph(n, m);

    if(!strcmp(tipoDeGrafo, "direcionado")){
        while(fscanf(graphtxt, "%d %d %d", &vertex1, &vertex2, &weight) != EOF){
            g->addEdgeDirected(vertex1, vertex2, weight);
        }
    }else if(!strcmp(tipoDeGrafo, "não direcionado")){
        while(fscanf(graphtxt, "%d %d %d", &vertex1, &vertex2, &weight) != EOF){
            g->addEdgeUndirected(vertex1, vertex2, weight);
        }
    }
    fclose (graphtxt);
    printf("\nGrafo: \n");
    g->print();//print do grafo
    
    return g;
}
int main(int argc,char **argv){
    char s[30] = "teste/teste.txt", tipoDeGrafo[30];//obs.: começa a registrar os vértices a partir do 0
    int pergunta, ini_vertex, fin_vertex, *prev, *distance;
    Graph *g;
    std::vector<std::pair<int, int>> S; //conjunto de arestas
    
    printf("Qual algoritmo deseja executar?\n1: Prim\n2: Kruskal\n3: Dijkstra\n4: Bellman-Ford\n");
    scanf("%d", &pergunta);
    switch (pergunta)
    {
    case 1://Prim
        strncpy(tipoDeGrafo, "não direcionado", sizeof(tipoDeGrafo));
        g = GraphReading(s, tipoDeGrafo);
        printf("Digite o vértice inicial: \n");
        scanf("%d", &ini_vertex);

        prev = prim_algorithm(g, ini_vertex);
        printf("\nÁrvore Geradora Mínima(vértice, vértice adjacente): \n");//verificar se do jeito que está printando está bom

        for(int i = 0; i < g->n; i++){
            if(prev[i] != -1){
                printf("(%d, %d)\n", prev[i], i);
		    }
        }
        free(prev);
        printf("\n");

        break;

    case 2://Kruskal
        strncpy(tipoDeGrafo, "não direcionado", sizeof(tipoDeGrafo));
        g = GraphReading(s, tipoDeGrafo);
        S = kruskal(g);
        //print do conjunto de arestas S
        printf("\nÁrvore Geradora Mínima(vértice, vértice adjacente):\n");
        for(std::vector<std::pair<int, int>>::iterator it = S.begin(); it != S.end(); it++){//verificar se do jeito que está printando está bom
            std::cout << "(" << (*it).first << ", " << (*it).second << ")" << std::endl;
        }
        break;

    case 3://Dijkstra
        strncpy(tipoDeGrafo, "direcionado", sizeof(tipoDeGrafo));
        g = GraphReading(s, tipoDeGrafo);
        printf("Digite o vértice inicial: \n");
        scanf("%d", &ini_vertex);

        distance = dijkstra_algorithm(g, ini_vertex);
        printf("\nA menor distância entre todos os vértices e o vértice inicial inserido: \n");
        for (int i = 0; i < g->n; ++i){
            if(MAX == distance[i]){
                printf("A menor distância entre o vértice inicial(%d) --- vértice(%d) = INDEFINIDO(%d)\n", ini_vertex, i, distance[i]);
            }else{
                printf("A menor distância entre o vértice inicial(%d) --- vértice(%d) = %d\n", ini_vertex, i, distance[i]);
            }
        }
        free(distance);
        printf("\n");
        break;

    case 4://Bellman-Ford
        strncpy(tipoDeGrafo, "direcionado", sizeof(tipoDeGrafo));
        g = GraphReading(s, tipoDeGrafo);
        printf("Digite o vértice inicial: \n");
        scanf("%d", &ini_vertex);

        distance = Bellman_Ford(g, ini_vertex);
        printf("\nA menor distância entre todos os vértices e o vértice inicial inserido: \n");
        for (int i = 0; i < g->n; ++i){
            if(MAX == distance[i]){
                printf("A menor distância entre o vértice inicial(%d) --- vértice(%d) = INDEFINIDO(%d)\n", ini_vertex, i, distance[i]);
            }else{
                printf("A menor distância entre o vértice inicial(%d) --- vértice(%d) = %d\n", ini_vertex, i, distance[i]);
            }
        }
        free(distance);
        printf("\n");
        break;

    default:
        printf("resposta inválida\n");
        break;
    }
    delete(g);
}