/*
#include <iostream>
using namespace std;

struct student
{
	string name;
	int c;
	int m;
	int e;
	int all()
	{
		return c + m + e;
	}
};

int main()
{
	int i,max=-1,ls;
	student people[1000];
	int n;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> people[i].name >>people[i].c >> people[i].m >> people[i].e;
	for (i = 0; i < n; i++ )
	{
		if (people[i].all() > max)
		{
			max = people[i].all();
			ls = i;
		}
	}
	cout << people[ls].name << " " << people[ls].c << " "
		<< people[ls].m << " " << people[ls].e << endl;;
	return 0;
}
*/