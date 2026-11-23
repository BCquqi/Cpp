#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 130,M = 1e5 + 5;
int a[N],b[N],fra[N],lsa[N],frb[N],lsb[N];
// a,b 记录不同字母的个数，fr ls 记录第一个 / 最后一个某字母的位置用于判断顺序是否一致  

bool check(char x,char y) {
	if (x == y) {
		if ((a[x] >= 2) && (b[x] >= 2)) return true; // 两个相同的顺序可以颠倒，不特判 
		else return false;
	}
	else if ((a[x] && a[y] && b[x] && b[y]) && ((fra[x] <= lsa[y]) && (frb[x] <= lsb[y]))) return true;
	// else if 条件分析: s1,s2 中字母存在; 两字符串中 x 都在 y 前，必须从左往右 
	return false;
}

void solve() {
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	memset(fra,0x3f,sizeof fra);
	memset(lsa,0,sizeof lsa);
	memset(frb,0x3f,sizeof frb);
	memset(lsb,0,sizeof lsb);
	int n,m,cnt = 2;
	string ans = "";
	cin >> n >> m;
	string s1,s2;
	cin >> s1 >> s2;
	s1 = '?' + s1, s2 = '?' + s2;
	for (int i = 1;i <= n;i++)
		a[s1[i]]++, fra[s1[i]] = min(fra[s1[i]],i), lsa[s1[i]] = max(lsa[s1[i]],i);
	for (int i = 1;i <= m;i++)
		b[s2[i]]++, frb[s2[i]] = min(frb[s2[i]],i), lsb[s2[i]] = max(lsb[s2[i]],i);
	// 字典序顺次枚举各种答案排列，检查是否可行 
	for (char i = 'A';i <= 'Z';i++)
		for (char j = 'A';j <= 'Z';j++)
			if (check(i,j)) {
				cout << i << j << endl;
				return ;
			}
	cout << -1 << endl;
	return ;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("geminae.in","r",stdin);
	freopen("geminae.out","w",stdout);
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
} 
