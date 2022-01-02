#include <bits/stdc++.h>
using namespace std;
bool check(int a[],int k,int n,int h){
    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]<=k){
            c++;
        }else{
            c+=(a[i]/k)+1;
        }
    }
    if(c<=h){
        return true;
    }
    return false;
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t){
	    int n,hr;
	    cin>>n>>hr;
	    // cout<<hr;
	    // cout<<0;
	    int a[]={1,2,3};
	    int l=0,h=a[n-1],mid;
	    cout<<l;
	    while(h-l>1){
	        mid=(l+h)/2;
	        // cout<<mid<<endl;
	        if(check(a,mid,n,hr)){
	            l=mid;
	        }else{
	            h=mid;
	        }
	    }
	    if(check(a,l,n,hr)){
	    	// cout<<1;
	        cout<<l<<endl;
	    }else{
	        cout<<h<<endl;
	    }
	    t--;
	}
	return 0;
}
