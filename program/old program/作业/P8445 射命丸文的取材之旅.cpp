/*
#include<iostream>
using namespace std;
int a[1000007];
int b[1000007];
int l[1000007];
int ans[1000007];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	for (int i = 1; i <= n; i++) {
		if (a[i] != b[i]) continue;
		ans[a[i]] = max(ans[a[i]], i - l[a[i]] - 1 - a[i]);
		l[a[i]] = i;
	}
	for (int i = 0; i <= n; i++)
		ans[i] = max(ans[i], n - l[i] - i);
	int res = 0;
	for (int i = 0; i <= n; i++)
		res = max(res, ans[i]);
	printf("%d", res);
}
*/