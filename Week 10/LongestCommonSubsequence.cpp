#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 1e3 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

vector<int> v1(MAXN), v2(MAXN);
stack<int> storage;
int F[MAXN][MAXN];

void lcsProblem(int M, int N) {

    ff(i, 1, M) {
        ff(j, 1, N) {

            if (v1[i] == v2[j]) {
                F[i][j] = F[i - 1][j - 1] + 1;
            } else {
                F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            }
        }
    }
}

void trace(int M, int N) {

    if (M == 0 || N == 0) {
        return;
    }

    if (v1[M] == v1[N]) {

        storage.push(v1[M]);
        trace(M - 1, N - 1);   
    } else {

        if (F[M - 1][N] == F[M][N]) {
            trace(M - 1, N);
        } else {
            trace(M, N - 1);
        }
    }
}

void solve() {
    int M, N; cin >> M >> N;

    ff(i, 1, M) {
        cin >> v1[i];
    }

    ff(i, 1, N) {
        cin >> v2[i];
    }

    lcsProblem(M, N);

    if (F[M][N] != 0) {
        trace(M, N);
    }

    while(!storage.empty()) {
        cout << storage.top() << " ";
        storage.pop();
    }
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);

    solve();

    return 0;
}