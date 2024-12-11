#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000000 + 5;

bitset<maxn> vis;
int pri[maxn], mi[maxn];
int n;

void init(){
	for(int i = 2; i <= n; i++) {
		if(!vis[i]) pri[++pri[0]] = i, mi[i] = i;
		for(int j = 1; j <= pri[0] && i * pri[j] <= n; j++) {
			vis[i * pri[j]] = 1;
			mi[i * pri[j]] = pri[j];
			if(i % pri[j] == 0) break;
		}
	}
}

void write(int x)
{
    if(x<0)
        putchar('-'),x=-x;
    if(x>9)
        write(x/10);
    putchar(x% 10+'0');
    return;
}

int main() {
//	freopen("a.out", "w", stdout);
	n = maxn  - 5;
	init();
	printf("%d\n", pri[0]);
	for(int i = 1; i <= n; i++) write(mi[i]), putchar(' ');
	return 0;
}
