#include<iostream>
#include<algorithm>
#define lid id * 2
#define rid id * 2 + 1
using namespace std;

const int N = 1e6 + 5;
struct seg_tree {int sum;} tr[N << 2];

void modify(int id,int l,int r,int k,int val) {
    tr[id].sum += val;
    if (l == r) return ;
    int mid = (l + r) >> 1;
    if (k <= mid) modify(lid,l,mid,k,val);
    else modify(rid,mid + 1,r,k,val);
}

int query(int id,int l,int r,int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (k <= tr[lid].sum) return query(lid,l,mid,k);
    else return query(rid,mid + 1,r,k - tr[lid].sum);
}

int f(int id,int l,int r) {
    if (l == r) return l;
    int m = (l + r) >> 1;
    if (tr[lid].sum) return f(lid, l, m);
    return f(rid, m + 1, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,q;
    cin >> n >> q;
    for (int i = 1;i <= n;i++) {
        int a;
        cin >> a;
        modify(1,1,N - 5,a,1);
    }
    while (q--) {
        int k;
        cin >> k;
        if(k > 0) modify(1,1,N - 5,k,1);
        else modify(1,1,N - 5,query(1,1,N - 5,~k + 1),-1);
    }
    cout << (!tr[1].sum ? 0 : f(1,1,N - 5)) << endl;
    return 0;
}