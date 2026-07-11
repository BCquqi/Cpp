#include<iostream>
#include<algorithm>
#include<cstdio>
#define int long long
using namespace std;

const int N = 1e5 + 5,MOD = 1e8 - 3;
int a[N],b[N],cura[N],curb[N],cpy[N],tree[N],n,ans = 0,mp[N]; // cur是适用本题的离散化方式

int lowbit(int x) {return x & -x;}
void add(int id,int val) {while (id <= n) {tree[id] += val,id += lowbit(id);}}
int query(int id) {
    int ret = 0;
    while (id) ret += tree[id],id -= lowbit(id);
    return ret;
}

// 思路: 离散化 a 作为下标，a 和 b 互相对应映射为 mp，求 mp 的逆序对数量 

signed main() {
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        cura[i] = i;
    }
    for (int i = 1;i <= n;i++) {
        cin >> b[i];
        curb[i] = i;
    }
    sort(cura + 1,cura + n + 1,[](int x,int y) {return (a[x] < a[y]);});
    sort(curb + 1,curb + n + 1,[](int x,int y) {return b[x] < b[y];});
    for (int i = 1;i <= n;i++) mp[cura[i]] = curb[i],cpy[cura[i]] = curb[i];
    for (int i = 1;i <= n;i++) {
        add(mp[i],1);
        ans += (i - query(mp[i])) % MOD,ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}