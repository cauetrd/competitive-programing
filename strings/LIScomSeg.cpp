#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define vll vector<long long>

const int oo = 1e9+3;


/*LIS com seg: 
em lis com dp, temos que dp[i] = max(dp[j], para j (i-1...0),v[i]>v[j] );
ou seja, dos elementos de valor menor do que o comparado, qual tem a maior lis (possivelmente 0);
isso pode ser feito usando uma seg de max, da seguinte forma:
manter uma seg de range dos valores* (0...maior a[i]), e percorrer o vetor analisado
da esquerda pra direita definindo o lis pra cada como na linha 14, e dando update na seg 

blog extramente útil:
https://codeforces.com/blog/entry/101210

*OBS.: Quase sempre vale a pena normalizar/comprimir o vetor original
*/


class SegTree { //construir a seg vazia primeiro;
    vector<ll> st;
    vector<ll> v;
    int size;
    int elem_neutro = -oo;// changes based on the segtree function

public:

    SegTree(vector<int> arr, int size): st(4*size,0), v(size+1,0) {
        this->size = size;

        for(int i = 1; i<size+1; i++){
            v[i] = arr[i];
        }
    }

    ll f(ll a, ll b){ //type and return of function are variable, depending on the segtree
        return max(a,b);
    }

    void build(int l, int r, int nodo){
        if(l ==r){
            st[nodo] = v[l];
            return;
        }
        int m = (l+r)/2;


        build(l,m,nodo*2); //desceu p esquerda
        build(m+1,r,nodo*2+1); //desceu p direita


        st[nodo] = f(st[nodo*2], st[nodo*2+1]);
    }

    void update_range(int i, int l, int r, ll x, int nodo) {
        if(l == r){
            st[nodo]  = x;
            return;
        }

        int m = (l+r)/2;

        if(i <=m){
            update_range(i, l, m, x, nodo*2);
        }
        else{
            update_range(i,m+1,r,x,nodo*2+1);
        }

        st[nodo] = f(st[nodo*2],st[nodo*2+1]);
    };

    void update(int i, ll x){
        int l =1;
        int r = size;
        int nodo = 1;
        return update_range(i,l,r,x,nodo);
    }

    ll query_range(int ql, int qr, int l, int r, int nodo){
        if(l >qr or r < ql){
            return elem_neutro;
        }

        if( l >= ql and r <= qr){
            return st[nodo];
        }

        int m = (l+r)/2;
        ll suml = query_range(ql,qr,l,m,nodo*2);
        ll sumr = query_range(ql,qr,m+1,r,nodo*2+1);
        return f(suml,sumr);
    }

    ll query(int ql, int qr){
        int l = 1;
        int r = size;
        int nodo =1;
        return query_range(ql,qr,l,r,nodo);
    }
};

/* Errichto falou que é a versão mais rápida pra normalizar;
de fato, não usa set, nem map e nem binary, parece mais rápido mesmo;
Obs.: pra refazer a normalização, basta manter um vector sorted e dai o 
    o vetor normalizado vira um vetor "ponteiro" pra esse sorted.
*/

void normalize( vi& v){
    int n = v.size();
    vector<pii> pairs(n);

    for(int i=0; i<n; i++){
        pairs[i] = {v[i],i };
    }

    sort(pairs.begin(),pairs.end());
    int nxt = 0;
    for(int i =0; i<n; i++){
        if(i>0 && pairs[i-1].first != pairs[i].first) nxt++;
        v[pairs[i].second] = nxt;
    }
}

int find_lis(const vi& v){
    int n = v.size();
    vi empty(n,0);
    SegTree seg(empty,n);
    seg.build(1,n,1);

    int lis = 0;

    for(int i =0; i<n; i++){
        if(v[i]>0){
            lis = seg.query(1,v[i]-1);
        }else{
            lis =0;
        }
        seg.update(v[i],lis+1);
    }

    return seg.query(1,n);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    return 0;
    }

    