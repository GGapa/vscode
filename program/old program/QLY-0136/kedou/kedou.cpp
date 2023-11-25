#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;
void ans1()
{
    string ans = "NO";
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c && c == d)
        ans = "YES";
    if (a == b && c == d)
        ans = "YES";
    if (a == d && b == c)
        ans = "YES";
    cout << ans << endl;
}

int main()
{
    freopen("kedou.in","r",stdin);
    freopen("kedou.out","w",stdout);
    ans1();
    return 0;
}