//LCA com binary lifting;
#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

int MAX_N = 1e6;
int LOG = 20;

vector<vi> children(MAX_N,vi(MAX_N));
vector<vi> up(MAX_N, vi(LOG));
vi depth(MAX_N);

//definir up[a]=a antes;
//construtor se passarmos o a como raiz;
void dfs(int a){
    for(int b: children[a]){
        up[b][0] =a;
        depth[b] =depth[a] +1;
        for(int j =1; j<LOG; j++){
            up[b][j]= up[ up[b][j-1] ][j-1];
        }
        dfs(b);
    }
}

int jump(int a, int k){
    for(int j = LOG-1; j>=0; j--){
        if(k >= (1<<j)){
            a = up[a][j];
            k -= (1 << j);
        }
    }
    return a;
}

 int getAncestralK (int nodo, int k){

        if(depth[nodo]<k){
            return -1; //impossível
        }

        // 1 << j = 2^j

        for(int j = LOG-1; j>=0; j--){
            if(k >= (1 << j)){
                nodo = up[nodo][j];
                k -= (1 << j);
            }
        }

        return nodo;
    }

int find_lca(int a, int b){

    if(depth[a]< depth[b]){
        swap(a,b); // a sempre o mais profundo;
    }
    int k = depth[a] - depth[b];
    a = jump(a,k);

    if(a == b) return a;

    for(int j = LOG-1; j>=0; j--){
        if(up[a][j]!= up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];    
}

int dist(int a, int b){
    return depth[a] + depth[b] - 2*depth[find_lca(a,b)];
}
