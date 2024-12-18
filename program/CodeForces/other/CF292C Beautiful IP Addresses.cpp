#include <stdio.h>
#include <string.h>
#include <assert.h>

#include <vector>
#include <iostream>
#include <algorithm>

#define LOG(FMT...) fprintf(stderr, FMT)

#define eb push_back
#define em emplace

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
constexpr int N = 100005, M = 400005;
constexpr int mod = 1e9 + 7;

int n, a[N];
int p[N];
string s;
vector<string> res;

void work(int sz) {
	constexpr int B = 256;
	for (int i = 1, x = p[0]; i < sz && x < B; ++i) {
		for (int j = i + 1, y = p[i]; j < sz && y < B; ++j) {
			for (int k = j + 1, z = p[j]; k < sz && z < B; ++k) {
				bool ok = false;
				if (p[k] == 0) {
					if (k == sz - 1) {
						ok = true;
					}
				} else {
					int t = 0;
					for (int l = k; l < sz && t < B; ++l) {
						t = t * 10 + p[l];
					}
					ok = (t < B);
				}
				if (ok) {
					s.clear();
					for (int l = 0; l < i; ++l) {
						s.eb(p[l] ^ 48);
					}
					s.eb('.');
					for (int l = i; l < j; ++l) {
						s.eb(p[l] ^ 48);
					}
					s.eb('.');
					for (int l = j; l < k; ++l) {
						s.eb(p[l] ^ 48);
					}
					s.eb('.');
					for (int l = k; l < sz; ++l) {
						s.eb(p[l] ^ 48);
					}
					res.eb(s);
				}
				if (z == 0) {
					break;
				}
				z = z * 10 + p[k];
			}
			if (y == 0) {
				break;
			}
			y = y * 10 + p[j];
		}
		if (x == 0) {
			break;
		}
		x = x * 10 + p[i];
	}
}

void dfs(int x, int was) {
	if (was == (1 << n) - 1) {
		for (int i = 0; i < x; ++i) {
			p[2 * x - i - 1] = p[i];
		}
		work(2 * x);
		for (int i = 0; i < x - 1; ++i) {
			p[2 * x - i - 2] = p[i];
		}
		work(2 * x - 1);
	}
	if (x == 6) {
		return;
	}
	for (int i = 0; i < n; ++i) {
		p[x] = a[i];
		dfs(x + 1, was | 1 << i);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	dfs(0, 0);
	cout << res.size() << '\n';
	for (string s : res) {
		cout << s << '\n';
	}
	return 0;
}