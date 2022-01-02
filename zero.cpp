#include<bits/stdc++.h>
using namespace std;
int count(string &s,int n){
	if(n==0){
		if(s[n]=='1'){
			return 0;
		}else{
			return 1;
		}
	}
	int res;
	if(s[n]=='1'){
		res=max(0,count(s,n-1)-1);
	}else{
		res=max(count(s,n-1)+1,count(s,n-1));
		// cout<<res<<" ";
	}
	return res;
}
int main(){
	string s;
	cin>>s;
	int o=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='0'){
			o++;
		}
	}
	if(o==0){
		cout<<-1;
	}else{
		// cout<<l;
		cout<<count(s,s.size()-1);
	}
}