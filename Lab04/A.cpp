#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 20005;
struct Node {
    int bright;
    int pos;
    bool operator < (const Node& e) const {
        return bright > e.bright;
    }
} node[maxn];
int query[maxn];
int main() {
    ios::sync_with_stdio(false);
    int caseCnt;
    cin >> caseCnt;
    while(caseCnt--) {
        int n, q;
        cin >> n >> q;
        for(int i = 1; i <= n; ++i) {
            cin >> node[i].bright;
            node[i].pos = i;
        }
        sort(node + 1, node + n + 1);
        for(int i = 1; i <= n; ++i) {
            query[node[i].pos] = i;
        }
        while(q--) {
            int enquiry;
            cin >> enquiry;
            cout << query[enquiry] << '\n';
        }
    }
    return 0;
}
