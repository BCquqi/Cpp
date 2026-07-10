#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
#define DEV_RND ( ( ((unsigned long long)rand() << 31) | (unsigned long long)rand() ) | ( (unsigned long long)(rand() & 1) << 62 ) )
#define RND(L,R) ( (long long)( (DEV_RND % ( (unsigned long long)(R) - (unsigned long long)(L) + 1ULL )) + (unsigned long long)(L) ) )

int main(){
    int T;
    srand(time(0));
    T = RND(1,100);
    printf("%d\n",T);
    while(T--) {
        int a = RND(1,1000000),b = RND(1,1000000);
        printf("%d %d\n",min(a,b),max(a,b));
    }
    return 0;
}