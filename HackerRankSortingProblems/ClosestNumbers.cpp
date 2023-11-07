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

vector<int> v(MAXN);

deque<int> storage;

void solve()
{
  int N; cin >> N;
  ff(i, 1, N)
    cin >> v[i];

  sort(v.begin() + 1, v.begin() + 1 + N);

  int MIN = INF;

  ff(i, 1, N - 1)
  {
    if (v[i + 1] - v[i] < MIN)
      storage.clear(),
      storage.push_back(v[i]),
      storage.push_back(v[i + 1]),
      MIN = v[i + 1] - v[i];
    
    else if (v[i + 1] - v[i] == MIN)
      storage.push_back(v[i]),
      storage.push_back(v[i + 1]);
  }

  while(!storage.empty())
    cout << storage.front() << " ",
    storage.pop_front();
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // freopen("X.inp", "r", stdin);
  // freopen("Y.out", "w", stdout);

  solve();

  return 0;
}
