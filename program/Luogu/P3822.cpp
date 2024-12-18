#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int N = 1e6 + 10; 
typedef unsigned int uit;
uit inc[N] ,dc[N];
set <int> s;
int n, t1, t2, t3;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t1 >> t2 >> t3;
    for(int i = 1, t, a, b; i <= n; i++) {
        cin >> t;
        if(t == 1) {
            cin >> a >> b;
            int p = b / 32, q = b % 32; //这个数处于哪一个块中
            if(a > 0) {
                uit st = (uit)a << q, ic = (uit)a >> (31 - q); 
                ic >>= 1;
				uit od = inc[p]; 
                inc[p] += st; 
                ic += (od > inc[p]);   //如果进位了
                if(inc[p] ^ dc[p]) s.insert(p); 
                else if(s.count(p)) s.erase(p); 
                p++;
                while(ic != 0){
					od = inc[p]; 
                    inc[p] += ic; 
                    ic = (od > inc[p]);
					if(inc[p] ^ dc[p]) s.insert(p); 
                    else if(s.count(p)) s.erase(p); 
                    p++;
				}
            }
            else if(a < 0) {
                a = -a;
                uit st = (uit)a << q, ic = (uit)a >> (31 - q);
                ic >>= 1;
				uit od = dc[p]; 
                dc[p] += st; 
                ic += (od > dc[p]);
                if(inc[p] ^ dc[p]) s.insert(p);
                else if(s.count(p)) s.erase(p); 
                p++;
                while(ic != 0) {
                    od = dc[p];
                    dc[p] += ic; 
                    ic = (od > dc[p]);
                    if(inc[p] ^ dc[p]) s.insert(p); 
                    else if(s.count(p)) s.erase(p); 
                    p++;
                }
            }
        }

        else {
            cin >> b;
            int p = b / 32, q = b % 32;
            int ans = ((inc[p] >> q) ^ (dc[p] >> q)) & 1;
            unsigned int v1 = inc[p] % (1 << q); unsigned int v2 = dc[p] % (1 << q);
            if(v1 < v2) {
                cout << (ans ^ 1) << '\n';
                continue;
            }
            else if(v1 > v2 || s.empty() || p <= *s.begin()) {
                cout << ans << '\n';
                continue;
            }
            else {
                auto it = s.lower_bound(p); --it; 
                if(inc[*it] > dc[*it]) cout << ans << '\n';
                else cout << (ans ^ 1) << '\n';
            }
        }
    }
    return 0;
}