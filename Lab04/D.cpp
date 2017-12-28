#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double exps = 1e-6;

double f(double x, double y) {
    return 42 * pow(x, 6.0) + 54 * pow(x, 5.0) + 15 * pow(x, 2.0) + 4 * x - y;
}

double ans(double x, double y) {
    return 6 * pow(x, 7.0) + 9 * pow(x, 6.0) + 5 * pow(x, 3.0) + 2 * pow(x, 2.0) - y * x;
}

int main() {
    ios::sync_with_stdio(false);
    int caseCnt;
    cin >> caseCnt;
    while(caseCnt--) {
        double y;
        cin >> y;
        double l = 0.0, r = 200.0;
        if(fabs(f(l, y)) < exps || f(l, y) > 0) cout << fixed << setprecision(4) << ans(l, y) << '\n';
        else if(fabs(f(r, y)) < exps || f(r, y) < 0) cout << fixed << setprecision(4) << ans(r, y) << '\n';
        else {
            while(fabs(l - r) > exps) {
                double mid = (l + r) / 2;
                if(f(mid, y) < 0) l = mid;
                else r = mid;
            }
            cout << fixed << setprecision(4) << ans(l, y) << '\n';
        }
    }
    return 0;
}
