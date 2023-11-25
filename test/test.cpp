#include<bits/stdc++.h>
using namespace std;
int alphacount[50];
char word[200];
bool isprime(int x)
{
	if(x<2)
	    return 0;
	for(int i=2;i<=sqrt(x);i++)
	{
		if(x%i==0)
		    return 0;
	}
	return 1;
}
int main()
{
	int maxn=0,minn=100;
	cin>>word;
	for(int i=0;i<strlen(word);i++)
		alphacount[word[i]-'a']++;
	for(int i=0;i<'z'-'a';i++)
	{
		if(alphacount[i]>maxn)
			maxn=alphacount[i];
		if(alphacount[i]<minn)
			minn=alphacount[i];
	}
	minn++;
	if(isprime(maxn-minn))
		cout<<"Lucky Word\n"<<maxn-minn<<endl;
	else
	    cout<<"No Answer\n0\n";
	return 0;
}
