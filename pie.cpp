#include<bits/stdc++.h>
using namespace std;
long double pi=3.14159265358979323846264338327950;
bool check(long double vol,int a[],int f,int n){
	if(vol==0){
		return false;
	}
	int c=0;
	for(int i=0;i<n;i++){
		long double x=pi*(a[i]*a[i])*1;
		c+=x/vol;
	}
	if(c>=f+1){
		return true;
	}
	return false;
}
int main(){
	long double esp=1e-6;
	int t;
	cin>>t;
	while(t--){
		int n,f;
		cin>>n>>f;
		int a[n],mx=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]>mx){
				mx=a[i];
			}
		}
		long double l=0,h=mx,mid,res;
		while(h-l>esp){
			mid=(l+h)/2;
			long double vol=pi*(mid*mid)*1;
			if(check(vol,a,f,n)){
				l=mid;
			}else{
				h=mid;
			}
		}
		long double vol2=pi*(l*l)*1;
		if(check(vol2,a,f,n)){

			cout<< fixed <<setprecision(4)<<vol2<<endl;
		}
		
	}
}