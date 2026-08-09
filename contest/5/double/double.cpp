#include<iostream>
#include<algorithm>
using namespace std;

// 题意转换为求序列中最大异或和
const int N = 1e5 + 5;
int a[N],s[N],box[N],cur = 0;


void solve() {
    int n,ans = 0;
    cin >> n;
    cur = 0,s[0] = 0,box[++cur] = 0;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        s[i] = s[i - 1] ^ a[i];
        box[++cur] = s[i];
    }
    sort(box + 1,box + cur + 1);
    cur = unique(box + 1,box + cur + 1) - box - 1;
    for (int i = 1;i <= cur;i++) // 随意搭配异或
        for (int j = 1;j <= cur;j++)
            ans = max(ans,box[i] ^ box[j]);
    cout << ans << endl;
    return ;
}

int main() {
    freopen("double.in","r",stdin);
    freopen("double.out","w",stdout);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}