#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 2e5 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

vector<int> v(MAXN), cnt(207);

double find_Median(int d)
{
  int pos = d/2, res = 0;
  double value1 = -1, value2 = -1;

  ff(i, 0, 200)
  {
    if (res + cnt[i] >= pos && value1 == -1)
      value1 = i;
    if (res + cnt[i] >= pos + 1 && value2 == -1)
    {
      value2 = i;
      break;
    }

    res += cnt[i];
  }

  if (d % 2 == 0)
    return (value1 + value2);
  else
    return 2*value2;
}

void solve()
{
  int N, d; cin >> N >> d;
  ff(i, 1, N)
  {
    cin >> v[i];
    if (i <= d)
      cnt[v[i]]++;
  }

  int ans = 0;

  ff(i, d + 1, N)
  {
    if (v[i] >= find_Median(d))
      ans++;
    cnt[v[i - d]]--;
    cnt[v[i]]++;
  }

  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // freopen("X.inp", "r", stdin);
  // freopen("Y.out", "w", stdout);

  solve();

  return 0;
}
