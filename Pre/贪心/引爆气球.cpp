#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int b,e;
} s[200005];

bool cmp(Node x,Node y)
{
	return x.e < y.e;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i].b >> s[i].e;
	}
	sort(s + 1,s + n + 1,cmp);
	int ans = 1,pik = 1;
	for (int i = 2;i <= n;i++)
	{
		if (s[i].b > s[pik].e)
		{
			ans++;
			pik = i;
		}
	}
	cout << ans << endl;
	return 0; 
}
