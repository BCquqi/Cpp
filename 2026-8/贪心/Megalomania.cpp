#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int N = 2e5 + 5;
struct Node {int a,b;} s[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> s[i].a >> s[i].b;
	sort(s + 1,s + n + 1,[](Node x,Node y) {return x.b < y.b;});
	int t = 0;
	for (int i = 1;i <= n;i++) {
		t += s[i].a;
		if (t > s[i].b) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
