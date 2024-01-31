/*
#include<iostream>
using namespace std;
int n, a[2000] = { 1 };
#define maxn 1 << n
int main() {
	cin >> n;
	for (int i = 0; i < maxn; ++i) {
		for (int j = 1; j < (maxn) - i; ++j)
			cout << " ";
		for (int j = i; j >= 0; --j)
			a[j] ^= a[j - 1];
		if (!(i % 2))
		{
			for (int j = 0; j <= i; ++j)
				cout << (a[j] ? "/\\" : "  ");
		}
		else
		{
			for (int j = 0; j <= i; j += 2)
				cout << (a[j] ? "/__\\" : "    ");
		}
		cout << endl;
	}
	return 0;
}
*/