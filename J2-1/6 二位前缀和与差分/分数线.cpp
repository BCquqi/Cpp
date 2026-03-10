#include<iostream>
using namespace std;

const int N = 505,M = 1e6 + 5;
int a[N][N],s[N][N],x[M],y[M];

int main()
{
	int n,q;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> x[i];
	for (int i = 1;i <= n;i++) cin >> y[i],a[x[i]][y[i]]++;
	for (int i = 0;i <= 500;i++)
		for (int j = 0;j <= 500;j++)
			s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + a[i][j];
	cin >> q;
	while (q--)
	{
		int A,B;
		cin >> A >> B;
		cout << s[500][500] - s[500][B - 1] - s[A - 1][500] + s[A - 1][B - 1] << endl;
	}
	return 0;
}