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

vector<string> v(MAXN);
deque<string> F1, F2;

void construct(int l, int r)
{
  int mid = (l + r)/2;

  ff(i, l, mid)
    F1.push_back(v[i]);
  ff(i, mid + 1, r)
    F2.push_back(v[i]);
}

bool compare(string a, string b)
{
  if (a.size() < b.size())
    return true;
  if (a.size() > b.size())
    return false;
  
  ff(i, 0, int(a.size()) - 1)
  {
    if (a[i] < b[i])
      return true;

    if (a[i] > b[i])
      return false;
  }
  
  return true;
}

string get_value()
{
  int flag; string value;

  if (F1.empty())
    flag = 2;
  else if (F2.empty())
    flag = 1;
  else
  {
    if (compare(F1.front(), F2.front()))
      flag = 1;
    else
      flag = 2;
  }

  if (flag == 1)
    value = F1.front(),
    F1.pop_front();
  else
    value = F2.front(),
    F2.pop_front();
  return value;
}

void Merge(int l, int r)
{
  construct(l, r);
  
  ff(i, l, r)
    v[i] = get_value();
}

void Merge_Sort(int l, int r)
{
  if (l == r)
    return;

  int mid = (l + r)/2;
  Merge_Sort(l, mid);
  Merge_Sort(mid + 1, r);
  Merge(l, r);
}

void solve()
{
  int N; cin >> N;
  ff(i, 1, N)
    cin >> v[i];

  Merge_Sort(1, N);

  ff(i, 1, N)
    cout << v[i] << "\n";

}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // freopen("X.inp", "r", stdin);
  // freopen("Y.out", "w", stdout);

  solve();

  return 0;
}
