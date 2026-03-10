#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5 + 100,M = 1e6 + 100;
struct Node {int s,t,c;} a[N];
int diff[M],s[M];

bool cmp(Node x,Node y)
{
	if (x.c != y.c) return x.c < y.c;
	return x.s < y.s;
}

int main() {
	int n,c,d,ans = 0;
	cin >> n >> c >> d;
	for (int i = 1;i <= n;i++) cin >> a[i].s >> a[i].t >> a[i].c;
	sort(a + 1,a + n + 1,cmp);
	Node b = a[1];
	for (int i = 2;i <= n + 1;i++)
	{
		if (b.c == a[i].c && a[i].s - b.t < d) b.t = a[i].t;
		else b.t += d,diff[b.s]++,diff[b.t]--,b = a[i];
	}
	for (int i = 1;i <= 1e6;i++)
		s[i] = s[i - 1] + diff[i],ans = max(ans,s[i]);
	cout << ans << endl;
    return 0;
}