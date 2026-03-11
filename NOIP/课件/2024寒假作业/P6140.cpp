#include<iostream>
using namespace std;

char a[2005],b[2005];

bool fun (int left,int right)
{
	int cmp = 0;
	while (a[left + cmp] == a[right - cmp])
	{
		if (left + cmp >= right + cmp) break;
		cmp++;
	}
	if (a[left + cmp] > a[right - cmp])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	int left = 1,right = n;
	int cur = 1;
	for (int i = 1;i <= n;i++)
	{
		if (fun(left,right))
		{
			b[cur] = a[right];
			right--;
			cur++;
		}
		else
		{
			b[cur] = a[left];
			left++;
			cur++;
		}
	}
	for (int i = 1;i <= n;i++)
	{
		cout << b[i];
		if (i % 80 == 0) cout << endl;
	}
	return 0;
}
