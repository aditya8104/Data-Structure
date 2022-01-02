#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long int n,m;
	cin>>n>>m;
	long long int a[n];
	for(long long int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long int l=0,h=a[n-1],mid,res=0;
	while(l<=h){
		mid=(l+h)/2;
		long long int sum=0;
		for(long long int i=0;i<n;i++){
			if(a[i]>=mid){
				sum+=a[i]-mid;
			}
		}
		if(sum>=m){
			l=mid+1;
			res=mid;
		}else{
			h=mid-1;
		}
	}
	if(res==0){
		cout<<-1;
	}else{
		cout<<res;
	}
	
	return 0;
}