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

//Exercise 1

  vector<int> cnt(MAXN);
  ll ans = 0;

  void Exercise1()
  {
    int N; cin >> N;
    ff(i, 1, N)
    {
      int x; cin >> x;
      ans += cnt[x];
      cnt[x]++;
    }

    cout << ans;
  }

//End Exercise 1

void solve()
{
  Exercise1();

}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  freopen("X.inp", "r", stdin);
  freopen("Y.out", "w", stdout);

  solve();

  return 0;
}