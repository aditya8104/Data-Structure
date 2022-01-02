#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int sum[n];sum[0]=a[0];
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int m;
	cin>>m;
	while(m--){
		int x;
		cin>>x;
		int l=0,h=n-1,mid,res;
		while(l<=h){
			mid=(l+h)/2;
			if(sum[mid]>=x){
				res=mid+1;
				h=mid-1;
			}else{
				l=mid+1;
			}
		}
		cout<<res<<endl;
	}

}