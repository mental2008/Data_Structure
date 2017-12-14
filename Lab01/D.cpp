#include <iostream>
#include <string>
#include <cstring>
#define mem(a, i) memset(a, i, sizeof(a))
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    string s;
    while(getline(cin, s)) {
        int len = s.size();
        int cnt[30];
        mem(cnt, 0);
        for(int i = 0; i < len; ++i) {
            if(s[i] >= 'a' && s[i] <= 'z') cnt[s[i] - 'a']++;
            else if(s[i] >= 'A' && s[i] <= 'Z') cnt[s[i] - 'A']++;
        }
        for(int i = 0; i < 26; ++i) {
            if(cnt[i]) {
                cout << (char)('A' + i) << " " << cnt[i] << '\n';
            }
        }
    }
    return 0;
}
