#include<cstdio>
using namespace std;

int main() {
    double r1,r2;
    scanf("%lf%lf",&r1,&r2);
    double R = 1 / (1 / r1 + 1 / r2);
    printf("%.2f\n",R);
    return 0;
}