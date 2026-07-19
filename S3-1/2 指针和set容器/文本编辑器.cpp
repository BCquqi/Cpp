#include<iostream>
using namespace std;

const int N = 5e5 + 5;

struct Node {
	char val;
	Node *l,*r;
	Node() {l = r = nullptr;}
} ls[N];

Node *head,*tail,*now,*p;

void link(Node *x,Node *y) {
	x -> r = y;
	y -> l = x;
}

void solve() {
	char op;
	cin >> op;
	switch (op) {
		case 'I' : {
			p = new Node;
			cin >> (p -> val);
			link(now -> l,p);
			link(p,now);
			break ;
		}
		case 'D' : {
			if (now == tail) break;
			p = now;
			now = now -> r;
			link(p -> l,p -> r);
			delete p;
			break;
		}
		case 'R' : {
			if (now == tail) break;
			now = now -> r;
			break;
		}
		case 'L' : {
			if (now -> l == head) break;
			now = now -> l;
			break;
		}
	}
	return ;
}

int main() {
	int n;
	cin >> n;
	head = new Node;
	tail = new Node;
	link(head,tail);
	now = new Node;
	now = tail;
	while (n--) solve();
	for (Node *x = head -> r;x != tail;x = x -> r) cout << (x -> val);
	cout << endl;
	return 0;
}