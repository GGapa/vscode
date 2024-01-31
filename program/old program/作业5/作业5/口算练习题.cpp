/*
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	char a[20];
	char b[50][25], start;
	string z[50];
	int n, ans, c, d, index = 0;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		fgets(a, sizeof(a), stdin);
		if (a[0] == 'a' || a[0] == 'b' || a[0] == 'c')
		{
			start = a[0];
			a[0] = ' ';
		}
		sscanf(a, "%d %d", &c, &d);
		switch (start)
		{
		case'a':sprintf(b[i], "%d+%d=%d", c, d, c + d); break;
		case'b':sprintf(b[i], "%d-%d=%d", c, d, c - d); break;
		case'c':sprintf(b[i], "%d*%d=%d", c, d, c * d); break;
		}
		//sprintf(b[i]"%s\r\n%d\r\n", b, strlen(b));
	}
	for (int i = 0; i < n; i++)
	{
		printf("%s\r\n%d\r\n", b[i], strlen(b[i]));
	}
	return 0;
}
*/