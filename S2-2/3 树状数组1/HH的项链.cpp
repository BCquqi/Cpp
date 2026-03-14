#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e6 + 5;
struct Node {int l,r,id;} s[N];
long long a[N],pos[N],ans[N],c[N],n,m;

bool cmp(Node x,Node y) {return x.r < y.r;}
int lowbit(int x) {return x & -x;}
void change(int x,int t) {while (x <= n) c[x] += t,x += lowbit(x);}
long long sum(int x) {
	long long ans = 0;
	while (x > 0) ans += c[x],x -= lowbit(x);
	return ans;
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	cin >> m;
	for (int i = 1;i <= m;i++) {
		cin >> s[i].l >> s[i].r;
		s[i].id = i;
	}
	sort(s + 1,s + m + 1,cmp);
	for (int i = 1,j = 1;i <= m;i++) {
		while (j <= s[i].r) {
			if (pos[a[j]]) change(pos[a[j]],-1);
			change(j,1);
			pos[a[j]] = j;
			j++;
		}
		ans[s[i].id] = sum(s[i].r) - sum(s[i].l - 1);
	}
	for (int i = 1;i <= m;i++) cout << ans[i] << endl;
	return 0;
}