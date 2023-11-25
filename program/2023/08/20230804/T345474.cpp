//T345474 「SFCOI-3」进行一个拆的解
//https://www.luogu.com.cn/problem/T345474?contestId=118761
// 60pts

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn];
int n,T;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while(T--)
    {
        bool flag0 = true;
        cin >> n ;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(a[i] != 0)
            {
                flag0 = false;
            }
        }
        if(n % 2 == 0)
        {
            bool flag1 = true;
            int mid = n / 2;
            for(int i = 1; i <= mid; i++)
            {
                if(a[i] != a[i + mid])
                {
                    cout << "YES" << endl;
                    flag1 = false;
                    break;
                }
            }
            if(flag1) 
                cout << "NO" << endl;
        }
        else if(n % 2 != 0)
        {
            bool flag1 = true;
            int mid = n / 2;
            for(int i = 1; i <= mid; i++)
            {
                if(a[i] != a[i + mid] || a[i] != a[i + mid + 1])
                {
                    flag1 = false;
                    break;
                }
            }
            for(int i = n; i >= mid + 1; i--)
            {
                if(a[i] != )
            }
            if(flag1) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else if(flag0)cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}