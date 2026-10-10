#include<iostream>
#include<unordered_set>
using namespace std;

const int N = 1e5 + 5,M = 2005;
const double eps = 1e-6;
struct Point {int x,y;} a[N];
int n,k,slope[M][M];
int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

void merge(int x,int y) {
    int fx = find(x),fy = find(y);
    if (fx != fy) f[fx] = fy;
}

bool check() {
    double num;
    if (a[2].x - a[1].x == 0) num = 1e9;
    else num = 1.0 * (a[2].y - a[1].y) / (a[2].x - a[1].x);
    for (int i = 3;i <= n;i++) {
        double tmp;
        if (a[i].x - a[i - 1].x == 0) tmp = 1e9;
        else tmp = 1.0 * (a[i].y - a[i - 1].y) / (a[i].x - a[i - 1].x);
        if (abs(tmp - num) >= eps) return false;
    }
    return true;
}

void solve() {
    cin >> n >> k;
    for (int i = 1;i <= n;i++)
        cin >> a[i].x >> a[i].y;
    for (int i = 1;i <= n;i++) f[i] = i;
    if (k == 1) {
        if (check()) cout << "YES" << endl;
        else cout << "NO" << endl;
        return ;
    }
    for (int i = 1;i < n;i++)
        for (int j = i + 1;j <= n;j++) {
            double tmp;
            if (a[i].x - a[j].x == 0) tmp = 1e9;
            else tmp = 1.0 * (a[i].y - a[j].y) / (1.0 * (a[i].x - a[j].x));
            slope[i][j] = tmp;
        }
    for (int i = 1;i < n;i++)
        for (int j = j + 1;j <= n;j++)
            for (int p = 1;p < n;p++)
                if (abs(slope[i][j] - slope[j][p]) <= eps) merge(i,j), merge(j,p);
    int ans = 0;
    for (int i = 1;i <= n;i++)
        if (find(i) == i) ans++;
    cout << ans << endl;
    if (ans == k) cout << "YES" << endl;
    else cout << "NO" << endl;
    return ;
}

int main() {
    freopen("spring.in","r",stdin);
    freopen("spring.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}