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

class Stack
{
  private:
    Node* head;
    int length = 0;

  public:

    void push(int val)
    {
      length++;

      Node* tmp = new Node;
      tmp->data = val;

      if (length == 1)
      {
        tmp->next = NULL;
        head = tmp;
        return;
      }

      tmp->next = head;
      head = tmp;
    }

    void pop()
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

  void Exercise5()
  {
    int N; cin >> N;
    
    Stack storage;

    while(N--)
    {
      string txt;
      cin >> txt;

      if (txt == "push")
      {
        int val; cin >> val;
        storage.push(val);
      }
      else  
        storage.pop();
    }

  storage.traversal();
}

void solve()
{
  Exercise5();
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  freopen("X.inp", "r", stdin);
  freopen("Y.out", "w", stdout);

  solve();

  return 0;
}