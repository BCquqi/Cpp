#include<iostream>
using namespace std;

const int N = 1e5 + 5,mod = 1e4 + 7;

struct Node {
    int c0,c1;
} num[N];

char op[N];
int top1,top2;

int main() {
    int l;
    string s;
    cin >> l >> s;
	s = '(' + s + ')';
    for (int i = 0;i < l + 2;i++) {
        if (s[i] != '(' && s[i - 1] != ')') num[++top1] = {1,1};
        if (s[i] == '(') op[++top2] = s[i];
        else if (s[i] == ')') {
            while (op[top2] != '(') {
                Node y = num[top1--],x = num[top1--];
                char c = op[top2--];
                if (c == '+') num[++top1] = {x.c0 * y.c0 % mod,(x.c1 * y.c1 + x.c1 * y.c0 + x.c0 * y.c1) % mod};
                else num[++top1] = {(x.c0 * y.c0 + x.c1 * y.c0 + x.c0 * y.c1) % mod,x.c1 * y.c1 % mod};
            }
            top2--;
        } else {
			while (top2 > 0 && op[top2] == '*') {
				Node y = num[top1--],x = num[top1--];
                char c = op[top2--];
                if (c == '+') num[++top1] = {x.c0 * y.c0 % mod,(x.c1 * y.c1 + x.c1 * y.c0 + x.c0 * y.c1) % mod};
                else num[++top1] = {(x.c0 * y.c0 + x.c1 * y.c0 + x.c0 * y.c1) % mod,x.c1 * y.c1 % mod};
			}
			op[++top2] = s[i];
        }
    }
	cout << num[1].c0 << endl;
    return 0;
}