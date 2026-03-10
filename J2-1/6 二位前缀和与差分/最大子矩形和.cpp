#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;
int a[N][N],s[N][N];

int main(){
	int n,m,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= m;j++)
		{
			cin >> a[i][j];
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	for (int x1 = 1;x1 <= n;x1++)
		for (int x2 = x1;x2 <= n;x2++)
			for (int y1 = 1;y1 <= m;y1++)
				for (int y2 = y1;y2 <= m;y2++)
					ans = max(ans,s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
	cout << ans << endl;
	return 0;
}