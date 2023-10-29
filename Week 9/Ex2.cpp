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

struct OwO {
    int u, v, w;
};

bool sortbysec(OwO a, OwO b) {
    return a.w < b.w;
}

vector<OwO> edges(MAXN);
vector<int> represent(MAXN), length(MAXN);
deque<OwO> storage;

int find(int u) {
    while(u != represent[u]) {
        u = represent[u];
    }

    return u;
}

void connect(int u, int v, int w, int &cost) {

    if (find(u) == find(v)) {
        return;
    }

    OwO x; x.u = u; x.v = v; x.w = w;
    storage.push_back(x);

    u = find(u);
    v = find(v);
    cost += w;

    if (length[u] <= length[v]) {
        swap(u, v);
    }

    represent[v] = u;
    length[u] += length[v];
}

void solve() {

    int N, M; cin >> N >> M;

    ff(i, 1, M) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    sort(edges.begin() + 1, edges.begin() + 1 + M, sortbysec);

    int cost = 0;

    ff(i, 1, M) {
        connect(edges[i].u, edges[i].v, edges[i].w, cost);
    }

    cout << cost << "\n";
    while(!storage.empty()) {
        OwO x = storage.front();
        storage.pop_front();

        cout << x.u << " " << x.v << " " << x.w << "\n";
    }
}


int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);

    ff(i, 0, MAXN - 5) {
        represent[i] = i;
        length[i] = 1;
    }

    solve();

    return 0;
}