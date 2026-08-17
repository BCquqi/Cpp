#include<iostream>
#include<queue>
#define int long long
using namespace std;

const int N = 1e5 + 5;
struct List {int pre,nxt,val;} a[N];
struct Node {
	int id,val;
	bool operator < (Node x) const {return val > x.val;}
}; 
int s[N];
bool vis[N];
priority_queue<Node> q;

void del(int x) { // É¾³ý±àºÅÎª x µÄÊý 
    a[a[x].pre].nxt = a[x].nxt,
    a[a[x].nxt].pre = a[x].pre;
}

signed main() {
	int n,k,ans = 0;
	cin >> n >> k >> s[0];
	for (int i = 1;i < n;i++) {
		cin >> s[i];
		a[i].val = s[i] - s[i - 1];
		a[i - 1].nxt = i, a[i].pre = i - 1;
		q.push({i,a[i].val});
	}
	a[0].val = a[n].val = 1e9;
	for (int i = 1;i <= k;i++) {
		while (vis[q.top().id]) q.pop();
		ans += q.top().val;
		vis[a[q.top().id].pre] = vis[a[q.top().id].nxt] = true;
		a[q.top().id].val = a[a[q.top().id].pre].val + a[a[q.top().id].nxt].val - a[q.top().id].val;
		del(a[q.top().id].pre);
		del(a[q.top().id].nxt);
		int cpy1 = q.top().id,cpy2 = a[q.top().id].val;
		q.pop();
		q.push({cpy1,cpy2}); 
	}
	cout << ans << endl;
	return 0;
}
