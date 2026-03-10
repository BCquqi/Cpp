#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 50005;
struct Node {
	int w,s;
} a[N];

bool cmp(Node x,Node y) {
	return max(-x.s,x.w - y.s) < max(y.w - x.s,-y.s);
}

int main(){
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> a[i].w >> a[i].s;
	sort(a + 1,a + n + 1,cmp);
	int sum = 0,ans = -1e9;
	for (int i = 1;i <= n;i++)
	{
		ans = max(ans,sum - a[i].s);
		sum += a[i].w;
	}
	cout << ans << endl;
	return 0;
}