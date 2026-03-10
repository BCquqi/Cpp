#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int num,t;
} s[1005];

bool cmp (Node x,Node y)
{
	if (x.t != y.t) return x.t < y.t;
	else return x.num < y.num;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i].t;
		s[i].num = i;
	}
	sort(s + 1,s + n + 1,cmp);
	long long ans = 0;
	for (int i = 1;i <= n;i++)
	{
		cout << s[i].num << " ";
		ans += s[i].t * (n - i);
	}
	printf("\n%.2lf\n",ans * 1.00 / n);
	return 0;
}
