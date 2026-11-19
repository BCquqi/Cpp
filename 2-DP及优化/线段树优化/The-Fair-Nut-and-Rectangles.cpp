#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
struct Node {int x,y; long long a;} s[N];
int q[N];
long long dp[N];

inline long long val(int j,int i) {return dp[j] + 1ll * s[i].x * s[i].y - 1ll * s[j].x * s[i].y - s[i].a;}
inline bool check(int a,int b,int c)
{return (__int128)(dp[b] - dp[a]) * (s[c].x - s[b].x) <= (__int128)(dp[c] - dp[b]) * (s[b].x - s[a].x);}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> s[i].x >> s[i].y >> s[i].a;
    sort(s + 1,s + n + 1,[](Node p,Node q) {return p.x != q.x ? p.x < q.x : p.y > q.y;});
    int l = 0,r = 0;
    for (int i = 1;i <= n;i++) {
        while (l < r && val(q[l],i) <= val(q[l + 1],i)) l++;
        int j = q[l];
        dp[i] = max(1ll * s[i].x * s[i].y - s[i].a,val(j,i));
        while (l < r && check(q[r - 1],q[r],i)) r--;
        q[++r] = i;
    }
    long long ans = 0;
    for (int i = 1;i <= n;i++) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}