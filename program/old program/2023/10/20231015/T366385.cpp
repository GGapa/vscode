#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

unsigned short T,n;
unsigned short a[505];
vector<pair<unsigned short,pair<unsigned short,unsigned short>>> ans;
bool dfs(unsigned short dep,vector<unsigned short>&b){
    int flag=0;
    if(b.size()==1) return 1;
    if(dep<0) return 0;
    vector<unsigned short> Box[518];
    vector<unsigned short> Next;
    for(int i=0;i<(int)b.size();++i){
        Box[b[i]].push_back(i);
        Next.push_back(b[i]);
    }
    for(int i=0;i<=(n>=400?1:2);++i){
        for(int j=b.size()-1;j>=0;--j){
            unsigned short sbjfb=b[i]^b[j];
            unsigned short Fir=0,l=0,r=Box[sbjfb].size()-1;
            for(int k=Box[sbjfb].size()-1;k>=0;--k){
                unsigned short T=Box[sbjfb][k];
                if(T>i&&T<j){
                    Next.erase(Next.begin()+i,1+Next.begin()+j);
                    unsigned short ssum=0;
                    for(unsigned short l=i;l<=j;++l) ssum^=b[l];
                    Next.insert(Next.begin()+i,ssum);
                    ans.push_back({i+1,{T+1,j+1}});
                    if(dfs(dep-1,Next)) {return 1;}
                    ans.pop_back();
                    Next.clear();
                    for(int l=0;l<b.size();++l) Next.push_back(b[l]);
                }
            }
        }
    }
    return 0;
}

int main() {
    cin >> T;
    while(T--) {
        cin >> n;
        vector<unsigned short> a(n);
        ans.clear();
        for(auto &i : a) cin >> i;
        int d = 1;
        bool flag = false;
        while(d++ && d <= n + 1) {
            if(dfs(d, a)) {
                cout << "Huoyu\n";
                cout << ans.size() << "\n";
                for(auto i : ans) cout << i.first << " " << i.second.first << " " << i.second.second << "\n";
                flag = true;
                break;
            }
        }
        if(flag) continue;
        cout << "Shuiniao\n";
    }
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
2.00KB
用时
101ms
内存
808.00KB
 GGapa
https://www.luogu.com.cn/record/129852506
所属题目
P9746 「KDOI-06-S」合并序列
评测状态
Accepted
评测分数
100
提交时间
2023-10-16 23:30:02
*/