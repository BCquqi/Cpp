#include<iostream>
#define int long long
using namespace std;

const int N = 2e5 + 5;
int a[N],tree1[N],tree2[N],n,f;

int lowbit(int x) {return x & -x;}
void add(int id,int val,int tree[]) {while (id <= n) tree[id] += val,id += lowbit(id);}
int query(int id,int tree[]) {
	int ret = 0;
	while (id) ret += tree[id],id -= lowbit(id);
	return ret;
}

signed main() {
	cin >> n >> f;
	for (int i = 1;i <= n;i++) {
		cin >> a[i]; 
		add(i,a[i] - a[i - 1],tree1);
        add(i,(a[i] - a[i - 1]) * (i - 1),tree2);
	}
	while (f--) {
		int op;
		cin >> op;
		switch (op) {
			case 1 : {
				int l,r,k;
				cin >> l >> r >> k;
				add(l,k,tree1); add(r + 1,-k,tree1);
				add(l,(l - 1) * k,tree2); add(r + 1,-r * k,tree2);
				break;
			}
			case 2 : {
				int k;
				cin >> k;
				add(1,k,tree1); add(2,-k,tree1);
				add(1,0,tree2); add(2,-k,tree2);
				break;
			}
			case 3 : {
				int k;
				cin >> k;
				add(1,-k,tree1); add(2,k,tree1);
				add(1,0,tree2); add(2,k,tree2);
				break;
			}
			case 4 : {
				int l,r;
				cin >> l >> r;
				cout << (r * query(r,tree1) - query(r,tree2)) - ((l - 1) * query(l - 1,tree1) - query(l - 1,tree2)) << endl;
				break;
			}
			case 5 : {
				cout << (query(1,tree1) - query(1,tree2) + query(0,tree2)) << endl;
				break;
			}
		}
	}
	return 0;
} 
