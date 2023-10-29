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
vector<pair<int, int>> order(MAXN);

void dfs(int u) {

    for(auto i : adj[u]) {
        order[i].first++;
        dfs(i);
    }
}

void solve() {

    int N, M; cin >> N >> M;

    while(M--) {
        int u, v; cin >> u >> v;
        adj[v].push_back(u);
    }

    ff(i, 1, N) {
        dfs(i);
    }

    sort(order.begin() + 1, order.begin() + 1 + N);
    Rep(i, N, 1) {
        cout << order[i].second << " ";
    }

    
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);


    ff(i, 0, MAXN - 5) {
        order[i].first = 0;
        order[i].second = i;
    }

    solve();

    return 0;
}