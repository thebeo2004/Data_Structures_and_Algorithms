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



//Quick sort

  void Quick_sort(int l, int r)
  {
    if (r <= l)
    {
      if (r == l)
        cout << l << " "  << v[l] << "\n";
      return;
    }
    
    int target = v[r], id = -1;
    ff(i, l, r - 1)
    {
      if (v[i] > target && id == -1)
        id = i;
      else if (v[i] <= target && id > 0)
      {
        swap(v[i], v[id]);
        id++;
      }
    }

    cout << "pivot " << target << "\n";
    cout << "left_array ";
    ff(i, l, id - 1)
      cout << v[i] << " ";
    cout << "\n" << "right_array ";
    ff(i, max(id + 1, 1), r)
      cout << v[i] << " ";
    cout << "\n";

    if (id == -1)
      Quick_sort(l, r - 1);
    else
    {
      swap(v[r], v[id]);
      Quick_sort(l, id - 1);
      Quick_sort(id + 1, r);
    }

  }
//End Quick sort


void solve()
{
  int N; cin >> N;

  ff(i, 1, N)
    cin >> v[i];

  Quick_sort(1, N);
  
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  freopen("X.inp", "r", stdin);
  freopen("Y.out", "w", stdout);

  solve();

  return 0;
}