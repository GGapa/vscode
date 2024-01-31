/*
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n, last;
	string in;
	cin >> n;
	while (n--)
	{
		cin >> in;
		int temp = (in[0] - '0') + (in[1] - '0');
		in.erase(0, 2);
		if (temp % 2 != 0)cout << "left" << " " << in << endl, last = 0;
		else
		{
			if (temp == 0)cout << ((last == 0) ? ("left ") : ("right ")) << in << endl;
			else cout << "right " << in << endl, last = 1;
		}
	}
	return 0;
}
*/