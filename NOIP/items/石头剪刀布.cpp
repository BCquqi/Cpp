#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;
int main()
{
	int ai=0,player=0;
	srand(time(0));
	printf("剪刀石头布游戏,剪刀出1,石头出2,布出3,停止出4\n");
	while (true){
		int n,a;
		scanf("%d",&n);
		if (n!=1 && n!=2 && n!=3 && n!=4){
			printf("输错了哦,再来一次吧\n");
			printf("\n");
			continue;
		}
		if (n==4)break;
		a=rand()%3+1;
		if (n==1){
			if (a==1){
				printf("双方都出了剪刀,平局\n");
			}else if (a==2){
				printf("你出了剪刀,机器出了石头,机器赢了\n");
				ai++;
			}else{
				printf("你出了剪刀,机器出了布,你赢了\n");
				player++;
			}
			printf("现在比分%d:%d\n",player,ai);
			printf("\n");
			continue;
		}
		if (n==2){
			if (a==2){
				printf("双方都出了石头,平局\n");
			}else if (a==3){
				printf("你出了石头,机器出了布,机器赢了\n");
				ai++;
			}else{
				printf("你出了石头,机器出了剪刀,你赢了\n");
				player++;
			}
			printf("现在比分%d:%d\n",player,ai);
			printf("\n");
			continue;
		}
		if (n==3){
			if (a==3){
				printf("双方都出了布,平局\n");
			}else if (a==1){
				printf("你出了布,机器出了剪刀,机器赢了\n");
				ai++;
			}else{
				printf("你出了布,机器出了石头,你赢了\n");
				player++;
			}
			printf("现在比分%d:%d\n",player,ai);
			printf("\n");
			continue;
		}
	}
	printf("游戏结束");
}
