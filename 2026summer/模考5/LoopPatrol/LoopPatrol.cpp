#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 5005;
struct Pos {int x,y;} a[N];

int main() {
    freopen("LoopPatrol.in","r",stdin);
    freopen("LoopPatrol.out","w",stdout);
    string s;
    long long t;
    cin >> s >> t;
    int len = s.size();
    s = '?' + s;
    a[0] = {0,0};
    for (int i = 1;i <= len;i++) {
        if (s[i] == 'E') a[i] = {a[i - 1].x + 1,a[i - 1].y};
        else if (s[i] == 'W') a[i] = {a[i - 1].x - 1,a[i - 1].y};
        else if (s[i] == 'N') a[i] = {a[i - 1].x,a[i - 1].y + 1};
        else a[i] = {a[i - 1].x,a[i - 1].y - 1};
    }
    long long ansx = 1ll * t / len * a[len].x + a[t % len].x,ansy = 1ll * t / len * a[len].y + a[t % len].y;
    cout << ansx << ' ' << ansy << endl;
    return 0;
}