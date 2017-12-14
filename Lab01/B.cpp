#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int m, n;
int ans;

void dfs(int last, int depth, int res) {
    if(depth == n) {
        if(res == 0) ans++;
        return;
    }
    for(int i = min(last, res); i >= 0; --i) {
        dfs(i, depth + 1, res - i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int caseCnt;
    cin >> caseCnt;
    while(caseCnt--) {
        cin >> m >> n;
        ans = 0;
        dfs(INF, 0, m);
        cout << ans << '\n';
    }
    return 0;
}
