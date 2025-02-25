#include <bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vll vector<long long>
using namespace std;


// Complexity: The pre proccessing is O(nlog(n)). Most queries such as sum are O(log(n));
// So in that case, it is pretty much always better to use a segTree.
// However, when the queries are min or max, the complexity of each query becomes O(1); 

class SparseTable
{
    int logn;
    vector<vll> tb;
    vi logs;

public:
    // Constructor takes only `n` and `arr` as arguments
    SparseTable(int n, vll arr) : logs(n + 1), tb(log2(n) + 1, vll(n)) {
        // Build the `logs` array
        logs[1] = 0;
        for (int i = 2; i <= n; i++) {
            logs[i] = logs[i / 2] + 1;
        }
        
        // Set logn to the maximum power needed for `n`
        this->logn = logs[n];
        
        // Initialize the first row of `tb` with `arr` values
        for (int i = 0; i < n; i++) {
            tb[0][i] = arr[i];
        }

        // Build the sparse table
        for (int k = 1; k <= logn; k++) {
            for (int i = 0; i + (1 << k) <= n; i++) {
                tb[k][i] = min(tb[k - 1][i], tb[k - 1][i + (1 << (k - 1))]);
            }
        }
    }

    // Range minimum query on the range [l, r]
    ll query(int l, int r) {
        //if not indexed in 1 remove this.
        l--;
        r--;
        int len = r - l + 1;
        int k = logs[len];
        return min(tb[k][l], tb[k][r - (1 << k) + 1]);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vll arr(n);

    // Initializing array;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Initialize the Sparse Table with the array
    SparseTable sp(n, arr);

    // Perform range minimum queries
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        cout << sp.query(l, r) << endl;
    }

    return 0;
}
