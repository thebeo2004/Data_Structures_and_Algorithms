#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 1e5 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

vector<vector<int>> adj(MAXN);
vector<bool> visited(MAXN);

void dfs(int v) {
    visited[v] = true;

    for(auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
}

void solve() {

    int N, M; cin >> N >> M;

    while(M--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int ans = 0;

    ff(i, 1, N) {
        if (!visited[i]) {
            ans++;
            dfs(i);
        }
    }

    cout << ans;
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); 
    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);

    solve();

    return 0;
}