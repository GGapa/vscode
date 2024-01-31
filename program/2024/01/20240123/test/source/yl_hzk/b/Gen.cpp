#include <bits/stdc++.h>
using namespace std;
const int N = 8e2 + 5;
int n,Q;
int main() {
	freopen("b.in","w",stdout);
	n = 800,Q = 100;
	printf("%d %d\n",500,n);
	for(int i = 2;i <= 500;i++) printf("%d%c",i - 1," \n"[i == 500]);
	for(int i = 2;i <= n;i++) printf("%d%c",i - 1," \n"[i == n]);
	printf("%d\n",Q);
	for(int i = 1;i <= Q;i++) printf("%d %d\n",1,i);
	return 0;
}