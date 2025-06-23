#include <bits/stdc++.h>

using namespace std;

/*
    Utilidades para o Euler Tour:
    o menor subarray entre dois elementos da array de EulerTour é o caminho entre esses dois vértices
    com isso, é possível descobrir várias coisas, como:
        qual o lca range (o depth mínimo);
        qual a soma de distâncias do caminho entre dois vértices
        qual a maior distância do caminho entre dois vértices
        dentre outros
*/

const int N = 1e5;

vector<vector<int>> g(N+1);
vector<int> depth(N+1); // definir depth[raiz] =1;
vector<int> eulerTour; // vai ter 2*N-1 elementos;
vector<int> first(N+1,-1); // primeira vez que um nó aparece no euler tour
vector<vector<int>> appears(N+1); //posições em que um nó aparece no eulertour

void dfs(int u){   
    
    if(first[u]==-1){
        first[u]=eulerTour.size();
    }

    appears[u].push_back(eulerTour.size());
    eulerTour.push_back(u);

    for(auto v : g[u]){
        depth[v] = depth[u]+1;
        dfs(v);
        appears[u].push_back(eulerTour.size());
        eulerTour.push_back(u);
    }
}

void print(){
    cout << eulerTour.size() << endl;
    for(auto x : eulerTour) cout << x << " ";
    cout << endl;
    for(auto x : eulerTour) cout << depth[x] << " ";
    cout << endl;
    for(int x = 1; x <9; x++) cout << first[x] << " ";
        
}

int main() {
    g[1].push_back(2);
    g[2].push_back(3);
    g[2].push_back(4);
    g[4].push_back(5);
    g[1].push_back(6);
    g[6].push_back(7);
    g[6].push_back(8);

    depth[1]= 1;
    dfs(1);

    print();
    
    return 0;
}