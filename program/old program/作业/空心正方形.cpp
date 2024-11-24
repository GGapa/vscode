/*

#include<iostream>
using namespace std;
int main() {
    int i, j, n;
    cin >> n;
    //只确定了每行循环的次数 
    for (i = 1; i <= n; i++) {
        //每行做的事
        //①每行输出n个* 
        for (j = 1; j <= n; j++) {
            if (i==1 || j==1 || i==n|| j==n)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        //②换行 
        cout << endl;
    }
    return 0;
}
*/