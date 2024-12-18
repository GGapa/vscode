#include <bits/stdc++.h>
using namespace std;

long long rnd(int l, int r) 
{
	return (long long)rand * rand() % (r - l + 1) + l;
}
int main()
{
	srand(time(0));
	freopen("in.in","w",stdout);
	cout<<rnd(0,1000000000)<<" "<<rnd(0,1000000000)<<endl;
	return 0;
}
