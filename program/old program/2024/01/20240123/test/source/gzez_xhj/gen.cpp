#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <random>
typedef long long lld;
using namespace std;
mt19937_64 eng;
inline lld gen(lld L, lld R) {
	return (eng() % (R - L + 1) + (R - L + 1)) % (R - L + 1) + L; 
}
int main() {
	FILE *f;
	unsigned long long seed;
	f = fopen("seed.cpp", "r"); fscanf(f, "%llu", &seed); fclose(f);
	eng = mt19937_64(seed);
	f = fopen("seed.cpp", "w"); fprintf(f, "%llu", eng()); fclose(f);
	int n = 100000, q = 100000;
	printf("%d %d\n", n, q);
	for (int i = 1; i <= n; ++ i) printf("%d ", gen(0, 1)); puts("");
	for (int i = 1, l, r; i < q; ++ i) {
		l = gen(1, n);
		r = gen(1, n);
		if (l > r) swap(l, r);
		printf("1 %d %d\n", l, r);
	}
	int k = 100000;
	printf("2 %d\n", k);
	for (int l, r; k --; ) {
		l = gen(1, n);
		r = gen(1, n);
		if (l > r) swap(l, r);
		printf("%d %d\n", l, r);
	}
}
