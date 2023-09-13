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

//Exercise2

  struct Node
  {
    int data;
    Node* next;
  };

  class linked_list
  {
    private:
      Node* head = NULL;
      int length = 0;

      Node* traversal(Node* start_, int pos) // find the left element of pos-th element
      {
        pos--;
        while(pos--)
          start_ = start_->next;
        return start_;
      }

    public:
      void insert(int pos, int value)
      {
        if (pos > length)
          return;

        length++;

        Node* tmp = new Node;
        tmp->data = value;
        
        if (head == NULL)
        {
          head = tmp;
          head->next = NULL;
          return;
        }
        
        if (pos == 0)
        {
          tmp->next = head;
          head = tmp;
          return;
        }
        
        Node* pre_node = traversal(head, pos);

        if (pre_node->next == NULL)
          pre_node->next = tmp,
          tmp->next = NULL;
        else
          tmp->next = pre_node->next,
          pre_node->next = tmp;
      }

      void remove(int pos)
      {
        if (pos >= length)
          return;

        if (pos == 0)
        {
          Node* tmp = head->next;
          delete head;
          head = tmp;

          return;
        }

        Node* pre_node = traversal(head, pos);
        Node* tmp = pre_node->next;
        pre_node->next = tmp->next;
        delete tmp;

        length--;
      }

      void display()
      {
        Node* start_ = head;

        while(start_ != NULL)
          cout << start_->data << " ",
          start_ = start_->next;
      }
  };


  void Exercise2()
  {
    int N; cin >> N;

    linked_list storage;

    while(N--)
    {
      string txt; cin >> txt;
      if (txt == "insert")
      {
        int pos, value; cin >> pos >> value;
        storage.insert(pos, value);
      }
      else
      {
        int pos; cin >> pos;
        storage.remove(pos);
      }
    }

    storage.display();
  }
//End Exercise

void solve()
{
  Exercise2();

}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  freopen("X.inp", "r", stdin);
  freopen("Y.out", "w", stdout);

  solve();

  return 0;
}