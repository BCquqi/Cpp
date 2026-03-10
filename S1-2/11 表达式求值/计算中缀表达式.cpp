#include<iostream>
#include<cmath>
using namespace std;

const int N = 105;
int num[N],op[N],top1 = 0,top2 = 0;

int id (char c) {
	if (c == '+' || c == '-') return 1;
	if (c == '*' || c == '/') return 2;
	if (c == '^') return 3;
	return 0;
}

int cal(int x,int y,char c) {
	if (c == '+') return x + y;
	if (c == '-') return x - y;
	if (c == '*') return x * y;
	if (c == '/') return x / y;
	if (c == '^') return pow(x,y);
}

int main() {
	string s;
	cin >> s;
	s = '(' + s + ')';
	for (int i = 0;i < s.size();i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			int x = 0;
			while ('0' <= s[i] && s[i] <= '9') {
				x = x * 10 + s[i] - '0';
				i++;
			}
			num[++top1] = x,i--;
		}
		else if (s[i] == '(') op[++top2] = s[i];
		else if (s[i] == ')') {
			while (op[top2] != '(') {
				int y = num[top1--],x = num[top1--];
				char c = op[top2--];
				num[++top1] = cal(x,y,c);
			}
			top2--;
		}
		else {
			while (top2 > 0 && id(op[top2]) >= id(s[i])) {
                if (s[i] == '^') break;
				int y = num[top1--],x = num[top1--];
				char c = op[top2--];
				num[++top1] = cal(x,y,c);
			}
			op[++top2] = s[i];
		}
	}
	cout << num[top1] << endl;
	return 0;
}