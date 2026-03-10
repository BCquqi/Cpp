#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int id,score;
};

bool operator < (const Node &x,const Node &y) {
	if (x.score != y.score) return x.score < y.score;
	return x.id > y.id;
}

priority_queue<Node> pq;

void solve() {
	string op;
	cin >> op;
	if (op == "submit") {
		Node x;
		cin >> x.id >> x.score;
		pq.push(x);
	}
	else {
		int x;
		cin >> x;
		if (pq.top().score < x) {cout << "none" << endl; return ;}
		while (pq.size() && pq.top().score >= x) {
			cout << pq.top().id << ' ';
			pq.pop();
		}
		cout << endl;
	}
}

int main() {
	int m;
	cin >> m;
	for (int i = 1;i <= m;i++) solve();
	return 0;
}