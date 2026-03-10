#include<iostream>
#include<cmath>
using namespace std;

int n,maxg = 0,ans = 0;
int p[] = {0,2,3,5,7,11,13,17,19,23,29,31};

void dfs(int step,int k,long long s,long long g) {
    if (s > n) return ;
    if (g > maxg || (g == maxg && s < ans)) maxg = g,ans = s;
    long long t = s;
    for (int i = 1;i <= k;i++) {
        t *= p[step];
        if (t > n) break;
        dfs(step + 1,i,t,g * (i + 1));
    }
}

int main() {
    cin >> n;
    dfs(1,31,1,1);
    cout << ans << endl;
    return 0;
}