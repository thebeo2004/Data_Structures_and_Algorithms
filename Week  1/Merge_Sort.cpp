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

//Merge Sort
  deque<int> F1, F2;

  int get_value()
  {
    int flag, ans;

    if (F1.empty())
      flag = 2;
    else if (F2.empty())
      flag = 1;
    else
    {
      if (F1.front() <= F2.front())
        flag = 1;
      else
        flag = 2;
    }

    if (flag == 1)
      ans = F1.front(),
      F1.pop_front();
    else
      ans = F2.front(),
      F2.pop_front();
    
    return ans;
  }

  void Merge(int l, int r)
  {
    int mid = (l + r)/2;
    
    ff(i, l, mid)
      F1.push_back(v[i]);
    ff(i, mid + 1, r)
      F2.push_back(v[i]);
    
    ff(i, l, r)
      v[i] = get_value();

  }

  void Merge_sort(int l, int r)
  {
    if (l == r)
    {
      cout << "index" << " " << l << " " << v[l] << "\n";
      return;
    }
    int mid = (l + r)/2;

    Merge_sort(l, mid);
    Merge_sort(mid + 1, r);
    Merge(l, r);

    cout << "range" << " " << l << " "  << r << "\n";
    ff(i, l, r)
      cout << v[i] << " ";
    cout << "\n";
  }
//End Merge Sort

void solve()
{
  int N; cin >> N;

  ff(i, 1, N)
    cin >> v[i];

  
  Merge_sort(1, N);
  
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  freopen("X.inp", "r", stdin);
  freopen("Y.out", "w", stdout);

  solve();

  return 0;
}