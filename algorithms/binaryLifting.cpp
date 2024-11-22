#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>



class TreeAncestor {
    int LOG;
    vector<vi> up;  //[n][log] -> o antecessor de n em 2^log
    vi depth;

public:
    TreeAncestor(int n, vi& pai){
        LOG =0;
        while((1 << LOG)<= n){
            LOG++;
            //formula de cálcular o log
        }
        up = vector<vi>(n,vi(LOG));
        depth = vi(n);

        // pai[i]<i:
        pai[0] =0;
        for(int v =0; v<n; v++){
            up[v][0]=pai[v];
            if(v !=0) depth[v] =depth[pai[v]]+1;
            for(int j = 1; j<LOG; j++){
                up[v][j] = up[ up[v][j-1]][j-1]; 
            }
        }

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
};
