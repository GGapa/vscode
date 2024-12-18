/*
Fabled Rooks
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n, ansx[5010], ansy[5010];
bool v[5010];
struct Node {
	int x, y, id;
} a[5010], b[5010];
bool Solve(Node *a, int n, int *ans) {
	for (register int i = 1; i <= n; ++i) {
		int y = a[i].x;
		while (v[y] && y <= a[i].y) ++y;
		if (y == a[i].y + 1) return 0;
		ans[a[i].id] = y;
		v[y] = 1;
	}
	return 1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	while (cin >> n && n) {
		for (register int i = 1; i <= n; ++i) cin >> a[i].x >> b[i].x >> a[i].y >> b[i].y, a[i].id = b[i].id = i;
		memset(v, 0, sizeof(v));
		sort(a + 1, a + n + 1, [](const Node& x, const Node& y){return x.y < y.y || (x.y == y.y && x.x < y.x);});
		bool flag = Solve(a, n, ansx);
		memset(v, 0, sizeof(v));
		sort(b + 1, b + n + 1, [](const Node& x, const Node& y){return x.y < y.y || (x.y == y.y && x.x < y.x);});
		flag &= Solve(b, n, ansy);
		if (!flag) printf("IMPOSSIBLE\n");
		else {
			for (register int i = 1; i <= n; ++i) printf("%d %d\n", ansx[i], ansy[i]);
		}
	}
}