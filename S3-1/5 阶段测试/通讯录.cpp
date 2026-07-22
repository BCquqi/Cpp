#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5,M = 10;
int ch[N][M],id = 1,sum[N],cnt[N];
string s[N];

void insert(string s) {
	int x = 1;
	for (auto c : s) {
		int i = c - '0';
		if (!ch[x][i]) ch[x][i] = ++id;
		x = ch[x][i];
		sum[x]++;
	}
	cnt[x]++;
}

bool query(string s) {
	int x = 1;
	for (auto c : s) {
		int i = c - '0';
		if (!ch[x][i]) return false;
		x = ch[x][i];
	}
	return sum[x] >= 2;
}

void solve() {
	id = 1;
	memset(ch,0,sizeof ch);
	memset(cnt,0,sizeof cnt);
	memset(sum,0,sizeof sum);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> s[i];
		insert(s[i]);
	}
	for (int i = 1;i <= n;i++)
		if (query(s[i])) { // 自己不能算
			cout << "Yes" << endl;
			return ;
		}
	cout << "No" << endl;
	return ;
}

int main() {
	int T;
	cin >> T;
	while (T--) solve();
	return 0;
}