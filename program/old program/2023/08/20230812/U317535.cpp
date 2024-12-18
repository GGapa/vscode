//U317535 queue
//https://www.luogu.com.cn/problem/U317535?contestId=123900
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
int n;
queue <string> que;
queue <string> playing;
map <string, string> mp;
map <string, int> number;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(n--) {
        string op;
        cin >> op;
        if(op == "start") {
            while(!playing.empty()) {
                que.push(playing.front());
                mp[playing.front()] = "-Watting";
                playing.pop();
            }
            if(que.empty()){
                cout << "Error" << endl;
                continue;
            }
            for(int i = 1, success = 0; success < 2 && !que.empty(); i++) {
                if(number[que.front()] > 1 || mp[que.front()] == "") {
                    number[que.front()]--;
                    que.pop();
                    continue;    
                }
                mp[que.front()] = "-Playing";
                success++;
                playing.push(que.front());
                cout << que.front() << " ";
                que.pop();
            }
            cout << endl;
        }
        else if(op == "arrive") {
            string ar;
            cin >> ar;
            if(mp[ar] == "-Watting" || mp[ar] == "-Playing") {
                cout << "Error" << endl;
                continue;
            }
            mp[ar] = "-Watting";
            number[ar]++;
            que.push(ar);
            cout << "OK" << endl;
        }
        else if(op == "leave") {
            string le;
            cin >> le;
            if(mp[le] == "-Playing" || mp[le] == "") {
                cout << "Error" << endl;
                continue;
            }
            mp[le] = "";
            cout << "OK" << endl;
        }
    }
    return 0;

}