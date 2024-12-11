//T364863 四个人的排名加起来没有小粉兔高
//https://www.luogu.com.cn/problem/T364863?contestId=1210
#include <iostream>
using namespace std;
int a, b, c, d;
int main() {
    cin >> a >> b >> c >> d;
    int sum = a + b + c + d;
    if(sum < 51) {
        cout << "Rabbit wins" << endl;
    }
    else {
        cout << "Rabbit lose" << endl;
    }
    return 0;
}