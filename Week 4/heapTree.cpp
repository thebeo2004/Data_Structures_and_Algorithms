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

class heapTree {

    private:
        int length = 0;
        int heap[MAXN];

    public:
        heapTree() {
            ff(i, 0, MAXN - 5) {
                heap[i] = -INF;
            }

            heap[0] = INF;
        }

        void swimUp(int pos) {
            while(heap[pos/2] < heap[pos]) {

                swap(heap[pos/2], heap[pos]);
                pos /= 2;
            }
        }

        void insert(int value) {
            length++;
            heap[length] = value;

            swimUp(length);
        }

        int getMax() {
            if (length == 0) {
                return -INF;
            }

            return heap[1];
        }

        void dive(int pos) {

            while(max(heap[2 * pos], heap[2 * pos + 1]) > heap[pos]) {

                if (heap[2 * pos] > heap[2 * pos + 1]) {
                    swap(heap[pos], heap[2 * pos]);
                    pos *= 2;
                } else {
                    swap(heap[2 * pos + 1], heap[pos]);
                    pos = 2 * pos + 1;
                }
            }
        }

        void removeFront() {

            if (length == 0) {
                return;
            }

            heap[1] = heap[length];
            heap[length] = -INF;
            length--;

            dive(1);
        }
};

void solve() {

}


int main() {

    ios_base::sync_with_stdio(0); cin.tie(0);

    // freopen("X.inp", "r", stdin);
    // freopen("Y.out", "w", stdout);

    solve();

    return 0;
}
