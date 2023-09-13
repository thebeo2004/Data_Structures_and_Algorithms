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

//Exercise3
  struct doubly_node
  {
    int data;
    doubly_node *_pre, *_next;
  };

  class doubly_linkedlist
  {
    private:
      doubly_node *head, *tail;
      int length;

    public:
      doubly_linkedlist()
      {
        head = new doubly_node;
        tail = new doubly_node;

        head->data = INF;
        tail->data = INF;

        head->_next = tail;
        tail->_pre = head;

        length = 0;
      }

      void insert(int val)
      {
        doubly_node* tmp = new doubly_node;
        tmp->data = val;

        doubly_node* pre_tail = tail->_pre;
        pre_tail->_next = tmp;
        tmp->_pre = pre_tail;

        tmp->_next = tail;
        tail->_pre = tmp;

        length++;
      }

      void traversal()
      {
        doubly_node* cur_node = head->_next;

        while(cur_node != tail)
          cout << cur_node->data << " ",
          cur_node = cur_node->_next;
      }

      int count_triplet()
      {
        if (length < 3)
          return 0;

        doubly_node* cur_node = head->_next->_next;

        int ans = 0;

        while(cur_node->_next != tail)
        {
          if (cur_node->data + cur_node->_pre->data + cur_node->_next->data == 0)
            ans++;
          
          cur_node = cur_node->_next;
        }

        return ans;
      }
  };

  void Exercise3()
  {
    int N; cin >> N;

    doubly_linkedlist storage;

    ff(i, 1, N)
    {
      int x; cin >> x;
      storage.insert(x);
    }

    cout << storage.count_triplet();
    // storage.traversal();
  }

//End Exercise3

void solve()
{
  Exercise3();

}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  freopen("X.inp", "r", stdin);
  freopen("Y.out", "w", stdout);

  solve();

  return 0;
}