//T297008 202212B 计算
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int main()
{
    string input;
    cin>>input;
    int total = input[0]+input[1]+input[2]-'0'*3;
    cout<<total<<endl<<total*total<<endl<<total*total*total<<endl;
    return 0;
}