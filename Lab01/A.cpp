#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int m, n;
    while(cin >> m >> n) {
        cout << "+";
        for(int i = 1; i <= m - 2; ++i) cout << "-";
        cout << "+\n";
        for(int i = 1; i <= n - 2; ++i) {
            cout << "|";
            for(int j = 1; j <= m - 2; ++j) {
                cout << "a";
            }
            cout << "|\n";
        }
        cout << "+";
        for(int i = 1; i <= m - 2; ++i) cout << "-";
        cout << "+\n";
    }
    return 0;
}
