#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Node {
	int x,id;
};

priority_queue<Node> pq1;
priority_queue<Node,vector<Node>,greater<Node> > pq2;
bool vis[200005]; int cur;

bool operator < (const Node &x,const Node &y) {return x.x < y.x;}
bool operator > (const Node &x,const Node &y) {return x.x > y.x;}

void solve() {
	char op;
	cin >> op;
	if (op == '+') {
		int x; cin >> x;
		vis[++cur] = true,pq1.push({x,cur}), pq2.push({x,cur});
	}
	else if (op == '-') {
		int n; cin >> n;
		vis[n] = false;
	}
	else {
		int x; cin >> x;
		while (!vis[pq1.top().id]) pq1.pop();
		while (!vis[pq2.top().id]) pq2.pop();
		int ans = max(abs(x - pq1.top().x),abs(x - pq2.top().x));
		cout << ans << endl;
	}
}

int main() {
	int q;
	cin >> q;
	while (q--) solve();
	return 0;
}