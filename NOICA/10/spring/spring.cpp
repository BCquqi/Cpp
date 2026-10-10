#include<iostream>
#include<unordered_set>
#include<random>
using namespace std;

const int N = 1e5 + 5,M = 2005;
const double eps = 1e-6;
struct Point {int x,y;} a[N];
int n,k,slope[M][M];

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
    int gen = 32;
    while (gen--) {
        mt19937 gen(time(NULL));
    }
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