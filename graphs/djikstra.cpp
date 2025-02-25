#include<bits/stdc++.h>

using namespace std;


#define pii pair<int, int>
#define ll long long


int N;
const int oo = 1e6+7; // depende

vector<vector<pii>> g(N);
vector<bool> used(N);
vector<ll> d(N, oo);
priority_queue< pii, vector<pii>, greater<pii> > q;

void dijkstra(int k) {
    d[k] = 0;
    q.push({0, k});

    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (used[u]) continue;
        used[u] = true;

        for (auto [v, w]: g[u]) {
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                q.push({d[v], v});   
            }
        }
    }
}