/*
#include <iostream>
#include <cstring>
using namespace std;

char a[200], b[20000] = { '!' };
int lb = 0, ls;
int p1, p2, p3;


void tc(char L, char R)
{
	char t[20000];
	int index = 0;
	for (int i = L + 1; i < R; i++)
	{
		for (int j = 0; j < p2; j++)
		{
			int temp = i;
			if (i > 57)
			{
				if (p1 == 2)  temp -= 32;
			}
			if (p1 == 3)temp = '*';
			t[index++] = temp;
		}
	}
	if (p3 == 1)
	{
		for (int i = 0; i < index; i++)
			b[lb++] = t[i];
	}
	else
	{
		for (int i = index - 1; i >= 0; i--)
			b[lb++] = t[i];
	}
}
void ds(char L, char R)
{
	if (L == R || L > R || (R == '-') || (L == '-')
		|| (L<=57 && R>=97  )
		|| (R <= 57 && L >= 97)
		)
	{
		b[lb++] = '-';
		return;
	}
	tc(L, R);
}
int main()
{


	cin >> p1 >> p2 >> p3;
	cin >> a;
	for (int i = 0; i < 20000; i++)
	{
		if (a[i] == '\0') break;
		else if (a[i] == '-' && i !=0 )
		{
			ds(a[i - 1], a[i + 1]);
		}
		else
		{
			b[lb++] = a[i];
		}
	}
	for (int i = 0; i < 20000; i++)
	{
		if (b[i] == '!')break;
		cout << b[i];
	}
	cout << endl;
	return 0;
}
*/