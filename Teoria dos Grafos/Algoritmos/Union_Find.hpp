#ifndef _UNION_FIND_HPP_
#define _UNION_FIND_HPP_

class Union_Find {
	public:
		Union_Find(int n);
        ~Union_Find();
		void Make_Set(int x);
		int Find(int x);
		void Union(int x, int y);
        void print();
    private:
        int *pai, *rank, size;
};
Union_Find::Union_Find(int n){
    pai = (int*)malloc((n+1)*sizeof(int));
    rank = (int*)malloc((n+1)*sizeof(int));
    size = n;
}

Union_Find::~Union_Find(){
    free(pai);
    free(rank);
}

void Union_Find::Make_Set(int x){
    pai[x] = x;
    rank[x] = 0;
}

int Union_Find::Find(int x){
    if(pai[x] != x){
        pai[x] = Find(pai[x]);
    }
    return pai[x];
}

void Union_Find::Union(int x, int y){
    if(rank[x] >= rank[y]){
        pai[y] = x;
        if(rank[x] == rank[y]){
            rank[x]++;
        }
    }else{
        pai[x] = y;
    }
}

void Union_Find::print(){
    for(int i = 0; i < size; i++){
        printf("%d(%d, %d), ", i, pai[i], rank[i]);
    }
}

#endif 