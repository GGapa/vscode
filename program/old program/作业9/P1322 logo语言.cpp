/*
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int len;
string a;

int num(int start, int end)
{
	int jia = 0;
	int ls = 1;
	if (a[end] == ']')end -= 1;
	else if (a[end+1] != ' '&&a[end+1]!='['&&a[end+1]!=']')end += 1;
	for (int i = end; i >= start; i--)
	{
		if (a[i] == '[' || a[i] == ']' || a[i] == ' ')continue;
		jia += (a[i] - 48) * ls;
		ls *= 10;
	}
	return jia;
}

int  move(int start,int end)
{
	if (end - start < 4)
		return 0;
	long long ans = 0;
	len = a.length();
	for (int i = start; i < end; i++)
	{
		if (a[i] == 'F')
		{
			i += 3;
			for (int j = i; j < len; j++)
			{
				if (a[j] == ' ' || j == len - 1)
				{
 					ans+=num(i, j-1);
					break;
				}
			}
		}
		if (a[i] == 'B')
		{
			i += 3;
			for (int j = i; j < len; j++)
			{
				if (a[j] == ' ' || j == len - 1)
				{
					ans-=num(i, j-1);
					break;
				}
			}
		}


		if (a[i] == 'T')
		{
			int ls=-1,temp;
			i += 2;
			for (int j = i; j < end; j++)
			{
				if (a[j] == '[' || j == len - 1 || a[j] == ' ')
				{
					temp = num(i, j-1);
					break;
				}
			}
			int v1 = 0,v2=0;
			bool bj = false;
			for (int j = i; j < end; j++)
			{
				if (a[j] == '[')
				{
					v1++;
					bj = true;
				}
				if (a[j] == ']')
				{
					ls = j;
					v2++;
					if (v1 == v2 && v2 != 0)
						break;
				}
			}
			ans += temp * move(i + 1, ls);
			i = ls;
		}
	}
	return ans;
}


int main()
{
	getline(cin, a);
	while(a.find("  ")!=string::npos)
		a = a.replace(a.find("  "),2, " ");
	//cout.setf(ios::fixed, ios::floatfield);
	cout << abs(move(0, a.length())) << endl;
}
*/