#include<iostream>
using namespace std;

const int N = 5005;
int L[N],R[N],num[N],head,tail,n,m,cur = 0;

void link(int x,int y) {R[x] = y, L[y] = x;}

void insertL(int x,int y) {link(L[x],y); link(y,x);}
void insertR(int x,int y) {link(y,R[x]); link(x,y);}

int find(int k) {
	int x = head;
	while (k--) x = R[x];
	return x;
}

void newup(int k) {
	int x = find(k);
	n++;
	insertL(x,n);
}

void newdown(int k) {
	newup(k + 1);
}

void topdown(int k) {
	int x = find(k);
	link(L[tail],R[head]);
	link(head,R[x]);
	link(x,tail);
}

void bottomup(int k) {
	topdown(n - k);
}

void middleup(int k1, int k2) {
	int x = find(k1),y = find(k2);
	link(L[x],R[y]);
	link(y,R[head]);
	link(head,x);
}

void middledown(int k1,int k2) {
	int x = find(k1),y = find(k2);
	link(L[x],R[y]);
	link(L[tail],x);
	link(y,tail);
}

void solve() {
	string op;
	int x,y;
	cin >> op;
	if (op == "NEWUP") {
		cin >> x;
		newup(x);
	}
	else if (op == "NEWDOWN") {
		cin >> x;
		newdown(x);
	}
	else if (op == "TOPDOWN") {
		cin >> x;
		topdown(x);
	}
	else if (op == "BOTTOMUP") {
		cin >> x;
		bottomup(x);
	}
	else if (op == "MIDDLEUP") {
		cin >> x >> y;
		middleup(x,y);
	}
	else if (op == "MIDDLEDOWN") {
		cin >> x >> y;
		middledown(x,y);
	}
}

int main() {
	cin >> n >> m;
	head = 0,tail = 5001;
	link(head,1);
	for (int i = 2;i <= n;i++) link(i - 1,i);
	link(n,tail);
	while (m--) solve();
	for (int i = R[head];i != tail;i = R[i]) cout << i << ' ';
	cout << endl;
	return 0;
}