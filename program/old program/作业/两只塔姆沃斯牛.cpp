/*
#include <iostream>
using namespace std;

char a[10][10];

struct obj
{
	int x;
	int y;
	int f=0;
};


obj move(obj m)
{
	if (m.f == 3 )
	{
		if (a[m.x][m.y-1] == '*' || m.y - 1 <0 )m.f++;
		else m.y--;
	}

	if (m.f == 2)
	{
		if (a[m.x+1][m.y] == '*' || m.x + 1 > 9)m.f++;
		else m.x++;
	}

	if (m.f == 1)
	{
		if (a[m.x ][m.y+1] == '*' || m.y + 1 > 9)m.f++;
		else m.y++;
	}

	if (m.f == 0)
	{
		if (a[m.x-1][m.y] == '*' || m.x-1 <0)m.f++;
		else m.x--;
	}


	if ( m.f > 3)m.f = 0;
	return m;
}



int main()
{
	
	int x1, y1, x2, y2, ls = 0, f1 = 0, f2 = 0, time = 0;
	bool bj = false;
	obj ox;
	obj farmer;

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> a[i][j];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (ls == 2)break;
			if (a[i][j] == 'C')
			{
				ox.x = i; ox.y = j;
				bj = true;
				ls++;
			}
			else if (a[i][j] == 'F')
			{
				farmer.x = i; farmer.y = j;
				bj = true;
				ls++;
			}
		}
		if (ls == 2)break;
	}
	bj = true;
	bool bj2 = true;
	while (true)
	{
		//a[ox.x][ox.y] = '.';
		ox =move(ox);
		//a[farmer.x][farmer.y] = '.';
		farmer= move(farmer);
		//a[farmer.x][farmer.y] = 'F';
		//a[ox.x][ox.y] = 'C';
		time++;
		if (time > 1000000)
		{
			cout << 0 << endl;
			return 0;
		}
		if (ox.x == farmer.x && ox.y == farmer.y)
		{
			cout << time << endl;
			return 0;
		}
		/*
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				cout << a[i][j];
			cout << endl;
		}
		*/
/*
	}
}
*/