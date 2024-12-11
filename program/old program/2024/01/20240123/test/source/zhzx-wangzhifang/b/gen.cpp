#include <bits/stdc++.h>
using namespace std;
int main(){
	int na=400,nb=800;
	printf("%d %d\n",na,nb);
	for(int i=2; i<na; ++i)
		printf("%d ",i-1);
	printf("%d\n",na-1);
	for(int i=2; i<nb; ++i)
		printf("%d ",i-1);
	printf("%d\n",nb-1);
	int q=100;
	printf("%d\n1 1\n",q);
	for(int i=2; i<=q; ++i)
		printf("1 %d\n",i);
	return 0;
}
