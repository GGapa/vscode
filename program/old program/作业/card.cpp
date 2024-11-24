/*
#include <iostream> 
#include <cstdio>
using namespace std;
#define maxn 100005
int p[maxn];
namespace A
{
	void print(long long n)
	{
		for (long long i = 0; i < n; i++)
			cout << 2 << " ";
	}
}
namespace B
{
	void print(long long n)
	{
		for (long long i = 0; i < n; i++)
			cout << n << " ";
	}
}
int main()
{
	bool ifa = true, ifb = true;
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++)
	{
		cin >> p[i];
		if (p[i] != 2 * ((i % 2) - 0.5) + i)ifa = false;
		if (p[i] != i % n + 1)ifb = false;
	}
	if (ifa)
	{
		A::print(n);
		return 0;
	}
	if (ifb)
	{
		B::print(n);
		return 0;
	}

}
*/