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

void display(int N)
{
  ff(i, 1, N)
    cout << v[i] << " ";
  cout << "\n";
}

void solve()
{
  int N; cin >> N;

  ff(i, 1, N)
    cin >> v[i];
  v[0] = -INF;

  ff(i, 2, N)
  {
    int pos = i;

    while(v[pos - 1] > v[pos])
      swap(v[pos - 1], v[pos]),
      pos--;
    
    display(N);
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
