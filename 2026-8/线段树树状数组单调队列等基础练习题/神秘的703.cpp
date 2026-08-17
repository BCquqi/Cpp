#include<iostream>
using namespace std;

const int N = 5e5 + 5;
int hard[N],tree[N];

int lowbit(int x) {return x & -x;}
void updmax(int id,int val) {while (id <= n) tree[id] = max(tree[id],val),id += lowbit(id);}
void updmul(int id,int val) {while (id <= n) tree[id] *= val,id += lowbit(id);}
void change(int id,int val)
int qmax(int id) {
	int ret = 0;
	while (id) ret = max(tree[id],ret),id -= lowbit(id);
	return ret;
}

int main() {
	int n,tal,m;
	cin >> n >> tal;
	for (int i = 1;i <= n;i++) cin >> hard[i];
	cin >> m;
	while (m--) {
		string s;
		int i,d;
		cin >> s >> i >> d;
		if (s == "BookCity") {
			
		}
	}
	return 0;
}
