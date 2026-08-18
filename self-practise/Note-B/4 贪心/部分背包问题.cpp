#include<iostream>
#include<algorithm>
using namespace std;

const int N = 105;
struct Node {int m,v; double xjb;} s[N];

int main() {
    int n;
    double t,ans = 0;
    cin >> n >> t;
    for (int i = 1;i <= n;i++) {
        cin >> s[i].m >> s[i].v;
        s[i].xjb = 1.00 * s[i].v / s[i].m;
    }
    sort(s + 1,s + n + 1,[](Node x,Node y) {return x.xjb > y.xjb;});
    for (int i = 1;i <= n;i++) {
        if (t - s[i].m > -1e-6)
            t -= s[i].m,ans += s[i].v;
        else {
            ans += t * s[i].xjb;
            break;
        }
    }
    printf("%.2lf",ans);
    return 0;
}