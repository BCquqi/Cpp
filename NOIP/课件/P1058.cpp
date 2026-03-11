#include<iostream>
using namespace std;

int a[55][55];

int main()
{
	int m,n;
	cin >> m >> n;
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= n;j++)
			cin >> a[i][j];
	return 0;
}
