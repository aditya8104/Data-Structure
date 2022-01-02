#include <bits/stdc++.h>
using namespace std;
#define r 3
#define c 10
int count(int g[r][c],int i,int j,int x,int y){
	if(i==x && j==y){
		return 1;
	}
	g[i][j]=0;
	int res=0;
	if(i<r-1 && g[i+1][j]==1){
		res=max(res,count(g,i+1,j,x,y));
	}
	if(i>0 && g[i-1][j]==1){
		res=max(res,count(g,i-1,j,x,y));
	}
	if(j<c-1 && g[i][j+1]==1){
		res=max(res,count(g,i,j+1,x,y));
	}
	if(j>0 && g[i][j-1]==1){
		res=max(res,count(g,i,j-1,x,y));
	}
	g[i][j]=1;
	if(res!=0){
		res+=1;
	}
	return res;
}
int main(){
	int g[r][c];
	for(int i=0;i<3;i++){
		for(int j=0;j<10;j++){
			cin>>g[i][j];
		}
	}
	cout<<count(g,0,0,1,7);
}