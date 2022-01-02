#include<bits/stdc++.h>
using namespace std;
#define r 2
#define c 2
vector<vector<int> > res;
void fun(int g[r][c],int i,int j,vector<int> t){
	if(i==r-1 && j==c-1){
		t.push_back(g[i][j]);
		res.push_back(t);
		t.pop_back();
		return;
	}
	t.push_back(g[i][j]);
	if(i<r-1){
		fun(g,i+1,j,t);
	}
	if(j<c-1){
		fun(g,i,j+1,t);
	}
	t.pop_back();
}
int main(){
	int g[r][c];
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>g[i][j];
		}
	}
	vector<int> t;
	fun(g,0,0,t);
	for(auto i:res){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}