#include<iostream>
using namespace std;

const int N = 130;
string s1,s2;
int a[N];

char build(int l,int r,int t) {
	if (l > r) return 0;
	char root = s1[t];
	int pos = l;
	for (int i = l;i <= r;i++)
		if (s2[i] == root) pos = i;
	char L = build(l,pos - 1,t + 1),R = build(pos + 1,r,t + pos - l + 1);
	if (L == 0 && R == 0) a[root] = 1;
	else a[root] = a[L] + a[R];
	return root;
}

void dfs(int id) {
	if (id > s1.size() - 1) return ;
	for (int i = 1;i <= a[s1[id]];i++) cout << s1[id];
	cout << endl;
	dfs(id + 1);
}

int main() {
    cin >> s1 >> s2;
    int len = s1.size();
    s1 = '?' + s1,s2 = '?' + s2;
	build(1,len,1);
	dfs(1);
    return 0;
}