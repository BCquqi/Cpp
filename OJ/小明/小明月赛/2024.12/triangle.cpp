#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
	freopen("triangle.in","r",stdin);
	freopen("triangle.out","w",stdout);
    double x,y,a,b,c;
    scanf("%lf%lf",&x,&y);
    a = min(x,y);
    b = max(x,y);
    if (b * b - a * a >= 0) {
        c = max(sqrt(b * b - a * a),sqrt(a * a + b * b));
    } else {
        c = sqrt(a * a + b * b);
    }
    printf("%.4lf\n",c);
    return 0;
}
