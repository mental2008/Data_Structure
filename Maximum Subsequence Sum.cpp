#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define maxn 100100
using namespace std;
int n;
int a[maxn];
int main() {
	while(~scanf("%d", &n)) {
		memset(a, 0, sizeof(a));
		int maxSum = 0, nowSum = 0;
		int nowstart = 0, nowend = 0;
		int ansstart = 0, ansend = 0;
		bool is_zero = false;
		for(int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if(a[i] == 0) is_zero = true;
			if(nowSum < 0) {
				nowSum = 0;
				nowstart = i;
			}
			nowSum += a[i];
			nowend = i;
//			printf("%d %d\n", nowstart, nowend);
			if(nowSum > maxSum) {
				maxSum = nowSum;
				ansstart = a[nowstart];
				ansend = a[nowend];
			}
		}
		if(maxSum == 0) {
			if(is_zero == true) {
				ansstart = 0;
				ansend = 0;
			}
			else {
				ansstart = a[0];
				ansend = a[n - 1];
			}
		}
		printf("%d %d %d\n", maxSum, ansstart, ansend);
	}
	return 0;
} 
