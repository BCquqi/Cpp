#include<cstdio>
#include<algorithm>
#include<cmath>
#include<bitset>
using namespace std;

const int N = 2005;
int n,m,ansk = 0;
bitset<N> a[N],x;

int GaussJordan(bitset<N> a[N]) {
    int r = 1;
    for (int j = 1;j <= n;j++) {
        int i = r;
        while (i <= m && !a[i][j]) i++;
        if (i > m) continue;
        swap(a[r],a[i]);
        ansk = max(ansk,i);
        for (int i = 1;i <= m;i++)
            if (i != r && a[i][j]) a[i] ^= a[r];
        r++;
    }
    if (--r < n) {
        for (int i = 1;i <= m;i++)
            if (a[i][n + 1]) return -1;
        return 0;
    }
    for (int i = 1;i <= m;i++) x[i] = a[i][n + 1];
    return 1;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= m;i++) {
        for (int j = 1;j <= n;j++) {
            int t;
            scanf("%01d",&t);
            a[i][j] = t;
        }
        int t;
        scanf("%d",&t);
        a[i][n + 1] = t;
    }
    int ans = GaussJordan(a);
    if (ans == -1 || ans == 0) printf("Cannot Determine\n");
    else {
        printf("%d\n",ansk);
        for (int i = 1;i <= n;i++)
            if (x[i]) printf("?y7M#\n");
            else printf("Earth\n");
    }
    return 0;
}