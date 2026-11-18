#include<iostream>
using namespace std;

const int N = 2e5 + 5;
int a[N],p[N];

int main() {
    freopen("dream.in","r",stdin);
    freopen("dream.out","w",stdout);
    int n,k,Q;
    cin >> n >> k >> Q;
    for (int i = 1;i <= n;i++) {
        cin >> p[i];
        a[i] = 1;
    }
    while (Q--) {
        int op;
        cin >> op;
        switch (op) {
            case 1 : {
                int cnt = 0;
                for (int i = 1;i <= n;i++) {
                    if (a[p[i]] == 1) a[p[i]] = 0, cnt = 0;
                    else cnt++;
                    if (cnt == k) break;
                }
                break;
            }
            case 2 : {
                int x;
                cin >> x;
                a[x] = 1;
                break;
            }
            case 3 : {
                int l,r;
                cin >> l >> r;
                int cnt = 0,ans = 0;
                for (int i = l;i <= r;i++) {
                    if (a[i] == 1) cnt++;
                    else ans += cnt * cnt, cnt = 0;
                }
                ans += cnt * cnt, cnt = 0;
                cout << ans << endl;
                break;
            }
        }
    }
    return 0;
}