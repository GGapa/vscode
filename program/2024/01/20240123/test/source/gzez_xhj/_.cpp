#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
typedef long long lld;
using namespace std;
int main() {
	int n = 6;
	printf("%d %d\n", n, 1ll * n * (n - 1) / 2);
	for (int i = 1; i <= n; ++ i)
		for (int j = i + 1; j <= n; ++ j)
			printf("%d %d 1\n", i, j);
	freopen("0.in", "r", stdin);
	freopen("0.out", "w", stdout);
	return 0;
}
