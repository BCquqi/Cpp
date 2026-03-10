#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;
long long s[N],t[N],x[N];

int main(){
	int a,b,q;
	cin >> a >> b >> q;
	for (int i = 1;i <= a;i++) cin >> s[i];
	for (int i = 1;i <= b;i++) cin >> t[i];
	sort(s + 1,s + a + 1);
	sort(t + 1,t + b + 1);
	while (q--)
	{
		long long x,ans = 1e18;
		cin >> x;
		int poss = upper_bound(s + 1,s + a + 1,x) - s;
		int post = upper_bound(t + 1,t + b + 1,x) - t;
		long long s1 = s[poss],s2 = s[poss - 1];
		long long t1 = t[post],t2 = t[post - 1];
		if (poss <= a && post <= b) ans = min(ans,max(s1,t1) - x);
		if (poss > 1 && post > 1) ans = min(ans,x - min(s2,t2));
		if (poss <= a && post > 1)
		{
			ans = min(ans,s1 - x + s1 - t2);
			ans = min(ans,x - t2 + s1 - t2);
		}
		if (poss > 1 && post <= b)
		{
			ans = min(ans,t1 - x + t1 - s2);
			ans = min(ans,x - s2 + t1 - s2);
		}
		cout << ans << endl;
	}
	return 0;
}
