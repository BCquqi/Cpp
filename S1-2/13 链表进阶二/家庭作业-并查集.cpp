#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
struct Node {
	int t,s;
} a[N];
int f[N];

bool cmp(Node x,Node y) {return x.s > y.s;}

int find(int x) {
	if (f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main() {
    int n,m = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].t >> a[i].s;
        m = max(m,a[i].t);
    }
    sort(a + 1,a + n + 1,cmp);
    int ans = 0;
    for (int i = 1;i <= m;i++) f[i] = i;
    for (int i = 1;i <= n;i++) {
        int pos = find(a[i].t);
        if (pos == 0) continue;
        ans += a[i].s;
        f[pos] = pos - 1;
    }
    cout << ans << endl;
    return 0;
}