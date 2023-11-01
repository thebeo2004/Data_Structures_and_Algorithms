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

class Solution
{
    public:

    int F[MAXN];

    void initialize() {

        ff(i, 0, MAXN - 5) {
            F[i] = -INF;
        }

        F[0] = 0;
    }

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int w[], int v[], int N) 
    { 
       int ans = 0;

       ff(i, 1, N) {

        Rep(j, W, w[i]) {

            if (F[j - w[i]] != -INF) {
                F[j] = max(F[j], F[j - w[i]] + v[i]);
                ans = max(ans, F[j]);
            }
        }
       }

       return ans;

    }
};

void solve() {
    
}
int main() {

    ios_base::sync_with_stdio(false); cin.tie(0);

    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);

    solve();

    return 0;
}