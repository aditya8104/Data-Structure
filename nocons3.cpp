#include<bits/stdc++.h>
using namespace std;
int maxs(int a[],int n,int i){
	if(n==0){
		return 0;
	}
	int res;
	if(i!=3){
		res=max(a[n-1]+maxs(a,n-1,i+1),maxs(a,n-1,1));
	}else{
		res=maxs(a,n-1,1);
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<maxs(a,n,1);
}