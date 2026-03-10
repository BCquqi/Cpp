#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
struct Node {
	int s,h;
	string t;
} a[N];

bool cmp(Node x,Node y) {
	return x.s * y.h > y.s * x.h;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i].t;
		for (auto c : a[i].t)
			if (c == 's') a[i].s++;
			else a[i].h++;
	}
	sort(a + 1,a + n + 1,cmp);
	long long ans = 0,cnts = 0;
	for (int i = 1;i <= n;i++)
		for (auto c : a[i].t)
			if (c == 'h') ans += cnts;
			else cnts++;
	cout << ans << endl;
	return 0;
}