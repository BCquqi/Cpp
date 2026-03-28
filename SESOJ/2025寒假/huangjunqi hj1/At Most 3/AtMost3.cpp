#include<iostream>
#include<map>
using namespace std;

const int N = 305;
int a[N];
map<int,bool> mp;

int main() {
    int n,w;
    cin >> n >> w;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        if (a[i] <= w) mp[a[i]] = true;
        for (int j = i + 1;j <= n;j++) {
            if (a[i] + a[j] <= w) mp[a[i] + a[j]] = true;
            for (int k = j + 1;k <= n;k++)
                if (a[i] + a[j] + a[k] <= w) mp[a[i] + a[j] + a[k]] = true;
        }
    }
    cout << mp.size() << endl;
    return 0;
}