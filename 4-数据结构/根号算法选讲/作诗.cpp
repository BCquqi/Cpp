#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int N = 1e5 + 5;
struct Block {int l,r,lazy;} block[N];
int a[N],n,c,m,pos[N],num[325][N],ans[325][325],snum[325][N],box[N];
// num 表示区间 i 中 j 的出现次数，ans 表示区间 i 到区间 j 之间的区间答案

void init() {
    int len = (int) sqrt(n), bnum = (n + len - 1) / len;
    for (int i = 1;i <= n;i++) pos[i] = (i - 1) / len + 1;
    for (int i = 1;i <= bnum;i++) {
        block[i].l = (i - 1) * len + 1, block[i].r = min(i * len,n);
        for (int j = block[i].l;j <= block[i].r;j++) num[i][a[j]]++;
        for (int j = 0;j <= c;j++) num[i][j] += num[i - 1][j];
    }
    for (int i = 1;i <= bnum;i++) {
        for (int j = i;j <= bnum;j++) {
            ans[i][j] = ans[i][j - 1];
            for (int k = block[j].l;k <= block[j].r;k++) {
                box[a[k]]++;
                if (!(box[a[k]] % 2)) ans[i][j]++;
                else if (box[a[k]] != 1) ans[i][j]--;
            }
        }
        for (int j = 0;j <= c;j++) box[j] = 0;
    }
    return ;
}

int solve(int l,int r) {
    int ret = 0;
    if (pos[l] == pos[r]) {
        int area = pos[l];
        for (int i = l;i <= r;i++) {
            box[a[i]]++;
            if (!(box[a[i]] % 2)) ret++;
            else if (box[a[i]] != 1) ret--;
        }
        for (int i = l;i <= r;i++) box[a[i]] = 0;
        return ret;
    }
    ret = ans[pos[l] + 1][pos[r] - 1];
    for (int i = l;i <= block[pos[l]].r;i++) {
        box[a[i]]++;
        if ((box[a[i]] + num[pos[r] - 1][a[i]] - num[pos[l]][a[i]]) % 2 == 0) ret++;
        else if (box[a[i]] + num[pos[r] - 1][a[i]] - num[pos[l]][a[i]] != 1) ret--;
    }
    for (int i = block[pos[r]].l;i <= r;i++) {
        box[a[i]]++;
        if ((box[a[i]] + num[pos[r] - 1][a[i]] - num[pos[l]][a[i]]) % 2 == 0) ret++;
        else if (box[a[i]] + num[pos[r] - 1][a[i]] - num[pos[l]][a[i]] != 1) ret--;
    }
    for (int i = l;i <= block[pos[l]].r;i++) box[a[i]] = 0;
    for (int i = block[pos[r]].l;i <= r;i++) box[a[i]] = 0;
    return ret;
}

inline int read() {
	int x = 0,f = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9'){x = x * 10 + ch - 48; ch = getchar();}
	return x * f;
}

int main() {
    n = read(); c = read(); m = read();
    for (int i = 1;i <= n;i++) a[i] = read();
    init();
    int lastans = 0;
    while (m--) {
        int l = read(),r = read();
        l = (l + lastans) % n + 1, r = (r + lastans) % n + 1;
        if (l > r) swap(l,r);
        lastans = solve(l,r);
        printf("%d\n",lastans);
    }
    return 0;
}