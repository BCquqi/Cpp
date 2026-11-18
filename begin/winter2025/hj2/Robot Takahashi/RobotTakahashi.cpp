#include<iostream>
using namespace std;

const int N = 2e5 + 5;
struct People {
    int w;
    bool isAdult;
} a[N];
int child[N],adult[N];

bool cmp(People x,People y) {return x.w < y.w;}

int main() {
    int n,ans = 0; string s;
    cin >> n >> s;
    for (int i = 1;i <= n;i++) {
        cin >> a[i].w;
        a[i].isAdult = (s[i - 1] == '1');
    }
    sort(a + 1,a + n + 1,cmp);
    for (int i = 1;i <= n;i++)
        child[i] = !a[i].isAdult ? child[i - 1] + 1 : child[i - 1], 
        adult[n - i + 1] = a[n - i + 1].isAdult ? adult[n - i + 2] + 1 : adult[n - i + 2];
    ans = max(ans,max(child[n],adult[1]));
    for (int i = 1;i <= n;i++)
        if (a[i].w != a[i + 1].w) ans = max(ans,child[i] + adult[i + 1]);
    cout << ans << endl;
    return 0;
}