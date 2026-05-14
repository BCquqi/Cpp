#include<iostream>
using namespace std;

const int N = 1e5 + 5;
int L[N],R[N],num[N],head,tail,cur = 0;

void link(int x,int y) {R[x] = y, L[y] = x;}

void insertL(int x,int y) {link(L[x],y); link(y,x);}
void insertR(int x,int y) {link(y,R[x]); link(x,y);}
void Delete(int x) {link(L[x],R[x]);}

void solve() {
	string op;
	int k,x;
	cin >> op;
	if (op == "L") {
		cin >> x;
		num[++cur] = x;
		insertR(head,cur);
	}
	else if (op == "R") {
		cin >> x;
		num[++cur] = x;
        insertL(tail,cur);
	}
	else if (op == "D") {
		cin >> k;
		Delete(k);
	}
	else if (op == "IL") {
		cin >> k >> x;
		num[++cur] = x;
        insertL(k,cur);
	}
    else {
        cin >> k >> x;
        num[++cur] = x;
        insertR(k,cur);
    }
}

int main() {
	int m;
	cin >> m;
    head = 0,tail = m + 1;
    link(head,tail);
	while (m--) solve();
    for (int i = R[head];i != tail;i = R[i]) cout << num[i] << ' ';
    cout << endl;
	return 0;
}