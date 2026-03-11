#define _for(i,a,b) for( int i=(a); i<(b); ++i)
#define _rep(i,a,b) for( int i=(a); i<=(b); ++i)

_for(i, 0, 4) 
{
	printf("%d", i);
}

#define _for(i,a,b) for( int i=(a); i<(b); ++i)
_for(i, 0, 10)

#include <iostream>
 
// 定义一个宏来封装for循环
#define FOR_LOOP(i, start, end) for(int i = start; i < end; ++i)
 
int main() {
    // 使用宏定义的for循环
    FOR_LOOP(i, 0, 10) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
