#include <bits/stdc++.h>
using namespace std;
#define int long long

int rnd(int x, int y) {
	return ((rand() * rand()) % y + x) % y + 1;
}
void Start() {
	int n = rnd(1, 50);
	cout << n << endl;
	while(n--) {
		cout << rnd(1, 10) << " ";
	}
	cout << endl;
}
signed main() {
	freopen("test.in", "w", stdout);
	struct _timeb T;
    _ftime(&T);
    srand(T.millitm);
    Start();
}
