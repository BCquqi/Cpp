#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> cols[7]={{7},{4},{8,2},{5,1},{9,3},{6},{10}};
int main() {
    string s;
    cin >> s;
    
    if(s[0] != '0') {
        cout<<"No"<<endl;
        return 0;
    }
    vector<int> has(7,0 );
    vector<int> down(7,1);
    for(int i=0;i<7;i++) {
        int all0=1;
        int any1=0;
        for(int p:cols[i]) {
            if(s[p-1] == '1') {
                any1=1;
                all0=0;
            }
        }
        has[i]=any1;
        down[i]=all0;
    }
    
    for(int l=0;l<7;l++) {
        if(!has[l]) continue;
        for(int r=l+1;r<7;r++) {
            if(!has[r]) continue;
            
            int mid=0;
            for(int k=l+1;k<r;k++) {
            	
                if(down[k]) {
                    mid=1;
                    break;
                }
            }
            if(mid) {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"No"<<endl;
    return 0;
}
