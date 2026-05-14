#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int N = 1e6 + 5;
struct Node {
	int t,s;
} a[N];
priority_queue<int,vector<int>,greater<int> > pq;

bool cmp(Node x,Node y) {return x.t < y.t;}

int main() {
	int n,ans = 0;
	scanf("%d",&n);
	for (int i = 1;i <= n;i++) scanf("%d%d",&a[i].t,&a[i].s);
	sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++) {
		if (pq.size() < a[i].t) {
			pq.push(a[i].s);
			ans += a[i].s;
		}
		else if (a[i].s > pq.top()) {
			ans -= pq.top();
			pq.pop();
			pq.push(a[i].s);
			ans += a[i].s;
		}
	}
	printf("%d\n",ans);
	return 0;
}