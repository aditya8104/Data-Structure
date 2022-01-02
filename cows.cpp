#include <bits/stdc++.h>
using namespace std;
int fun(int a[],int cf,int i,int n,int c,int l,int diff){
	if(cf==c-1){
		// cout<<a[i]-l<<" ";
		return min(diff,a[i]-l);
	}else{
		int res=0;
		for(int j=i;j<=n-c+cf;j++){
			if(cf==1){
				// cout<<l<<" ";
				res=max(res,fun(a,cf+1,j+1,n,c,a[j],a[j]-l));
			}else{
				int d=min(diff,a[j]-l);
				res=max(res,fun(a,cf+1,j+1,n,c,a[j],d));
			}
		}
		return res;
	}
}
int main(){
	int n,c;
	cin>>n>>c;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<fun(a,1,1,n,c,a[0],0);
}