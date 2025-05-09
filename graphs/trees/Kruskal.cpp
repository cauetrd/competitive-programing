#include <bits/stdc++.h>

using namespace std;

/*
Kruskal:
percorre todas as arestas em ordem, 
se a ordem for crescente retorna a minimum spanning tree;
se a ordem for decrescente retorna a maximum spanning tree;
se os dois vértices que cada aresta liga já estão conectados, pula essa aresta;
se não, conecta os dois componentes e adiciona essa aresta;

a prova de que funciona é meio trivial, e a implementação é bem tranquila com dsu,
só to adicionando ai pra já ter uma que retorna mastigadinho com a árvore montada por adj;
*/

class DSU
{
    vector<int> parent;
    vector<int> card;
    
public:
    DSU(int n): parent(n+1), card(n+1,1)
    {
        for(int i = 1; i <= n; i++)
            parent[i] = i;
    }

    /* O(log n) */
    int find_set(int x)
    {
        if(x == parent[x])
            return x;
        
        return parent[x] = find_set(parent[x]);
    }

    bool same_set(int a, int b)
    {
        return find_set(a) == find_set(b);
    }

    /* O(log n) */
    void join_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        
        if(card[a] < card[b])
            swap(a,b);
        
        card[a] += card[b];
        parent[b] = a;
    }
};

// n = quantidade de vértices;
// retorna tree com tree[x] = {weigth, vertice};

vector<vector<pair<int,int>>> Kruskal(vector<pair<int,pair<int,int>>>& arestas, int n){
    DSU d(n);
    vector<vector<pair<int,int>>> tree(n+1);

    for(auto [w,p] : arestas){
        if(d.same_set(p.first, p.second)) continue;
        d.join_sets(p.first, p.second);
        tree[p.first].push_back({w,p.second});
        tree[p.second].push_back({w,p.first});
    }

    return tree;
}