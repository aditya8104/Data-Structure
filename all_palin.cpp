#include<bits/stdc++.h>
using namespace std;
vector<vector<string> > v;
bool ispalin(string s,int i,int j){
	bool res=true;
	while(i<j){
		if(s[i]!=s[j]){
			res=false;break;
		}
		i++;j--;
	}
	return res;
}
// int t[1001][1001];
void fun(string s,int i,vector<string> curr){
	if(i==s.size()){
		v.push_back(curr);
		return;
	}
	// if(ispalin(s,i,j)){
	// 	if(t[i][j]!=-1){
	// 		return ;
	// 	}
	// 	for(int x=i;x<=j;x++){
	// 		cout<<s[x];
	// 	}
	// 	cout<<endl;
	// 	t[i][j]=1;
	// }
	for(int k=i;k<s.size();k++){
		if(ispalin(s,i,k)){
			curr.push_back(s.substr(i, k-i+1));
			fun(s,k+1,curr);
			curr.pop_back();
		}
	}
}
int main(){
	string s;
	cin>>s;
	// memset(t,-1,sizeof(t));
	vector<string> curr;
	fun(s,0,curr);
	for(auto i:v){
		for(auto j:i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
}