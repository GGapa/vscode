//T363242 喜牌
//https://www.luogu.com.cn/problem/T363242?contestId=123906
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 5e5 + 5; 
int T, n, k;
int a[maxn * 2], b[maxn];
int Next[maxn];
bool check(int x) {
	if (k == 0)
		return x == 1;
	if (n == 2)
		return k % 2 == x - 1;
	if (k == 1)
		return x != 1;
	return true;
}
bool KMP() {
    for (int i = 1, j = Next[1] = 0; i <= n; ) {
		while (j != 0 && b[i] != b[j])
			j = Next[j];	
		Next[++i] = ++j;
	}
    for (int i = 1, j = 1; i < n * 2; i++) {
		while (j != 0 && b[j] != a[i])
			j = Next[j];
		if (++j > n) {
			if (check(i - n + 1))
				return true;
			j = Next[j];
		}
	}
    return false;

}
int main() {
    cin >> T;
    while(T--) {
        cin >> n >> k;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            a[n + i] = a[i];
        }
        for(int i = 1; i <= n; i++)
            cin >> b[i];
        cout << (KMP() ? "YES" : "NO") << '\n';
    }
    return 0;
}