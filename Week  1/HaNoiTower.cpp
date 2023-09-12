#include <bits/stdc++.h>

using namespace std;
#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 1e6 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

ll HaNoi_Tower(int N)
{
    if (N == 1)
        return 1;
    if (N == 2)
        return 3;
    
    return 2*HaNoi_Tower(N - 1) + 1;
}

void solve()
{
    int N; cin >> N;
    cout << HaNoi_Tower(N);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}