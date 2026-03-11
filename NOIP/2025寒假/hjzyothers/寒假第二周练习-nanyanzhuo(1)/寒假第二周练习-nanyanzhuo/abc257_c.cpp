#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct f{
	int val,age;
};
int n;
string s;
int w[200005];
f p[200005];

int main() {
    cin >> n >> s;
    for (int i=0;i<n;i++) cin >> w[i];
    int c0=0;
    for (int i=0;i<n;i++) {
        int t=s[i]-'0';
        p[i]={w[i], t};
        if (t == 0) c0++;
    }
    sort(p, p + n);
    int cur=c0, ans=cur;
    for (int i=0;i<n;) {
        int x=p[i].val;
        while (i<n && p[i].val == x) {
            if (p[i].age == 0) cur--;
            else cur++;
            i++;
        }
        if (cur>ans) ans=cur;
    }
    
    cout << ans << endl;
    return 0;
}
