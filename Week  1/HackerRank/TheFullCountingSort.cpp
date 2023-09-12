#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 1e2 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

vector<vector<string>> cnt(MAXN);

void display(int x)
{
  for(auto i: cnt[x])
    cout << i << " ";
}

void solve()
{
  int N; cin >> N;
  ff(i, 1, N)
  {
    int x; string s;
    cin >> x >> s;

    if (i <= N/2)
      s = "-";

    cnt[x].push_back(s);
  }

  ff(i, 0, MAXN - 5)
    display(i);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // freopen("X.inp", "r", stdin);
  // freopen("Y.out", "w", stdout);

  solve();

  return 0;
}
