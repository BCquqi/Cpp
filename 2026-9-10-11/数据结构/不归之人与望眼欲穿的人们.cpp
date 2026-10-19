#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int N = 5e4 + 5,M = 305;
struct Node {int x,y;} tmp[M];
struct Block {int l,r;} block[M];
vector<Node> pre[M],suf[M];
int a[N],pos[N],all[M],f[M][M];
int n,m,len,num,cur;

void clean() {
    tmp[cur + 1] = {0,-1};
    int tmpcur = 0;
    for (int i = 1;i <= cur;i++)
        if (tmp[i].y != tmp[i + 1].y) tmp[++tmpcur] = tmp[i];
    cur = tmpcur;
    return ;
}

void modify(int i) {
    memset(f[i],0,sizeof f[i]);
    int tmpcur = 0;
    pre[i].clear(), suf[i].clear(), cur = 0;
    for (int j = block[i].l;j <= block[i].r;j++) {
        if ((tmpcur | a[j]) != tmpcur) tmpcur |= a[j], pre[i].push_back({j,tmpcur});
        for (int k = 1;k <= cur;k++) tmp[k].y |= a[j];
        tmp[++cur] = {j,a[j]}, clean();
        for (int k = 1;k <= cur;k++)
            f[i][j - tmp[k].x + 1] = max(f[i][j - tmp[k].x + 1],tmp[k].y);
    }
    suf[i].assign(tmp + 1,tmp + cur + 1);
    for (int j = 1;j <= block[i].r - block[i].l + 1;j++) f[i][j] = max(f[i][j],f[i][j - 1]);
    all[i] = tmpcur;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    len = (int)sqrt(n), num = (n + len - 1) / len;
    for (int i = 1;i <= n;i++) cin >> a[i], pos[i] = (i - 1) / len + 1;
    for (int i = 1;i <= num;i++) {
        block[i].l = (i - 1) * len + 1, block[i].r = min(i * len,n);
        modify(i);
    }
    while (m--) {
        int op,k;
        cin >> op >> k;
        if (op == 1) {
            int x;
            cin >> x;
            a[k] = x, modify(pos[k]);
        } else {
            int res = 1e9; cur = 0;
            for (int i = 1;i <= num;i++) {
                if (f[i][block[i].r - block[i].l + 1] >= k)
                    res = min(res,(int)(lower_bound(f[i] + 1,f[i] + block[i].r - block[i].l + 1 + 1,k) - f[i]));
                for (int xi = 1,y = 0;xi <= cur;xi++) {
                    while (y < pre[i].size() && (tmp[xi].y | pre[i][y].y) < k) y++;
                    if (y < pre[i].size()) res = min(res,pre[i][y].x - tmp[xi].x + 1);
                }
                for (int j = 1;j <= cur;j++) tmp[j].y |= all[i];
                for (auto [x,y] : suf[i]) tmp[++cur] = {x,y};
                clean();
            }
            cout << (res == 1e9 ? -1 : res) << endl;
        }
    }
    return 0;
}