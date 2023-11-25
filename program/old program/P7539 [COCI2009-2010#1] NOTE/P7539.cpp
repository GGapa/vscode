//P7539 [COCI2009-2010#1] NOTE
#include<iostream>
using namespace std;
int main()
{
	long long s=0;
	for (int i = 0; i < 8; i++)
	{
        int a;
        cin>>a;
        s=s*10+a;
	}
    //cout<<s<<endl;
    if(s==12345678)cout<<"ascending"<<endl;
    else if(s==87654321)cout<<"descending"<<endl;
    else cout<<"mixed"<<endl;
	return 0;
}