#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1e5 + 5;
int a[N],b[N],c[N],tree[N],pos[N];
int n;
long long pa = 0,ans = 1e18;

/*
第一遍求逆序对找相交线条数量
然后对于每一次位移操作，考虑其对答案的影响 
*/

int lowbit(int x) {return x & -x;}
void add(int id,int val) {while (id <= n) {tree[id] += val,id += lowbit(id);}}
int query(int id) {
	int ret = 0;
	while (id) ret += tree[id],id -= lowbit(id);
	return ret;
}

void solve1() {
	memset(tree,0,sizeof tree);
	for (int i = 1;i <= n;i++) pos[b[i]] = i; // pos 代表 b[i] 在数组中的出现位置 
	for (int i = 1;i <= n;i++) c[i] = pos[a[i]]; // 构造映射 a[i] 在 b 中的位置 
	for (int i = 1;i <= n;i++) {
		add(c[i],1);
		pa += i - query(c[i]); // 总数 i 减去 c[i] 前非逆序对个数 
	}
	ans = min(ans,pa);
	for (int i = 1;i < n;i++) {
		pa += n - c[i], pa -= c[i] - 1;
		ans = min(ans,pa);
		// 若 a[i] 移动到最前面，则 c[i] 移动到最后面 
		// 则少了 n - c[i] 个逆序对，多了 c[i] - 1 个逆序对 
	}
	return ;
}

void solve2() {
	memset(tree,0,sizeof tree);
	pa = 0;
	for (int i = 1;i <= n;i++) pos[a[i]] = i; // pos 代表 b[i] 在数组中的出现位置 
	for (int i = 1;i <= n;i++) c[i] = pos[b[i]]; // 构造映射 a[i] 在 b 中的位置 
	for (int i = 1;i <= n;i++) {
		add(c[i],1);
		pa += i - query(c[i]); // 总数 i 减去 c[i] 前非逆序对个数 
	}
	ans = min(ans,pa);
	for (int i = 1;i < n;i++) {
		pa += n - c[i], pa -= c[i] - 1;
		ans = min(ans,pa);
		// 若 a[i] 移动到最前面，则 c[i] 移动到最后面 
		// 则少了 n - c[i] 个逆序对，多了 c[i] - 1 个逆序对 
	}
	return ;
}

int main() {
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	for (int i = 1;i <= n;i++) cin >> b[i];
	solve1();
	solve2();
	cout << ans << endl;
	return 0;
} 
