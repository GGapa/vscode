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
	int n = 600, m = 800, q = 100;
	printf("%d %d\n", n, m);
	for (int i = 2; i <= n; ++ i) printf("%d ", i - 1); puts("");
	for (int i = 2; i <= m; ++ i) printf("%d ", i - 1); puts("");
	printf("%d\n", q);
	for (int i = 1; i <= q; ++ i) printf("1 %d\n", i);
}
