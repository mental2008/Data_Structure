#include <iostream>
#include <queue>
using namespace std;
int n;
priority_queue<int, vector<int>, greater<int> > q;
int main() {
    ios::sync_with_stdio(false);
    int caseCnt;
    cin >> caseCnt;
    while(caseCnt--) {
        cin >> n;
        while(!q.empty()) q.pop();
        for(int i = 1; i <= n; ++i) {
            int val;
            cin >> val;
            q.push(val);
        }
        int ans = 0;
        while(n != 1) {
            n--;
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            ans += (x + y);
            q.push(x + y);
        }
        cout << ans << '\n';
    }
}
