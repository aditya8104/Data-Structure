#include <bits/stdc++.h>
using namespace std;
#define R 5
#define C 5
bool isval(vector<vector<int> > &v,int i,int j){
	if(i<0 || i>=R || j<0 || j>=C || v[i][j]==0 || v[i][j]==-1){
		return false;
	}
	return true;
}
int fun(vector<vector<int> > &v,int i,int j){
	v[i][j]=-1;
	int res=1;
	int a=0;
	int d[][2]={{-1,0},{1,0},{-1,-1},{1,1},{0,1},{0,-1},{1,-1},{-1,1}};
	for(int x=0;x<8;x++){
		int ni=d[x][0]+i;
		int nj=d[x][1]+j;
		if(isval(v,ni,nj)){
			a=max(a,fun(v,ni,nj));
		}
	}
	v[i][j]=1;
	return res+a;
}
int main(){
	vector<vector<int> > v;
	for(int i=0;i<R;i++){
		vector<int> t;
		for(int j=0;j<C;j++){
			int c;
			cin>>c;
			t.push_back(c);
		}
		v.push_back(t);
	}
	int res=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(v[i][j]==1){
				res=max(res,fun(v,i,j));
			}
		}
	}
	cout<<res;
}