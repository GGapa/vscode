#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
struct students
{
    string name;
    int finallytest,normallytest,writer,studentnum;
    char weststudent,mainstudent;
    int money=0;
}student[101];
bool cmp(students x,students y)
{
    if(x.money==y.money)return x.studentnum<y.studentnum;
    else return x.money>y.money;
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
    {
        cin>>student[i].name>>student[i].finallytest>>student[i].normallytest>>student[i].mainstudent>>student[i].weststudent>>student[i].writer;
        student[i].studentnum=i;
        if(student[i].finallytest>80&&student[i].writer>=1)student[i].money+=8000;
        if(student[i].finallytest>85&&student[i].normallytest>80)student[i].money+=4000;
        if(student[i].finallytest>90)student[i].money+=2000;
        if(student[i].finallytest>85&&student[i].weststudent=='Y')student[i].money+=1000;
        if(student[i].normallytest>80&&student[i].mainstudent=='Y')student[i].money+=850;
        sum+=student[i].money;
    }
    sort(student+1,student+1+n,cmp);
    cout<<student[1].name<<endl<<student[1].money<<endl<<sum<<endl;
    return 0;
}