#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int t,w;
} a[505];

bool cmp (Node x,Node y)
{
	return x.w > y.w;
}

bool v[505];

int main(){
	int m,n;
	cin >> m;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].t;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i].w;
		m -= a[i].w;
	}
	sort(a + 1,a + n + 1,cmp);
	for (int i = 1;i <= n;i++)
	{
		for (int j = a[i].t;j >= 1;j--)
		{
			if (!v[j])
			{
				v[j] = true;
				m += a[i].w;
				break;
			}
		}
	}
	cout << m << endl;
	return 0;
}
