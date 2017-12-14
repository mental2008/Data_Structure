#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int maxn = 1005;
int n;

struct Teller {
    string name;
    int res;
} node[maxn];

struct Customer {
    int arrivetime;
    string name;
    int occupy;
} customer[maxn];

int main() {
    ios::sync_with_stdio(false);
    while(cin >> n) {
        for(int i = 1; i <= n; ++i) node[i].name == "NULL";
        int arrivetime;
        int cnt = 0;
        while(cin >> arrivetime) {
            if(arrivetime == -1) break;
            string name;
            int occupy;
            cin >> name >> occupy;
            customer[++cnt].arrivetime = arrivetime;
            customer[cnt].name = name;
            customer[cnt].occupy = occupy;
        }
        int t = 0;
        int pos = 1;
        while(pos <= cnt) {
            if(t != 0) cout << '\n';
            t++;
            cout << t << ":\n";
            for(int i = 1; i <= n; ++i) {
                cout << "Teller" << i << ": ";
                if(node[i].name != "NULL" && node[i].res == 0) {
                    node[i].name = "NULL";
                }
                if(node[i].name == "NULL") {
                    if(pos <= cnt) {
                        if(customer[pos].arrivetime <= t) {
                            node[i].name = customer[pos].name;
                            node[i].res = customer[pos].occupy;
                            pos++;
                        }
                    }
                }
                node[i].res--;
                cout << node[i].name << '\n';
            }
            cout << "Waiting:";
            bool ok = false;
            for(int i = pos; i <= cnt && customer[i].arrivetime <= t; ++i) {
                ok = true;
                cout << " " << customer[i].name;
            }
            if(!ok) cout << " NULL";
            cout << '\n';
        }
    }
    return 0;
}
