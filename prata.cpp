#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int p;
		cin>>p;
		int l;
		cin>>l;
		int a[l],mx=0;
		// cout<<l;
		for(int i=0;i<l;i++){
			cin>>a[i];
			// cout<<a[i];
			mx=max(mx,a[i]);
		}
		int h=mx*((p)*(p+1))/2;
		// cout<<h;
		int lo=0,mid,res;
		while(lo<=h){
			mid=(lo+h)/2;
			int cnt=0,sum=0;
			for(int i=0;i<l;i++){
				int x=a[i];int j=2;
				while(x<=mid){
					cnt++;
					x+=a[i]*j;
					j++;
				}
			}
			if(cnt>=p){
				// cout<<mid<<" "<<cnt<<endl;
				res=mid;
				h=mid-1;
			}else{
				// cout<<1;
				lo=mid+1;
				// cout<<cnt<<" ";
			}
		}
		cout<<res<<endl;
	}
	return 0;
}