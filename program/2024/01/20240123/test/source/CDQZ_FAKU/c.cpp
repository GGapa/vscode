#include <bits/stdc++.h>

const int MAXN = 100005;

const int MOD  = 998244353;

using namespace std;

inline long long Qpow (const long long a, const long long b = MOD - 2) {
	if (b == 1) return a;
	long long Ret = Qpow (a, b >> 1);
	if (b & 1) return Ret * Ret % MOD * a % MOD;
	else return Ret * Ret % MOD;
}

long long N;

int main () {
	
	cin >> N;
	
	for (int i = 1; i <= 10; ++ i)
		cerr << N * i << endl;
	
	cerr << Qpow (576) << endl;
	
	cout << N % MOD * Qpow (8) % MOD << endl;
	
	return 0;
}
