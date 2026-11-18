#include<algorithm>
#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

const int N = 200005;
int x[N],y[N];
long long sum[N];

int main() {
    freopen("move.in","r",stdin);
    freopen("move.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,X,Y;
    cin >> n >> X >> Y;
    long long cl,cr,cd,cu;
    cin >> cl >> cr >> cd >> cu;
    string s;
    cin >> s;
    for (int i = 1;i <= n;i++) {
        x[i] = x[i - 1], y[i] = y[i - 1], sum[i] = sum[i - 1];
        if (s[i - 1] == 'L') x[i]--, sum[i] += cl;
        if (s[i - 1] == 'R') x[i]++, sum[i] += cr;
        if (s[i - 1] == 'D') y[i]--, sum[i] += cd;
        if (s[i - 1] == 'U') y[i]++, sum[i] += cu;
    }
    int dx = x[n] - X, dy = y[n] - Y;
    long long ans = (dx == 0 && dy == 0 ? 0 : 1e18);
    map<pair<int,int>,int> mp;
    mp[{0,0}] = 0;
    for (int i = 1;i <= n;i++) {
        pair<int,int> tmp = {x[i] - dx,y[i] - dy};
        if (mp.count(tmp))
            ans = min(ans,sum[i] - sum[mp[tmp]]);
        mp[{x[i],y[i]}] = i;
    }
    if (ans == 1e18) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}