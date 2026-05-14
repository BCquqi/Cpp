#include<iostream>
#include<queue>
using namespace std;

const int N = 2e5 + 5;
struct Node {
	int num,cnt,id;
} e[N];
bool operator < (const Node &x,const Node &y) {
	if (x.cnt != y.cnt) return x.cnt < y.cnt;
	return x.id > y.id;
}
priority_queue<Node> q;
int a[N],L[N],R[N],num[N],head,tail,cur = 0;
bool vis[N];

void link(int x,int y) {R[x] = y, L[y] = x;}
void Delete(int x) {link(L[x],R[x]);}

int main() {
	int n,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i];
	int sz = 0,cnt = 1;
	for (int i = 2;i <= n + 1;i++) {
		if (a[i] == a[i - 1]) cnt++;
		else sz++, e[sz].num = a[i - 1], e[sz].cnt = cnt, e[sz].id = sz, cnt = 1;
	}
	head = 0,tail = sz + 1;
	for (int i = 1;i <= sz;i++) {
		link(i - 1,i);
		q.push(e[i]);
	}
	link(sz,tail);
	while (R[head] != tail)
	{
		int x = q.top().id;
		q.pop();
		while (vis[x]) {x = q.top().id; q.pop();}
		Delete(x);
		vis[x] = true;
		if (L[x] != head && e[L[x]].num == e[R[x]].num) {
			e[L[x]].cnt += e[R[x]].cnt;
			Delete(R[x]);
			vis[R[x]] = true;
			q.push(e[L[x]]);
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}