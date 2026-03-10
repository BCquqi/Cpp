#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5005;
int a[N][N],s[N][N];

int main(){
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		int x,y,v;
		cin >> x >> y >> v;
		x++,y++;
		a[x][y] += v;;
	}
	for (int i = 1;i <= 5001;i++)
		for (int j = 1;j <= 5001;j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
	int ans = 0;
	for (int i = 1;i + m - 1 <= 5001;i++)
		for (int j = 1;j + m - 1 <= 5001;j++)
		{
			int x = i + m - 1,y = j + m - 1;
			ans = max(ans,s[x][y] - s[x][j - 1] - s[i - 1][y] + s[i - 1][j - 1]);
		}
	cout << ans << endl;
	return 0;
}