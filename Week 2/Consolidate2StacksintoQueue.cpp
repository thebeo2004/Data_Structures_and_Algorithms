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

//Consolidate 2 stack -> 1 queue

struct Node
{
  int data;
  Node* next;
};

class Stack
{
  private:
    Node* head;
    int length = 0;

  public:
    void Insert(int val)
    {
      Node* tmp = new Node;
      tmp->data = val;

      length++;

      if (length == 1)
      {
        head = tmp;
        head->next = NULL;

        return;
      }

      tmp->next = head;
      head = tmp;
    }

    bool is_empty()
    {
      return (length == 0);
    }

    void Pop()
    {
      if (is_empty())
        return;

      length--;
      Node* tmp = head->next;
      delete head;
      head = tmp;
    }

    int get_top()
    {
      if (is_empty())
        return -1;

      return head->data;
    }
};

Stack storage1, storage2;

int dequeue()
{
  while(!storage1.is_empty())
    storage2.Insert(storage1.get_top()),
    storage1.Pop();
  
  int ans = storage2.get_top();
  storage2.Pop();

  while(!storage2.is_empty())
    storage1.Insert(storage2.get_top()),
    storage2.Pop();
  
  return ans;
}

void solve()
{
  int T; cin >> T;

  while(T--)
  {
    string txt; cin >> txt;
    if (txt == "enqueue")
    {
      int val; cin >> val;
      storage1.Insert(val);
    }

    else
      cout << dequeue() << " ";
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