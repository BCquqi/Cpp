#include<iostream>
#include<algorithm>
#include<cstring>
#define int long long
using namespace std;

const int N = 1e6 + 5;
int x[N],p[N],c[N],s1[N],s2[N],dp[N],q[N];
//  ���� ���� ����   ά����          ���� 

signed main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> x[i] >> p[i] >> c[i];
		s1[i] = s1[i - 1] + p[i], s2[i] = s2[i - 1] + p[i] * x[i]; 
	}
	int l = 1,r = 1;
	for (int i = 1;i <= n;i++) {
		while (l < r && dp[q[l + 1]] + s2[q[l + 1]] - dp[q[l]] - s2[q[l]] <= x[i] * (s1[q[l + 1]] - s1[q[l]])) ++l;
		dp[i] = dp[q[l]] + c[i] + x[i] * (s1[i] - s1[q[l]]) - (s2[i] - s2[q[l]]);
		if (!p[i]) dp[i] = min(dp[i],dp[i - 1]);
		while (l < r && (dp[q[r]] + s2[q[r]] - dp[q[r - 1]] - s2[q[r - 1]]) * (s1[i] - s1[q[r]]) >= (dp[i] + s2[i] - dp[q[r]] - s2[q[r]]) * (s1[q[r]] - s1[q[r - 1]])) --r;
		q[++r] = i;
	}
	int ans = 1e18,i;
	// ���߼�: ���л������� n, ���һ���л��������ߺ�����û�������������ұ���ѡ��һ���ֿ� 
	for (i = n;!p[i] && i >= 1;i--)
		ans = min(ans,dp[i]);
	ans = min(ans,dp[i]);
	cout << ans << endl;
	return 0;
} 
