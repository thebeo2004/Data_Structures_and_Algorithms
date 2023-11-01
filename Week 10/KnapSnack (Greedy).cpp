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

    bool sortbysec(pi a, pi b) {
        
        if (a.second == b.second) {
            a.first > b.first;
        }

        return a.second < b.second;
    }

    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int w[], int v[], int N) 
    { 
       vector<pi> vect(MAXN);
       //first: weight
       //second: value

       ff(i, 1, N) {
        vect[i].first = w[i - 1];
        vect[i].second = v[i - 1];
       }

       sort(vect.begin() + 1, vect.begin() + 1 + N, sortbysec);

       int ans = 0;

        Rep(i, N, 1) {

            if (W >= vect[i].first) {
                W -= vect[i].first;
                ans += vect[i].second;
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