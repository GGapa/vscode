//https://www.luogu.com.cn/problem/T364889?contestId=121028
//T364889 小粉兔处理题解审核志愿者轮换
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

map<string, string> name;

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    for(int i = 1; i <= n; i++) {
        string Input;
        cin >> Input;
        name[Input] = Input;
    }
    for(int i = 1; i <= m; i++) {
        string Input;
        cin >> Input;
        name.erase(Input);
    }
    for(int i = 1; i <= l; i++) {
        string Input;   
        cin >> Input;
        name[Input] = Input;
    }
    vector <string> ls;
    for(auto i = name.begin(); i != name.end(); i++) {
        ls.push_back(i->second);
    }
    sort(ls.begin(), ls.end());
    for(int i = 0; i < ls.size(); i++){
        cout << ls[i] << endl;
    }
    return 0;
}