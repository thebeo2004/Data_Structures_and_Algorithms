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

struct Node
{
    Node* next;
    int data;
};

void solve()
{
  int N; cin >> N;

  Node* head = new Node;
  Node* cur_node = head;

  ff(i, 1, N)
  {
    int x; cin >> x;

    cur_node->data = x;

    if (i < N)
        cur_node->next = new Node,
        cur_node = cur_node->next;
    else
        cur_node->next = NULL;
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
