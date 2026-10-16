#include<iostream>
#include<deque>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
struct Point {int x,y;} a[N];
deque<int> qmax,qmin;

// 问题转化为: 在数列 y 中选出一段使其中最大值 - 最小值 >= d

int main() {
    int n,d,ans = 1e9;
    cin >> n >> d;
    for (int i = 1;i <=  n;i++) cin >> a[i].x >> a[i].y;
    sort(a + 1,a + n + 1,[](Point p,Point q) {return p.x < q.x;});
    for (int i = 1;i <= n;i++) { // 其实是现在处理的点
        while (!qmax.empty() && abs(a[qmax.front()].x - a[i].x) >= ans) qmax.pop_front(); // 必须刷新 front，不然答案无法更新
        while (!qmin.empty() && abs(a[qmin.front()].x - a[i].x) >= ans) qmin.pop_front();
        while (!qmax.empty() && a[qmax.back()].y <= a[i].y) qmax.pop_back();
        qmax.push_back(i);
        while (!qmin.empty() && a[qmin.back()].y >= a[i].y) qmin.pop_back();
        qmin.push_back(i);
        if (a[qmax.front()].y - a[qmin.front()].y >= d)
            ans = min(ans,abs(a[qmax.front()].x - a[qmin.front()].x));
    }
    cout << (ans == 1e9 ? -1 : ans) << endl;
    return 0;
}