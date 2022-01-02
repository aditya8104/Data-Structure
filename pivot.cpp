#include <bits/stdc++.h>
using namespace std;
int find(int a[],int l,int h,int n){
	// cout<<l<<" "<<h<<endl;
	if(l>h){
		// cout<<'a';
		return -1;
	}else if(l==h){
		// cout<<l<<" "<<h;
		if(l==0){
			// cout<<'b';
			if(a[l+1]<a[l] && a[l]>a[n]){
				return a[l];
			}else{
				return -1;
			}
		}else if(l==n){

			if(a[l]>a[l-1] && a[l]>a[0]){
				return a[l];
			}else{
				return -1;
			}
		}else{
			// cout<<'b';
			if(a[l]>a[l-1] && a[l]>a[l+1]){
				return a[l];
			}else{
				return -1;
			}
		}
	}else{
		int mid=(l+h)/2;
		// int ans;
		cout<<mid<<endl;
		if((mid-1>0 && a[mid]>a[mid-1]) && (mid+1<n && a[mid]>a[mid+1])){
			return a[mid];
		}
		if(a[mid-1]<a[l]){
			cout<<'a';
			return find(a,l,mid-1,n);
		}
		else if(a[mid+1]>a[h]){
			cout<<'3';
			return find(a,mid+1,h,n);
		}
		else{
			cout<<mid;
			if(a[0]<a[n]){
				return a[n];
			}else{
				return a[mid-1];
			}
		}
	}
}
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cout<<find(a,0,n-1,n-1);
}