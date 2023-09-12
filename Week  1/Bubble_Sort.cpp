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


  void display(double step, int N)
  {
    cout << "step" << step << ": ";
    ff(i, 1, N)
      cout << v[i] << " ";
    cout << "\n";
  }

//Bubble sort
  void Bubble_sort(int N)
  {
    display(0, N);

    bool any_swap = true;
    int step = 1;

    while(any_swap)
    {
      any_swap = false;
      double x = step + 0.0;
      cout << "step" << step << ":\n";

      ff(i, 1, N - 1)
      {
        if (v[i] > v[i + 1])
          swap(v[i], v[i + 1]),
          any_swap = true;
        
        x += 0.1;
        cout << "  ";
        display(x, N);
      }

      step++;
      
    }
  }
//end Bubble sort

void solve()
{
  int N; cin >> N;

  ff(i, 1, N)
    cin >> v[i];

  Bubble_sort(N);
  
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  freopen("X.inp", "r", stdin);
  freopen("Y.out", "w", stdout);

  solve();

  return 0;
}