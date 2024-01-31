/*
#include <iostream>
using namespace std;
int a[5000][3];

int b[10000];
int p;
void clear()
{
	for(int i=0;i<10000;i++)
	{
		b[i] = -1;
	}
	p = 0;
}
void print()
{
	for (int i = 0; i < 10000; i++)
	{
		cout << b[i] << " ";
		if (b[i] == -1) break;
	}
}
bool inList(int t)
{
	for (int i = 0; i < 10000; i++)
	{
		if (b[i] == -1) return false;
		if (b[i] == t)return true;
	}
	return false;

}


int main()
{
	
	int i, q, n, m, start=0, end=0, num = 0;
	long small = 500000000;
	bool bj = true;


	cin >> n >> m;
	for (i = 0; i < m; i++)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	for (i = 0; i < m; i++)
	{
		clear();
		
		start = a[i][0];
		b[p] = start;
		end = a[i][1];
		b[++p] = end;
		num = a[i][2];
		bj = true;
		int count = 0;
		int tempQ = -1;
		while (bj)
		{
			bj = false;
			for (q = 0; q < m; q++)
			{
				if (i == q) continue;
				if (q == tempQ) continue;
				if (end == a[q][0])
				{
					tempQ = q;
					if (inList(a[q][1])) continue;
					count++;
					bj = true;
					end = a[q][1];
					b[++p] = end;
					num += a[q][2];
					if (start == end )
					{
						if (p > 2)
						{
							print();
							cout << "t:" << num << endl;
							if (num < small) small = num;
						}
						bj = false;
						
					}
					break;
				}
			}
			if (count > m) break;
			
		}
		
	}
	if (small == 500000000)cout << "No solution." << endl;
	else cout << small << endl;
	return 0;

}*/