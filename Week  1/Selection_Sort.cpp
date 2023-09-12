#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 5e4 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

vector<int> v(MAXN);

//Selection Sort
  void display(double step, int N)
  {
    cout << "step" << step << ": ";
    ff(i, 1, N)
      cout << v[i] << " ";
    cout << "\n";
  }

  void Selection_sort(int N)
  {
    display(0, N);

    ff(i, 1, N - 1)
    {
      int pos = i;

      ff(j, i + 1, N)
        if (v[j] < v[pos])
          pos = j;
      
      
      swap(v[i], v[pos]);
      display(i, N);
    }
  }
//End Selection sort

void solve()
{
  int N; cin >> N;

  ff(i, 1, N)
    cin >> v[i];

  Selection_sort(N);
  
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

//   freopen("X.inp", "r", stdin);
//   freopen("Y.out", "w", stdout);

  solve();

  return 0;
}