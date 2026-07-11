#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e3 + 5;
struct Node {int p,a;} s[N];

int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= m;i++) cin >> s[i].p >> s[i].a;
	sort(s + 1,s + m + 1,[](Node x,Node y) {return x.p < y.p;});
	int sum = 0,ans = 0;
	for (int i = 1;i <= m;i++) {
		if (sum + s[i].a <= n)
			sum += s[i].a,ans += s[i].p * s[i].a;
		else {
			ans += (n - sum) * s[i].p;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}