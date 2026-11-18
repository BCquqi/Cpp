#include<iostream>
#include<random>
#include<ctime>
using namespace std;

const int N = 2e5 + 5;
struct Point {long long x,y;} a[N],v[N];
mt19937 rng(time(0));

inline bool cal(Point a,Point b,Point c)
{return (b.x - a.x) * (c.y - a.y) == (b.y - a.y) * (c.x - a.x);}

void solve() {
    int n,k;
    cin >> n >> k;
    for (int i = 1;i <= n;i++) cin >> a[i].x >> a[i].y;
    if (n <= 2) {
        cout << "YES" << endl;
        return;
    }
    if (k == 1) {
        bool flag = true;
        for (int i = 3;i <= n;i++)
            if (!cal(a[1],a[2],a[i])) {
                flag = false;
                break;
            }
        if (flag) cout << "YES" << endl;
        else cout << "NO" << endl;
        return;
    } else if (k == 2) {
        for (int gen = 0;gen < 100;gen++) {
            int p = rng() % n + 1,q = rng() % n + 1;
            while (q == p) q = rng() % n + 1;
            int cnt = 0;
            for (int i = 1;i <= n;i++)
                if (i != p && i != q)
                    if (!cal(a[p],a[q],a[i])) v[++cnt] = a[i];
            
            if (cnt <= 2) {
                cout << "YES" << endl;
                return;
            }
            bool flag = true;
            for (int i = 3;i <= cnt;i++)
                if (!cal(v[1],v[2],v[i])) {
                    flag = false;
                    break;
                }
            if (flag) {
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
    }
}

int main() {
    freopen("spring.in","r",stdin);
    freopen("spring.out","w",stdout);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}