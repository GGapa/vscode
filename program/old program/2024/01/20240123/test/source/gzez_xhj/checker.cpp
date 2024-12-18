#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <time.h>
typedef long long lld;
using namespace std;
int main() {
	for (;;) {
		system("b_gen > b.in");
		int t = clock();
		system("b.exe");
		printf("TIME USED: %.3lf\n", (double)(clock() - t) / CLOCKS_PER_SEC);
//		system("0_BF.exe");
		if (0 && system("fc 0.out 0_BF.out")) {
			puts("DIFFERENT ANSWER!");
			return 0;
		}
	}
}
