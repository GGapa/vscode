/*
include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int s = 1;
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < 9; i++)
		s *= a[i];
	string ls;
	for (int i = 123; i <= 789; i++)
	{
		ls = "";
		int b = i * 2;
		int c = i * 3;
		ls += (to_string(i) + to_string(b) + to_string(c));

		if (ls.length() != 9)continue;
		int ls1 = 1;
		for (int j = 0; j < 9; j++)
		{
			ls1 *=  ls[j] - 48;
		}
		
		if(ls1==s)
		{
			cout << i << " " << b << " " << c << endl;
		}
	}
	return 0;
}
*/