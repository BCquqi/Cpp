#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
struct Node {
	int num,id;
} p[N];
int a[N],L[N],R[N],ans[N];

bool cmp(Node x,Node y) {return x.num < y.num;}
void link(int x,int y) {R[x] = y, L[y] = x;}

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {cin >> a[i]; p[i].num = a[i], p[i].id = i;}
    sort(p + 1,p + n + 1,cmp);
    int head = 0,tail = n + 1;
    for (int i = 1;i <= n;i++) link(p[i - 1].id,p[i].id);
    link(p[n].id,tail);
    for (int i = n;i >= 2;i--) {
    	int x = a[L[i]],y = a[R[i]];
    	x = abs(x - a[i]),y = abs(y - a[i]);
    	if (L[i] == head) x = 2e9;
    	if (R[i] == tail) y = 2e9;
    	if (x <= y) ans[i] = L[i];
    	else ans[i] = R[i];
    	link(L[i],R[i]);
    }
    for (int i = 2;i <= n;i++) cout << abs(a[i] - a[ans[i]]) << ' ' << ans[i] << endl;
    return 0;
}