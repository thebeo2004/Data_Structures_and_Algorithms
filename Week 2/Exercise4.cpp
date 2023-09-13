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
  int data;
  Node* next;
};

class personal_queue
{
  private:
    Node *head, *tail;
    int length = 0;
  public:
    void enqueue(int val)
    {
      Node* tmp = new Node;
      tmp->data = val;
      tmp->next = NULL;

      length++;

      if (length == 1)
      {
        head = tmp;
        tail = tmp;

        return;
      }

      tail->next = tmp;
      tail = tmp;
    }

    void dequeue()
    {
      if (length == 0)
        return;

        length--;

      Node* tmp = head->next;
      delete head;
      head = tmp;
    }

    void traversal()
    {
      Node* cur_node = head;

      while(cur_node != NULL)
        cout << cur_node->data << " ",
        cur_node = cur_node->next;
    }
};

void Exercise4()
{
  int N; cin >> N;

  personal_queue storage;

  while(N--)
  {
    string txt; cin >> txt;
    if (txt == "enqueue")
    {
      int val; cin >> val;
      storage.enqueue(val);
    }

    else
      storage.dequeue();
  }

  storage.traversal();
}

void solve()
{
  Exercise4();
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  freopen("X.inp", "r", stdin);
  freopen("Y.out", "w", stdout);

  solve();

  return 0;
}