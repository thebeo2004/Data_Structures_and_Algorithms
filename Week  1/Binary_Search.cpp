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

vector<int> v(MAXN);

int binary_search(int l, int r, int value)
{
    if (r < l)
        return -1;
    
    int mid = (l + r)/2;

    if (v[mid] == value)
        return mid;
    
    if (value >= v[mid])
        return (mid + 1, r, value);
    else
        return (l, mid - 1, value);
}

void solve()
{

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();

    return 0;
}