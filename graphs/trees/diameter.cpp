#include <bits/stdc++.h>

using namespace std;

const int N = 1e4; //tamanho da árvore

vector<vector<int>> g(N); // árvore por lista de adjacências;

void dfs(int x, int p, int l, int& longestPath, int& nodo){
    for(auto v : g[x]){
        if(v==p) continue;
        dfs(v,x,l+1,longestPath,nodo);
    }
    if(l>longestPath){
        longestPath = l;
        nodo = x;
    }
}

//x = primeiro nó da árvore
pair<int,pair<int,int>> findDiameter(int x){
    //g = tree por lista de adjacência
    int nodo = x;
    int longestPath =0;
    
    dfs(x,-1,1,longestPath,nodo);

    longestPath =0;
    x = nodo;
    
    dfs(x, -1,1, longestPath, nodo);
    
    return make_pair(longestPath, make_pair(x,nodo));
}