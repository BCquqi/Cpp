#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 2e5 + 5;
struct Block {int l,r;} block[N];
int a[N],n,pos[N],step[N],to[N];
// steps 记录从当前点跳出本区块需要几步
// to 记录第一次跳出所在区块后所在位置

void init() {
    int len = (int) sqrt(n), block_num = (n + len - 1) / len;
    for (int i = 1;i <= n;i++) pos[i] = (i - 1) / len + 1;
    for (int i = 1;i <= block_num;i++)
        block[i].l = (i - 1) * len + 1, block[i].r = min(i * len,n);
    for (int i = n;i >= 1;i--)
        if (i + a[i] >= block[pos[i] + 1].l)
            step[i] = 1, to[i] = i + a[i];
        else 
            step[i] = step[i + a[i]] + 1, to[i] = to[i + a[i]];
    return ;
}

int query(int x) {
    int ret = 0;
    while (x <= n) ret += step[x], x = to[x];
    return ret;
}

void modify(int x,int y) {
    a[x] = y;
    for (int i = block[pos[x]].r;i >= block[pos[x]].l;i--)
        if (i + a[i] >= block[pos[i] + 1].l)
            step[i] = 1, to[i] = i + a[i];
        else 
            step[i] = step[i + a[i]] + 1,to[i] = to[i + a[i]];
    return ;
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    init();
    int m;
    cin >> m;
    while (m--) {
        int i,j;
        cin >> i >> j;
        // 节点从 0 开始编号
        if (i == 1) cout << query(j + 1) << endl;
        else {
            int k;
            cin >> k;
            modify(j + 1,k);
        }
    }
    return 0;
}