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

vector<int> v(MAXN);

void solve()
{
  int N; cin >> N;
  ff(i, 1, N)
    cin >> v[i];

  int target = v[1], pos = -1;

  ff(i, 2, N)
  {
    if (v[i] > target && pos == -1)
      pos = i;
    else if (v[i] <= target && pos != -1)
      swap(v[i], v[pos]),
      pos++;
  }

  if (pos == -1)
    swap(v[1], v[N]);
  else
    swap(v[1], v[pos - 1]);
  
  ff(i, 1, N)
    cout << v[i] << " ";
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // freopen("X.inp", "r", stdin);
  // freopen("Y.out", "w", stdout);

  solve();

  return 0;
}
