// T351674 「RiOI-2」hacker
// https://www.luogu.com.cn/problem/T351674?contestId=122184
#include <iostream>
#include <cmath>
using namespace std;
#define int long long
signed main()
{
    int T;
    cin >> T;
    while (T--) {
        long long a, b;
        cin >> a >> b;
        bool acc = false,bot = false;
        while(a != 0 || b != 0) {
            int tmpa = a & 1, tmpb = b & 1;
            if(tmpa == 1 && tmpb == 0) bot = true;
            if(tmpa == 0 && tmpb == 1) acc = true;
            a >>= 1;
            b >>= 1;
        }
        cout << acc + bot << endl;
    }
    return 0;
}
