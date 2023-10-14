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

//adj[v]: a set of the nodes adjacency to i
vector<vector<int>> adj(MAXN);
//d[i]: the minimum distance from starting node to i-th node
vector<int> d(MAXN);
//visited[i]: check if i-th node is visited?
vector<bool> visited(MAXN);

void reset() {
    ff(i, 0, MAXN - 5) {
        visited[i] = false;
    }
}

int bfs(int begin, int target) {

    reset();
    d[begin] = 0;

    queue<int> storage;
    storage.push(begin);

    while(!storage.empty()) {

        int v = storage.front();
        visited[v] = true;
        storage.pop();

        if (v == target) {
            return d[v];
        }

        for(auto u : adj[v]) {
            if (!visited[u]) {
                d[u] = d[v] + 1;
                storage.push(u);
            }
        }
    }

    return INF;
}


void solve() {

    int N, M, X, Y; cin >> N >> M >> X >> Y;

    while(M--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }

    cout <<  min(bfs(X, Y), bfs(Y, X));
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); 
    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);

    solve();

    return 0;
}