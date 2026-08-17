#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1e6 + 5;
struct Block {int l,r,lazy;} block[N];
int a[N],n,q,len,num,pos[N],cpy[N];

void init() {
    len = (int) sqrt(n), num = (n + len - 1) / len;
    for (int i = 1;i <= n;i++) pos[i] = (i - 1) / len + 1;
    for (int i = 1;i <= num;i++) {
        block[i].l = (i - 1) * len + 1, block[i].r = min(i * len,n);
        sort(cpy + block[i].l,cpy + block[i].r + 1);
    }
    return ;
}

void modify(int area,int l,int r,int w) {
    for (int i = l;i <= r;i++) a[i] += w;
    for (int i = block[area].l;i <= block[area].r;i++) cpy[i] = a[i];
    sort(cpy + block[area].l,cpy + block[area].r + 1);
}

void add(int l,int r,int w) {
    if (pos[l] == pos[r]) {
        modify(pos[l],l,r,w);
        return ;
    }
    modify(pos[l],l,block[pos[l]].r,w);
    modify(pos[r],block[pos[r]].l,r,w);
    for (int i = pos[l] + 1;i < pos[r];i++) block[i].lazy += w;
}

int calc(int area,int l,int r,int c) {
    int ret = 0;
    for (int i = l;i <= r;i++) ret += (a[i] + block[area].lazy >= c);
    return ret;
}

int query(int l,int r,int c) {
    if (pos[l] == pos[r]) return calc(pos[l],l,r,c);
    int ret = 0;
    for (int i = pos[l] + 1;i < pos[r];i++)
        ret += block[i].r - (lower_bound(cpy + block[i].l,cpy + block[i].r + 1,c - block[i].lazy) - cpy) + 1;
    return calc(pos[l],l,block[pos[l]].r,c) + ret + calc(pos[r],block[pos[r]].l,r,c);
}

int main() {
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cpy[i] = a[i];
    }
    init();
    while (q--) {
        char op;
        cin >> op;
        if (op == 'M') {
            int l,r,w;
            cin >> l >> r >> w;
            add(l,r,w);
        } else {
            int l,r,c;
            cin >> l >> r >> c;
            cout << query(l,r,c) << endl;
        }
    }
    return 0;
}