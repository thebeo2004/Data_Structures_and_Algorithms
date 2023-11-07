#include <bits/stdc++.h>

using namespace std;

#define ff(i, a, b) for(int i = a; i <= b; i++)
#define Rep(i,a, b) for(int i = a; i >= b; i--)
#define MP make_pair
typedef long long ll;
typedef pair<int, int> pi;
const ll MAXN = 1e5 + 7;
const ll base = 311;
const ll INF = 1e9 + 7;

vector<int> number_compression(MAXN), v(MAXN), pos(MAXN), v1(MAXN), pos1(MAXN);

void compress(int N)
{
  sort(number_compression.begin() + 1, number_compression.begin() + 1 + N);

  ff(i, 1, N)
    v[i] = lower_bound(number_compression.begin() + 1, number_compression.begin() + 1 + N, v[i]) - number_compression.begin(),
    pos[v[i]] = i,
    v1[i] = N - v[i] + 1,
    pos1[v1[i]] = i;

}

void solve()
{
  int N; cin >> N;
  ff(i, 1, N)
    cin >> v[i],
    number_compression[i] = v[i];
  
  compress(N);

  int ans1 = 0, ans2 = 0;

  ff(i, 1, N)
  {
    if (i != v[i])
    {
      ans1++;

      int id1 = pos[i], id2 = pos[v[i]];
      swap(pos[i], pos[v[i]]);
      swap(v[id1], v[id2]);

    }

    if (i != v1[i])
    {
      ans2++;

      int id1 = pos1[i], id2 = pos1[v1[i]];
      swap(pos1[i], pos1[v1[i]]);
      swap(v1[id1], v1[id2]);
    }
  }
  
  cout << min(ans1, ans2);
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  // freopen("X.inp", "r", stdin);
  // freopen("Y.out", "w", stdout);

  solve();

  return 0;
}
