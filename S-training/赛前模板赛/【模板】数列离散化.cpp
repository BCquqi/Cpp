#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

const int N = 1e5 + 5;
int a[N],b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1,b + n + 1);
    map<int,int> rank;
    int cnt = 0;
    for (int i = 1;i <= n;i++)
        if (!rank[b[i]]) rank[b[i]] = ++cnt;
    for (int i = 1;i <= n;i++) cout << rank[a[i]] << ' ';
    cout << endl;
}

int main()
{
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}