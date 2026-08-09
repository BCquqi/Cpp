#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int mp[] = {6,2,5,5,4,5,6,3,7,5};

int main() {
    freopen("SegCount.in","r",stdin);
    freopen("SegCount.out","w",stdout);
    int a,b,ans = 0;
    cin >> a >> b;
    long long sum = a + b;
    while (sum > 0) {
        ans += mp[int(sum % 10)];
        sum /= 10;
    }
    cout << ans << endl;
    return 0;
}