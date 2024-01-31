/*
#include <iostream>
using namespace std;

struct student
{
	string name;
	int chi, mat, eng,xuehao;
	int all()
	{
		return chi + mat + eng;
	}
};

int main()
{
	bool bj = true;
	int i, j,n;
	cin >> n;
	student name[300];
	student ls;
	for (i = 0; i < n; i++)
	{
		cin >> name[i].chi >> name[i].mat >> name[i].eng;
		name[i].xuehao = (i+1);
	}
	while (bj)
	{
		bj = false;
		for (i = 0; i < n-1; i++)
		{
			if (name[i].all() < name[i + 1].all())
			{
				ls = name[i + 1];
				name[i + 1] = name[i];
				name[i] = ls;
				bj = true;
			}
			if (name[i].all() == name[i + 1].all())
			{
				if (name[i].chi < name[i+1].chi)
				{
					ls = name[i + 1];
					name[i + 1] = name[i];
					name[i] = ls;
					bj = true;
				}
				if (name[i].chi == name[i + 1].chi)
				{
					if (name[i].xuehao > name[i + 1].xuehao)
					{
						ls = name[i + 1];
						name[i + 1] = name[i];
						name[i] = ls;
						bj = true;
					}
				}
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		cout << name[i].xuehao << " " << name[i].all() << endl;
	}
	return 0;
}
*/