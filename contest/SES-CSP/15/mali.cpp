#include<iostream>
using namespace std;

// 值域小 优先用值域排序

const int N = 105;
int a[N],b[N],cpya[N],cpyb[N];

int main() {
    freopen("mali.in","r",stdin);
    freopen("mali.out","w",stdout);
    int n;
    cin >> n;
    while (n--) {
        int ai,bi;
        cin >> ai >> bi;
        a[ai]++, b[bi]++;
        for (int i = 1;i <= 100;i++) cpya[i] = a[i], cpyb[i] = b[i];
        int res = 0,i = 1,j = 100;
        while (i <= 100 && j >= 1) {
            while (i <= 100 && !cpya[i]) i++;
            while (j >= 1 && !cpyb[j]) j--;
            if (i == 101 || j == 0) break;
            res = max(res,i + j);
            cpya[i]--, cpyb[j]--;
        }
        cout << res << endl;
    }
    return 0;
}