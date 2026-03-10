#include<iostream>
using namespace std;

const int N = 1e6 + 5;
char op[N];
int top1,top2;

struct Node {
	bool d;
	int c1,c2;
} num[N];

Node operator & (Node x,Node y) {
	if (x.d == 0) return Node{0,x.c1 + 1,x.c2};
	return Node{x.d && y.d,x.c1 + y.c1,x.c2 + y.c2};
}

Node operator | (Node x,Node y) {
	if (x.d == 1) return Node{1,x.c1,x.c2 + 1};
	return Node{x.d || y.d,x.c1 + y.c1,x.c2 + y.c2};
}

int id (char c) {
	if (c == '|') return 1;
	if (c == '&') return 2;
	return 0;
}

int main() {
    string s;
	cin >> s;
	s = '(' + s + ')';
	for (int i = 0;i < s.size();i++) {
		if (s[i] == '0' || s[i] == '1') num[++top1] = Node{s[i] - '0',0,0};
		else if (s[i] == '(') op[++top2] = s[i];
		else if (s[i] == ')') {
			while (op[top2] != '(') {
				Node y = num[top1--],x = num[top1--];
				char c = op[top2--];
				if (c == '|') num[++top1] = x | y;
				else num[++top1] = x & y;
			}
			top2--;
		} else {
			while (top2 > 0 && id(op[top2]) >= id(s[i])) {
				Node y = num[top1--],x = num[top1--];
				char c = op[top2--];
				if (c == '|') num[++top1] = x | y;
				else num[++top1] = x & y;
			}
			op[++top2] = s[i];
		}
	}
	cout << num[1].d << endl << num[1].c1 << ' ' << num[1].c2 << endl;
    return 0;
}