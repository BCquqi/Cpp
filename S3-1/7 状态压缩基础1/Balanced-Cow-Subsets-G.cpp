#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N = 25,M = (1 << 20) + 5;
int a[N],cntl = 0,cntr = 0,lim,n;
int mp[M];
struct Node {
    int sum,mask;
    bool operator < (const Node &x) const {return sum < x.sum;}
} L[M],R[M];

void dfs(int step,int sum,int mask) {
    if (step > lim) {
        if (lim == n / 2) L[++cntl] = {sum,mask};
        else R[++cntr] = {sum,mask};
        return ;
    }
    dfs(step + 1,sum,mask);
    dfs(step + 1,sum + a[step],mask | (1 << (step - 1)));
    dfs(step + 1,sum - a[step],mask | (1 << (step - 1)));
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    lim = n / 2;
    dfs(1,0,0);
    lim = n;
    dfs(n / 2 + 1,0,0);
    sort(L + 1,L + cntl + 1);
    sort(R + 1,R + cntr + 1);
    for (int i = 1;i <= cntl;i++) {
        int pos1 = lower_bound(R + 1,R + cntr + 1,L[i]) - R;
        int pos2 = upper_bound(R + 1,R + cntr + 1,L[i]) - R - 1;
        for (int j = pos1;j <= pos2;j++)
            mp[(R[j].mask | L[i].mask)] = true;
    }
    int ans = 0;
    for (int i = 1;i < (1 << n);i++) ans += mp[i];
    cout << ans << endl;
    return 0;
}