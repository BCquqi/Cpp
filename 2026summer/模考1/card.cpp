#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5e5 + 5;
int a[N],s[N],S[N * 2];

struct Node {
    int s,e,d;
} num[N],ans[N];

bool cmp(Node x,Node y) {
    if (x.d != y.d) return x.d > y.d;
    if (x.e - x.s != y.e - y.s) return x.e - x.s < y.e - y.s;
    return x.s < y.s;
}

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        if (a[i] == i) s[i] = s[i - 1] + 1;
        else s[i] = s[i - 1];
        num[i] = {a[i],i,abs(i - a[i]) / 2};
    }
    sort(num + 1,num + n + 1,[](Node x,Node y) {return x.d < y.d;});
    for (int i = 1;i <= n;i++) {
        int maxn = max(num[i].s,num[i].e),minn = min(num[i].s,num[i].e);
        if ((maxn - minn) % 2 == 0) {
            int cur = minn + (maxn - minn) / 2;
            S[cur]++,ans[i] = {minn,maxn,S[cur] - s[maxn] + s[minn - 1]};
        } else {
            int cur = minn + (maxn - minn) / 2 + n;
            S[cur]++,ans[i] = {minn,maxn,S[cur] - s[maxn] + s[minn - 1]};
        }
    }
    sort(ans + 1,ans + n + 1,cmp);
    cout << a[ans[1].s] << ' ' << a[ans[1].e] << endl;
    return 0;
}