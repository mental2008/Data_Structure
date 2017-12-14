#include <iostream>
using namespace std;
const int maxn = 1005;
int n;
int t;
int pre[maxn];
int nxt[maxn];
int main() {
    ios::sync_with_stdio(false);
    while(cin >> t) {
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            pre[i] = i - 1;
            nxt[i] = i + 1;
        }
        nxt[n] = 1;
        pre[1] = n;
        int times = n;
        int pos = 1;
        while(times--) {
            for(int j = 1; j < t; ++j, pos = nxt[pos]) ;
            nxt[pre[pos]] = nxt[pos];
            pre[nxt[pos]] = pre[pos];
            cout << pos;
            if(times) cout << ' ';
            pos = nxt[pos];
        }
        cout << '\n';
    }
    return 0;
}
