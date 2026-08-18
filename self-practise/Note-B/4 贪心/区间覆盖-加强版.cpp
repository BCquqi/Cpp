#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
struct Node {long long s,t;} a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {cin >> a[i].s >> a[i].t;}
    sort(a + 1,a + n + 1,[](Node x,Node y) {return (x.s != y.s ? x.s < y.s : x.t < y.t);});
    long long ans = a[1].t - a[1].s + 1,cur = a[1].t;
    for (int i = 2;i <= n;i++) {
        if (a[i].s > cur) ans += a[i].t - a[i].s + 1,cur = a[i].t;
        else if (a[i].t > cur) ans += a[i].t - max(a[i].s,cur),cur = a[i].t;
    }
    cout << ans << endl;
    return 0;
}