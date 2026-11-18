#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 2005;
struct Drink {int v,s;} a[N];
// v = volume, s = suger
vector<Drink> p,q;

int main() {
    int n,t;
    scanf("%d%d",&n,&t);
    for (int i = 1;i <= n;i++)
        scanf("%d%d",&a[i].v,&a[i].s);
    double ans = 0;
    int d1 = 0,d2 = 0,s1 = 0,s2 = 0;
    for (int i = 1;i <= n;i++) {
        auto [v,s] = a[i];
        if (s == t) ans += v;
        else if (s < t) {
            d1 += v * (t - s), s1 += v;
            p.push_back({v,t - s});
        } else {
            d2 += v * (s - t), s2 += v;
            q.push_back({v,s - t});
        }
    }
    if (d1 == d2) ans += d1 + d2;
    else if (d1 < d2) {
        ans += s1;
        sort(q.begin(),q.end(),[](Drink x,Drink y) {return x.s < y.s;});
        double sum = 0;
        for (auto [v,s] : q) {
            if (sum + v * s <= d1)
                sum += v * s, ans += v;
            else {ans += (1.00 * d1 - sum) / s; break;}
        }
    } else {
        ans += s2;
        sort(p.begin(),p.end(),[](Drink x,Drink y) {return x.s < y.s;});
        double sum = 0;
        for (auto [v,s] : p) {
            if (sum + v * s <= d2)
                sum += v * s, ans += v;
            else {ans += (1.00 * d2 - sum) / s; break;}
        }
    }
    printf("%.3lf\n",ans);
    return 0;
}