#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

class Graph {
	public:
		int n, m;
    	std::vector<std::vector<std::pair<int, int>>> edges;
		//cria o grafo vazio
		Graph(int n, int m);
		void addEdgeDirected(int vertex1, int vertex2, int weight);
		void addEdgeUndirected(int vertex1, int vertex2, int weight);
		void print();
};

//cria o grafo vazio
Graph::Graph(int n, int m){
	this->n = n;
	this->m = m;
	while(edges.size() <= n){
		edges.push_back( {} );
	}
}

void Graph::addEdgeDirected(int vertex1, int vertex2, int weight){
	edges[vertex1].push_back(std::make_pair(vertex2, weight));
}

void Graph::addEdgeUndirected(int vertex1, int vertex2, int weight){
	edges[vertex1].push_back(std::make_pair(vertex2, weight));
	edges[vertex2].push_back(std::make_pair(vertex1, weight));
}

void Graph::print(){
	for(int i = 0; i < n; i++){
		printf("%d ->", i);
		for(std::vector<std::pair<int, int>>::iterator it = edges[i].begin(); it != edges[i].end(); it++){
			printf(" (%d, %d)", (*it).first, (*it).second);//(first = vértice de destino, second = peso da aresta)
		}
		printf("\n");
	}
}
#endif 