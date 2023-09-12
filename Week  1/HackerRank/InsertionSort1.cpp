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

vector<pi> v(MAXN);

void display(int N)
{
  ff(i, 1, N)
    cout << v[i].first << " ";
  cout << "\n";
  // ff(i, 1, N)
  //   cout << v[i].second << " ";
  // cout << "\n";
}

void solve()
{
  int N; cin >> N;

  ff(i, 1, N)
    cin >> v[i].first;
  
  v[N].second = v[N].first;
  int id = N;

  while(id > 0)
  {
      if (id == 1)
      {
        v[id].first = v[id].second;
      display(N);
      break;
      }
    // cout << id << "\n";
    if (v[id - 1].first >= v[id].second)
    {
      v[id].first = v[id - 1].first;
      v[id - 1].second = v[id].second;
      display(N);
    }
    else
    {
      v[id].first = v[id].second;
      display(N);
      break;
    }
    id--;
  }
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // freopen("X.inp", "r", stdin);
  // freopen("Y.out", "w", stdout);

  solve();

  return 0;
}
