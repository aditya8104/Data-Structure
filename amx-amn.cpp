#include<bits/stdc++.h>
using namespace std;
int count(int a[],int n,int k,int i){
	if(i==1){
		return INT_MAX;
	}
	int res=INT_MAX,c=INT_MAX,l;
	for(int j=0;j<n;j++){
		if(a[i-1]-a[j]<=k){
			if(c>a[j]){
				l=j;
				c=a[j];
			}
		}
	}
	if(c!=INT_MAX){
		res=0;
		for(int j=0;j<n;j++){
			if(a[j]>a[i-1] || a[j]<a[l]){
				res++;
			}
		}
	}
	res=min(res,count(a,n,k,i-1));
	return res;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int k;
	cin>>k;
	cout<<count(a,n,k,n);
}