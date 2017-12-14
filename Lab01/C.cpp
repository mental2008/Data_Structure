#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 1e5 + 5;

struct Student {
    string name;
    int id;
    int sum;
    int a, b, c;
} node[maxn];

bool cmp(Student x, Student y) {
    if(x.sum == y.sum) return x.id < y.id;
    return x.sum > y.sum;
}

int main() {
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; ++i) {
            cin >> node[i].name >> node[i].id;
            cin >> node[i].a >> node[i].b >> node[i].c;
            node[i].sum = node[i].a + node[i].b + node[i].c;
        }
        sort(node, node + n, cmp);
        for(int i = 0; i < n; ++i) {
            cout << node[i].name;
            printf(" %06d ", node[i].id);
            cout << node[i].a << " " << node[i].b << " " << node[i].c << '\n';
        }
    }
    return 0;
}
