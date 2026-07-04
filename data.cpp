#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;
#define DEV_RND ((int)rand()*RAND_MAX+rand())
#define RND(L,R) (DEV_RND%((R)-(L)+1)+(L))

int main(){
    int T;
    srand(time(0));
    T = RND(1,100);
    printf("%d\n",T);
    while(T--) {
        int a = RND(1,1000000),b = RND(1,1000000);
        // printf("%d %d\n",min(a,b),max(a,b));
    }
    return 0;
}