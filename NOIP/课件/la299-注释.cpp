#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

const int maxn=10;
int n;
char pos[maxn][maxn][maxn];
char view[6][maxn][maxn];

char read_char(){
    char ch;
    for(;;){
        ch=getchar();
        if((ch>='A' && ch<='Z') || ch=='.')return ch;
    }
}
void get(int k,int i,int j,int len,int &x,int &y,int &z){
    switch(k){
        case 0:x=len;y=j;z=i;break;
        case 1:x=n-1-j;y=len;z=i;break;
        case 2:x=n-1-len;y=n-1-j;z=i;break;
        case 3:x=j;y=n-1-len;z=i;break;
        case 4:x=n-1-i;y=j;z=len;break;
        case 5:x=i;y=j;z=n-1-len;break;
    }
}//表示第k个视图中，第i行第j列、深度为len单位立方体在原立方体中的坐标(x,y,z)
int main(){
    while(cin>>n && n){
        REP(i,n)REP(k,6)REP(j,n)view[k][i][j]=read_char();
        REP(i,n)REP(j,n)REP(k,n)pos[i][j][k]='#';
        // 如果视图这个位置为空,可以看穿,说明这排是没有单位立方体的.全部标为空.
        REP(k,6)REP(i,n)REP(j,n)if(view[k][i][j]=='.'){
            REP(p,n){
                int x,y,z;
                get(k,i,j,p,x,y,z);
                pos[x][y][z]='.';
            }
        }
        // 不断重复地扫描六个面.将没被删除的格子进行染色.
        for(;;){
            bool done=true;
            REP(k,6)REP(i,n)REP(j,n)if(view[k][i][j]!='.'){
                REP(p,n){
                    int x,y,z;
                    get(k,i,j,p,x,y,z);
                    if(pos[x][y][z]=='.')continue;// 如果是'.',那么这个格子已经被删除掉了,跳过
                    if(pos[x][y][z]=='#'){// 如果没染过色,进行染色.
                        pos[x][y][z]=view[k][i][j];
                        break;
                    }
                    if(pos[x][y][z]==view[k][i][j])break;// 两个视图看到的颜色一样.暂定为存在
                    else{// 两个视图看到的颜色不一样,说明不存在,删掉这个单位立方体.
                        pos[x][y][z]='.';
                        done=false;
                    }
                }
            }
            if(done)break;// 如果遍历六个视图后没有删掉一个单位立方体,可以结束循环.
        }

        int ans=0;// 计算重量
        REP(i,n)REP(j,n)REP(k,n)
            if(pos[i][j][k]!='.')ans++;

        printf("Maximum weight: %d gram(s)\n",ans);
    }return 0;
}
