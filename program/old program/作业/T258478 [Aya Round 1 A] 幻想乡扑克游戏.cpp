/*
#include <iostream>
#include <string>
using namespace std;

int main(){
	int t,tong[1000]={0};
	cin >> t;
	while (t--){
		string a;
		cin >> a;
		for (int i = 0; i < a.length(); i++){
			tong[a[i]]++;
		}
		bool bj = true;
		for (int i = 0; i < 1000; i++){
			if (tong[i] == 4 || (tong['X'] == 1 && tong['D'] == 1)){
				cout << "Yes" << endl;
				bj = false;
				break;
			}
		}
		if (bj){
			cout << "No" << endl;
		}
		for (int i = 0; i < 1000; i++){
			tong[i] = 0;
		}
	}
}
*/