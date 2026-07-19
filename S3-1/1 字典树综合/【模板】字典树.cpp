#include<iostream>
using namespace std;

const int N = 1e6 + 5,M = 30;
int ch[N][M],sum[N],cnt[N],id = 1;

void insert(string s) {
	int x = 1;
	for (auto c : s) {
		int i = c - 'a';
		if (!ch[x][i]) ch[x][i] = ++id;
		x = ch[x][i];
		sum[x]++;
	}
	cnt[x]++;
}

int query(string s) {
	int x = 1;
	for (auto c : s) {
		int i = c - 'a';
		if (!ch[x][i]) return 0;
		x = ch[x][i];
	}
	return sum[x];
}

int main() {
	int n,q;
	cin >> n >> q;
	while (n--) {
		string s;
		cin >> s;
		insert(s);
	}
	while (q--) {
		string s;
		cin >> s;
		cout << query(s) << endl;
	}
	return 0;
}