#include <iostream>
#include <random>
using namespace std;

int main()
{
    srand(time(0));
    int a,b;
    cin>>a>>b;
    if(a==1)cout<<0<<endl;
    else if(a==b&&b==0)
    {
        int c = rand()%2;
        if(c==0)cout<<-1<<endl;
        else cout<<0<<endl;
    }
    else cout<<-1<<endl;
}