#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {int a,b;};
vector<Node> d,d1,d2;

int main() {
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++) {
        int a,b;
        cin >> a >> b;
        if (a <= b) d1.push_back({a,b});
        else d2.push_back({a,b});
    }
    sort(d1.begin(),d1.end(),[](Node x,Node y) {return x.a < y.a;});
    sort(d2.begin(),d2.end(),[](Node x,Node y) {return x.b > y.b;});
    for (auto it : d1) d.push_back(it);
    for (auto it : d2) d.push_back(it);
    int ans = 0,suma = 0,sumb = 0;
    for (int i = 1;i <= n;i++)
        suma += d[i].a, 
        ans = max(ans,suma - sumb), 
        sumb += d[i].b;
    cout << ans << endl;
    return 0;
}