#include<iostream>
#include<algorithm>
#define int long long
using namespace std;

const int N = 3e5 + 5;
struct Node {int h,pos;} s[N];
int tree[N],n;

int lowbit(int x) {return x & -x;}
void add(int id,int val) {while (id <= n) {tree[id] += val,id += lowbit(id);}}
int query(int id) {
	int ret = 0;
	while (id) ret += tree[id],id -= lowbit(id);
	return ret;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("city.in","r",stdin);
    freopen("city.out","w",stdout);
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> s[i].h;
        s[i].pos = i;
        add(i,1);
    }
    sort(s + 1,s + n + 1,[](Node x,Node y) {return (x.h != y.h ? x.h < y.h : x.pos < y.pos);});
    long long ans = 0;
    for (int i = 1;i <= n;i++) {
        int j;
        for (j = i;j <= n && s[j].h == s[i].h;j++)
            add(s[j].pos,-1);
        for (int k = i;k < j;k++)
            ans += min(query(s[k].pos - 1),query(n) - query(s[k].pos));
        i = j - 1;
    }
    cout << ans << endl;
    return 0;
}