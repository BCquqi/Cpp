#include<cstdio>
using namespace std;

int main() {
    freopen("variance.in","r",stdin);
    freopen("variance.out","w",stdout);
    int n,l,r;
    scanf("%d%d%d",&n,&l,&r);
    int half = n / 2;
    double ave = 1.00 * (1.00 * (l * half) + 1.00 * (r * (n - half))) / n;
    double ans = 1.00 * (1.00 * half * (1.00 * ave - l) * (1.00 * ave - l) + 1.00 * (n - half) * (1.00 * r - ave) * (1.00 * r - ave)) / n;
    printf("%.2lf",ans);
    return 0;
}