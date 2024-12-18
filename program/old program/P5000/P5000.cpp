#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int n, r;
vector<int> mul(vector<int> &A, int b)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size() || t; i++)
    {
        if (i < A.size())
            t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
int main()
{
    scanf("%d %d", &n, &r);
    vector<int> vec;
    while (n--)
    {
        string s;
        cin >> s;
        vec.clear();
        vec.push_back(1);
        for (int i = 0; i < s.length(); i++)
        {
            int temp=s[i]-'A';
            temp+=r;
            temp%=26;
            s[i]=temp+'A';
        }
        cout<<s<<endl;
        for(int i = s.length()-1;i>=0;i--)
        {
            vec = mul(vec,s[i]);
        }
        for (int i = vec.size() - 1; i >= 0; i--)
            printf("%d", vec[i]);
            cout<<endl;
    }
}