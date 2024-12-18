//P4981 ¸¸×Ó
#include <iostream>
using namespace std;
#include <cmath>
typedef long long ll;
const ll mod = 1e9+9;
ll f(ll a, ll n)
{
    ll re = 1;
    while(n)
    {
        if(n & 1)
            re = (re * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return re % mod;
}
int main()
{
    long long n;
    cin>>n;
    long long a=n;
    while(n--)
    {
    	long long input;
    	cin>>input;
 	   	cout<<f(input,input-1)<<endl;
	}
    return 0;
}
