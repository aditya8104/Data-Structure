#include <bits/stdc++.h>
using namespace std;
#define R 12
#define C 10
bool issafe(int g[R][C],int i,int j){
	bool res=true;
	for(int x=i-1;x<i+2;x++){
		if(x!=i){
			if(x>=0 && x<R){
				if(g[x][j]==0){
					res=false;break;
				}
			}
		}
	}
	for(int x=j-1;x<j+2;x++){
		if(x!=j){
			if(x>=0 && x<C){
				if(g[i][x]==0){
					res=false;
				}
			}
		}
	}
	return res;
}
int count(int g[R][C],int v[R][C],int i,int j,int c){
	if(j==C-1){
		return c;
	}
	int res=INT_MAX;
	v[i][j]=1;
	if(i<R-1){
		if(g[i+1][j]==1 && v[i+1][j]==0 && issafe(g,i+1,j)){

			res=count(g,v,i+1,j,c+1);
		}
	}
	if(j<C-1){
		if(g[i][j+1]==1 && v[i][j+1]==0 && issafe(g,i,j+1)){

			res=min(res,count(g,v,i,j+1,c+1));
		}
	}
	if(i>0){
		if(g[i-1][j]==1 && v[i-1][j]==0 && issafe(g,i-1,j)){

			res=min(res,count(g,v,i-1,j,c+1));
		}
	}
	if(j>0){
		if(g[i][j-1]==1 && v[i][j-1]==0 && issafe(g,i,j-1)){

			res=min(res,count(g,v,i,j-1,c+1));
		}
	}
	v[i][j]=0;
	return res;
}
int main(){
	// cin>>n>>m;
	// cout<<1;
	int g[R][C],v[R][C];
	// cout<<'a';
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			cin>>g[i][j];
		}
	}
	// cout<<1;
	int res=INT_MAX;
	for(int i=0;i<R;i++){
		if(issafe(g,i,0)){
			memset(v,0,sizeof(v));
			res=min(res,count(g,v,i,0,0));
		}
	}
	cout<<res;
}