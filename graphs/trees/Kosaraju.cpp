#include <bits/stdc++.h>

using namespace std;

/*
    Algoritmo de Kosaraju:
    contexto : grafo direcionado;
    objetivo: encontrar componentes fortemente conectados* no grafo 
        *fortemente conectado: é possível chegar em todos os nós saindo de qualquer nó;
        *componente fortemente conectado (SCC): maior quantidade possível de vértices fortemente conectados no grafo
    
    Um grafo G direcionado pode ser representado por um grafo acíclico direcionado S onde cada nó de S é um SCC de G;
        *S == G, se G é acíclico

    Execução: 
    encontra a pós-ordem por DFS;
    cria um grafo Ginv igual a G mas com a direção das arestas trocada.
        Obs, um componente fortemente conectado em G também é em Ginv;
    Performa DFS em Ginv para encontrar os SCC diferentes.
*/
const int N = 1e5+1;
vector<vector<int>> g(N), ginv(N); //grafo original, inverso e resultado do kosaraju;
vector<int> vis(N,0); 
vector<int> pai(N); //nó que vai representar o componente conexo (noção de dsu);
vector<int> scc; //lista de representantes de componentes scc;
stack<int> posord;

void dfs(int u){
    vis[u]=1;
    for(auto v: g[u]){
        if(!vis[v]) dfs(v);
    }
    posord.push(u);
}

void invdfs(int u){
    vis[u] =1;
    for(auto v: ginv[u]){

        if(!vis[v]){
            pai[v] = pai[u];
            invdfs(v);
        }
    }
}

void kosaraju(int n){
    for(int i = 1; i<=n ; i++) vis[i]=0;

    for(int i =1; i<=n; i++) if(!vis[i]) dfs(i);
    
    for(int i =1; i<=n; i++) vis[i]=0;

    while(!posord.empty()){
        int u = posord.top(); posord.pop();
        if(vis[u]) continue;

        pai[u] = u;
        scc.push_back(u);
        invdfs(u);
    }
    
}
