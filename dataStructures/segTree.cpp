#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define pii pair<int,int>


//passar vetor indexado em 1

class SegTree {
    vector<ll> st;
    vector<ll> v;
    int size;
    int elem_neutro = 0;// changes based on the segtree function

public:

    SegTree(vector<ll> arr, int size): st(4*size,0), v(size+1,0) {
        this->size = size;

        for(int i = 1; i<size+1; i++){
            v[i] = arr[i];
        }
    }

    ll f(ll a, ll b){ //type and return of function are variable, depending on the segtree
        return a+b;
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
    }

    