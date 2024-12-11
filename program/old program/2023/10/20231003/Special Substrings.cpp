/*
Special Substrings
https://vjudge.csgrandeur.cn/contest/584210#problem/D0
*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define int long long 

string a;
map<char, int> iter;
int it = 0;
long long ans = 0;
map<vector<int>, int> mp;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a;
    a.insert(0, " ");
    for(int i = 1; i <= a.length(); i++) if(iter.count(a[i]) == 0) 
        iter[a[i]] = ++it;
    
    int cnt = it;
    vector<int> tmp(it, 0);
    for (int i = 1; i <= a.length(); i++) {
        if (tmp[iter[a[i]]] == 0)
             cnt--;
        tmp[iter[a[i]]]++;
        if (cnt == 1){
            for (int j = 1; j <= it; j++){
                tmp[j]--;
                if (tmp[j] == 0) cnt++;
            }
        }
        ans += mp[tmp];  
        mp[tmp]++;
    }
    cout << ans << endl;
    return 0;
}