#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 1e5 + 5;
struct Node {
	int a,w;
} s[N];

bool cmp(Node x,Node y) {
	return x.a < y.a;
}

int main()
{
	long long n,sumw = 0,sum = 0,x,ans = 0;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> s[i].a;
	for (int i = 1;i <= n;i++) cin >> s[i].w,sumw += s[i].w;
	sort(s + 1,s + n + 1,cmp);
	for (int i = 1;i <= n;i++) 
	{
		sum += s[i].w;
		if (sum >= sumw / 2 + 1) {x = s[i].a; break;}
	}
	for (int i = 1;i <= n;i++) ans += 1ll * s[i].w * abs(x - s[i].a);
	cout << ans << endl;
	return 0;
}