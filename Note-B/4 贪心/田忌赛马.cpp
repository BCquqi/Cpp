#include<iostream>
#include<algorithm>
using namespace std;

const int N = 2005;
int a[N],b[N];

int main() {
    int n,ans = 0;
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) cin >> b[i];
    sort(a + 1,a + n + 1); sort(b + 1,b + n + 1);
    int la = 1,ra = n,lb = 1,rb = n;
    while (la <= ra && lb <= rb) {
        if (a[ra] > b[rb]) ans += 200,ra--,rb--;
        else if (a[ra] < b[rb]) ans -= 200,la++,rb--;
        else if (a[la] > b[lb]) ans += 200,la++,lb++;
        else if (a[la] < b[rb]) ans -= 200,la++,rb--;
        else la++,rb--;
    }
    cout << ans << endl;
    return 0;
}