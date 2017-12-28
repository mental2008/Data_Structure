#include <cstdio>
#include <cstring>
#define mem(a, i) memset(a, i, sizeof(a))
int n, m;
int cmp[30][30];

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    while(scanf("%d%d", &n, &m), n || m) {
        int status = 0;
        int turn;
        mem(cmp, 0);
        for(int i = 1; i <= m; ++i) {
            char c[5];
            scanf("%s", &c);
            int u = c[0] - 'A', v = c[2] - 'A';
            if(!status) {
                if(cmp[u][v] == -1 || cmp[v][u] == 1) {
                    status = 3;
                    turn = i;
                }
                else if(cmp[u][v] == 0) {
                    cmp[u][v] = 1;
                    cmp[v][u] = -1;
                    for(int j = 0; j < n; ++j) {
                        for(int k = 0; k < n; ++k) {
                            for(int p = 0; p < n; ++p) {
                                if(cmp[k][j] == 1 && cmp[j][p] == 1) {
                                    cmp[k][p] = 1;
                                    cmp[p][k] = -1;
                                }
                                if(cmp[k][j] == -1 & cmp[j][p] == -1) {
                                    cmp[k][p] = -1;
                                    cmp[p][k] = 1;
                                }
                            }
                        }
                    }
                }
                if(status) continue;
                bool ok = true;
                for(int j = 0; j < n; ++j) {
                    for(int k = j + 1; k < n; ++k) {
                        if(!cmp[j][k]) ok = false;
                    }
                }
                if(ok) {
                    status = 1;
                    turn = i;
                }
            }
        }
        if(!status) {
            for(int i = 0; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    if(!cmp[i][j]) status = 2;
                }
            }
        }
        if(status == 1) {
            printf("Sorted sequence determined after %d relations: ", turn);
            for(int i = 0; i < n; ++i) printf("%c", (char)(i + 'A'));
            puts(".");
        }
        else if(status == 2) printf("Sorted sequence cannot be determined.\n");
        else if(status == 3) printf("Inconsistency found after %d relations.\n", turn);
    }
    return 0;
}
