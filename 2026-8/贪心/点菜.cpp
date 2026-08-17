#include<iostream>
#include<algorithm>
#include<cstdio>
#include<queue>
#define int long long
using namespace std;

const int N = 5e4 + 5,M = 2e5 + 5;
struct Node {
	int x,y;
	bool operator < (const Node x) const {return y < x.y;} // 价格升序 
} s[M],cpy[M];
int a[N],b[N],n,m,p,Q;
priority_queue<Node> q; // 存储菜 

bool check(int mid) {
	while (!q.empty()) q.pop(); 
	if ((n - p - Q) * mid >= m) return true; // 没有限制的人就可以达到目标 
	int cur1 = 1;
	// 挑剔 
	for (int i = 1;i <= p;i++) {
		while (cur1 <= m && s[cur1].x >= a[i]) q.push(s[cur1++]); // 符合条件就可以进
		for (int j = 1;j <= mid && !q.empty();j++) q.pop(); 
	}
	int cur2 = 0;
	while (!q.empty()) {cpy[++cur2] = q.top(); q.pop();}
	for (int i = cur1;i <= m;i++) cpy[++cur2] = s[i];
	// 上两行可以让 cpy 数组内有除了被贪心吃掉的菜外所有菜 
	sort(cpy + 1,cpy + cur2 + 1); // 价格升序排列 为后续做准备
	cur1 = 1;
	// 贫穷 
	for (int i = 1;i <= Q;i++) {
		while (cur1 <= cur2 && cpy[cur1].y <= b[i]) q.push(cpy[cur1++]); // 不能自增 会有问题 
		for (int j = 1;j <= mid && !q.empty();j++) q.pop();
	}
	// q 是穷人没吃的 cur2 是富人没吃的 cur1 是穷人富人总共吃的 容斥原理  
	return ((int)q.size() + cur2 - cur1 + 1 <= (n - p - Q) * mid);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> p >> Q;
	for (int i = 1;i <= m;i++) cin >> s[i].x >> s[i].y; // 美味度 价格 
	for (int i = 1;i <= p;i++) cin >> a[i]; // 美味度下限 
	for (int i = 1;i <= Q;i++) cin >> b[i]; // 价格上限 
	sort(a + 1,a + p + 1,greater<int>());
	sort(b + 1,b + Q + 1);
	sort(s + 1,s + m + 1,[](Node x,Node y) {return x.x > y.x;}); // 按照美味度从大到小排序 
	int l = 1,r = m,ans = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (check(mid)) ans = mid,r = mid - 1;
		else l = mid + 1;
	} 
	cout << ans << '\n';
	return 0;
} 
