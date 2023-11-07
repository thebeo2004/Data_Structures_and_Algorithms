#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 1e5 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

int SegTree[4*MAXN];

void Update(int id, int low, int high, int pos)
{
    if (low == high)
    {
        SegTree[pos]++;
        return;
    }

    int mid = (low + high)/2;

    if (id >= low && id <= mid) Update(id, low, mid, 2*pos + 1);
    else Update(id, mid + 1, high, 2*pos + 2);

    SegTree[pos] = SegTree[2*pos + 1] + SegTree[2*pos + 2];
}

int Sum_Query(int l, int r, int low, int high, int pos)
{
    if (low >= l && high <= r) return SegTree[pos];
    if (low > r || high < l) return 0;

    int mid = (low + high)/2;

    return Sum_Query(l, r, low, mid, 2*pos + 1) + Sum_Query(l, r, mid + 1, high, 2*pos + 2);
}

vector<int> v(MAXN), compress;

void Reset()
{
    compress.clear();

    ff(i, 0, 4*MAXN - 5)
        SegTree[i] = 0;
}

void solve()
{
    int N; cin >> N;

    ff(i, 1, N)
    {
        cin >> v[i];

        compress.push_back(v[i]);
    }

    compress.push_back(INF);

    sort(compress.begin(), compress.end());

    ll ans = 0;

    ff(i, 1, N)
    {
        int id = lower_bound(compress.begin(), compress.end(), v[i]) - compress.begin();

        Update(id, 0, MAXN - 5, 0);

        ans += Sum_Query(id + 1, MAXN - 5, 0, MAXN - 5, 0);
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);

    int T; cin >> T;

    while(T--)
        Reset(),
        solve();

    return 0;
}
