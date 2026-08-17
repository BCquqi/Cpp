#include<iostream>
#include<queue>
using namespace std;

const int N = 5e5 + 5;
int a[N],lg[N];
long long s[N],st[N][30]; 

// st 表部分为方便求解答案统一维护下标 

int query(int l,int r) {
	int k = lg[r - l + 1];
	return s[st[l][k]] > s[st[r - (1 << k) + 1][k]] ? st[l][k] : st[r - (1 << k) + 1][k];
}

struct Node {
	int m,l,r;
	bool operator < (const Node &a) const {return s[query(l,r)] - s[m - 1] < s[query(a.l,a.r)] - s[a.m - 1];}
};

priority_queue<Node> q;

int main() {
	int n,k,L,R; // 音符个数 超级和弦个数 音符个数范围 
	long long ans = 0;
	cin >> n >> k >> L >> R;
	lg[1] = 0;
	for (int i = 2;i <= n;i++) lg[i] = lg[i >> 1] + 1;
	for (int i = 1;i <= n;i++) {
		cin >> a[i]; // 美妙度 
		s[i] = s[i - 1] + a[i];
	}
	for (int i = 1;i <= n;i++) st[i][0] = i; // 维护前缀和最大值的下标 
	for (int j = 1;j <= lg[n];j++)
		for (int i = 1;i + (1 << j) - 1 <= n;i++)
			st[i][j] = s[st[i][j - 1]] > s[st[i + (1 << j - 1)][j - 1]] ? st[i][j - 1] : st[i + (1 << j - 1)][j - 1];
	for (int i = 1;i <= n;i++)
		if (i + L - 1 <= n) q.push({i,i + L - 1,min(i + R - 1,n)});
	for (int i = 1;i <= k;i++) {
		int m = q.top().m,l = q.top().l,r = q.top().r;
		int pos = query(l,r);
		ans += s[pos] - s[m - 1];
		q.pop();
		if (l != pos) q.push({m,l,pos - 1});
		if (r != pos) q.push({m,pos + 1,r});
	}
	cout << ans << endl;
	return 0;
}
