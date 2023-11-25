// 2023-11-10

// 有很多根轨道共同组成了一个进路。这些轨道各自都有名称和不同的长度
// 现在有一列火车，我们知道每个车厢的长度，也知道机车头所在的轨道和偏移量
// 需要得到每一节车厢位于那一个轨道的什么偏移量上。

// 例如一根铁路由3段轨道A,B,C组成，分别长 20，3，15米
// 有一列机车有3个车厢，编号是1，2，3号，分别长 11，12，13米
// 我们已经知道1号车厢位于A轨道3米处。

// 我们计算得出：
// 1 A 3 意思是1号车厢位于A轨道的3米处
// 2 A 14 2号车厢位于A轨道14米处
// 3 C 3 3号车厢位于C轨道的3米处

#include <iostream>
using namespace std;
const int maxn = 1000;

int n, Count, StartPoint; // 轨道数量，车厢数量，开始
int itt, itc, sumt, AerialFront;
int lent, lenc;
bool HookDirection; // 左侧(1) 右侧(0)

struct Track
{ // 轨道
    string TrackID;
    int LengthCM;
} RailList[maxn];

struct Carriage
{ // 车厢
    string name;
    int FrameLength;
} FrameList[maxn];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> Count >> StartPoint >> AerialFront >> HookDirection;
    for (int i = 0; i < n; i++)
        cin >> RailList[i].TrackID >> RailList[i].LengthCM, lent += RailList[i].LengthCM;
    for (int i = 0; i < Count; i++)
        cin >> FrameList[i].name >> FrameList[i].FrameLength, lenc += FrameList[i].FrameLength;
    if (HookDirection)
    {
        sumt = 0, AerialFront = RailList[itt].LengthCM - StartPoint + AerialFront;
        itt = itc = 0;
        AerialFront += FrameList[itc].FrameLength;
        sumt = RailList[itt].LengthCM;
        // itt = 1; 
        while (itt < n && itc < Count)
        {
            if(AerialFront > lent) break;
            while (AerialFront >= sumt && itt + 1 < n) // 判断铁轨所处的位置是否合法
                sumt += RailList[++itt].LengthCM;
            cout << FrameList[itc].name << " " << RailList[itt].TrackID << " " << abs(AerialFront - sumt) << endl; // 输出
            if(itc + 1 < Count)AerialFront += FrameList[++itc].FrameLength;                                                           // 判断下一个车厢
            else break;
        }
        while (++itc < Count)
            cout << -1 << endl;
    }
    else
    {
        sumt = 0, AerialFront += StartPoint;
        itt = itc = 0;
        // itt = 1; 
        while (itt < n && itc < Count)
        {
            if (AerialFront > lent)
                break;
            while (AerialFront - sumt >= RailList[itt].LengthCM && itt + 1 < n) // 判断铁轨所处的位置是否合法
                sumt += RailList[itt++].LengthCM;
            cout << FrameList[itc].name << " " << RailList[itt].TrackID << " " << AerialFront - sumt << endl; // 输出
            if(itc + 1 < Count)AerialFront += FrameList[itc++].FrameLength;                                                           // 判断下一个车厢
            else break;
        }
        while (++itc < Count)
            cout << -1 << endl;
    }
    return 0;
}