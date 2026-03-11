#include<iostream>
#include <cstring>
using namespace std;

int a[15],n,cnt = 0;
bool vis[15];
int c[30],z[30],f[30];

void dfs(int step)
{
    if (step > n)
    {
        if (cnt >= 3)
        {
            cnt++;
            return ;
        }
        for (int i = 1;i <= n;i++) cout << a[i] << ' ';
        cout << endl;
        cnt++;
        return ;
    }
    for (int i = 1;i <= n;i++)
    {
        if (vis[i]) continue;
        a[step] = i;
        if (c[i] || z[step - i + n] || f[step + i]) continue;
        c[i]++;
        z[step - i + n]++;
        f[step + i]++;
        vis[i] = true;
        dfs(step + 1);
        vis[i] = false;
        a[step] = 0;
        c[i]--;
        z[step - i + n]--;
        f[step + i]--;
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << cnt << endl;
    return 0;
}
