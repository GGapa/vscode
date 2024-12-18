#include <iostream> 
using namespace std;

int main()
{
	int n;
	while(true)
	{
		cin>>n;
		if(n==0)return 0;
		cout<<((n%2==0)?("Alice"):("Bob"))<<endl;
	}
}
