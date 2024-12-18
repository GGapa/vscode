// P5018 [NOIP2018 普及组] 对称二叉树
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1e6 + 5;

struct TREE
{
    int left, right,number;
};
TREE tree[maxn];
int n;
bool check(int index1,int index2)
{
    if(index1==index2&&index1==-1)return true;
    else if(index1==-1||index2==-1)return false;
    else if(tree[index1].number!=tree[index2].number)return false;
    return check(tree[index1].left,tree[index2].right)&&check(tree[index1].right,tree[index2].left);
}
int cnt(int index)
{
    return index==-1?0:cnt(tree[index].left)+cnt(tree[index].right)+1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin>>tree[i].number;
    }
    for(int i = 1;i <= n;i++)
    {
        cin>>tree[i].left>>tree[i].right;
    }
    int ans=-1;
    for(int i = 1;i <= n;i++)
    {
        if(check(i, i))ans = max(ans, cnt(i));
    }
    cout << ans << endl;
    return 0;
}