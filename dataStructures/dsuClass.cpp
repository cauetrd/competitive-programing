#include <bits/stdc++.h>

using namespace std;

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