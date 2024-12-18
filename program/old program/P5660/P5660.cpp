//P5660 [CSP-J2019] Êı×ÖÓÎÏ·
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string a;
	int ans=0;
	cin>>a;
	for(int i = 0;i<a.size();i++)
	{
		if(a[i]=='1')ans++;
	}
	cout<<ans<<endl;
	return 0;
}
