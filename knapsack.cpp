#include <bits/stdc++.h>
using namespace std;
int count(int a[],int n,int k){
	if(k<=1){
		return 0;
	}
	if(n==0){
		return 1;
	}
	int res;
	if(a[n-1]<=k){
		res=count(a,n-1,k/a[n-1])+count(a,n-1,k);
	}else{
		res=count(a,n-1,k);
	}
	return res;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	int k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	cin>>k;
	cout<<count(a,n,k);
	return 0;
}