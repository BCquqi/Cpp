#include<iostream>
#include<unordered_map>
using namespace std;

const int N = 15;
long long n,a[N],s[N];
unordered_map<long long,bool> mp;

void dfs(int step,long long cnt,long long sum) {
    if (step > n) {
        mp[sum] = true;
        return ;
    }
    s[cnt] = a[step];
    dfs(step + 1,cnt + 1,a[step] ^ sum);
    s[cnt] = 0;
    for (int i = 1;i < cnt;i++) {
        long long tmp = s[i] ^ sum;
        s[i] += a[step];
        dfs(step + 1,cnt,s[i] ^ tmp);
        s[i] -= a[step];
    }
    return ;
}

int main() {
    cin >> n;
    for (int i = 1;i <= n;i++) cin >> a[i];
    dfs(1,1,0);
    cout << mp.size() << endl;
    return 0;
}