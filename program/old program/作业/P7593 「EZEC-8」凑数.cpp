#include <iostream>
using namespace std;

int main()
{
	long long n, k, s, t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k >> s;
		if (s >= (1 + k) * k / 2 && s <= ((n - k + 1) + n) * k / 2)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}