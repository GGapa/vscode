/*#include <iostream>
#include <string>
#include <stack>
using namespace std;
constexpr auto MXAN = 1010;
stack<int> a;

int main()
{
	char n;
	int num = 0, l, r;
	do
	{
		n = getchar();
		if ('0' <= n && n <= '9')
			num = num * 10 + (n - '0');
		else if (n == '.')
		{
			a.push(num);
			num = 0;
		}
		else if (n != '@')
		{
			r = a.top();
			a.pop();
			l = a.top();
			a.pop();
			switch (n)
			{
			case('+'):a.push(l + r); break;
			case('-'):a.push(l - r); break;
			case('*'):a.push(l * r); break;
			case('/'):a.push(l / r); break;
			}
		}
	} while (n != '@');
	cout << a.top() << endl;
	return 0;
}
*/