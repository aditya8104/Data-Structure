#include<bits/stdc++.h>
using namespace std;
int ttl(vector<vector<int> > &a,int i,int j1,int j2,int m,int n){
	if(i<0 || j1<0 || j2<0 || i>m-1 || j1>n-1 || j2>n-1){
		return INT_MIN;
	}
	if(i==m-1){
		if(j1==0 && j2==n-1){
			cout<<j1<<" "<<j2<<" ";
			cout<<a[i][j1]+a[i][j2]<<endl;
			return a[i][j1]+a[i][j2];
		}else{
			return INT_MIN;
		}
	}else{
		int sum=INT_MIN;
		int x=a[i][j1];
		a[i][j1]=0;
		int y=a[i][j2];
		a[i][j2]=0;
		sum=max(sum,ttl(a,i+1,j1-1,j2-1,m,n));
		sum=max(sum,ttl(a,i+1,j1-1,j2,m,n));
		sum=max(sum,ttl(a,i+1,j1-1,j2+1,m,n));
		sum=max(sum,ttl(a,i+1,j1,j2-1,m,n));
		sum=max(sum,ttl(a,i+1,j1,j2,m,n));
		sum=max(sum,ttl(a,i+1,j1,j2+1,m,n));
		sum=max(sum,ttl(a,i+1,j1+1,j2-1,m,n));
		sum=max(sum,ttl(a,i+1,j1+1,j2,m,n));
		sum=max(sum,ttl(a,i+1,j1+1,j2+1,m,n));
		if(j1==j2){
			a[i][j1]=x;
			a[i][j2]=x;
		}else{
			a[i][j1]=x;
			a[i][j2]=y;
		}
		if(sum>0){
			if(j1==j2){
				sum+=x;
			}else{
				sum+=x+y;
			}
		}else{
			sum=INT_MIN;
		}
		cout<<sum<<endl;
		return sum;
	}
}
int getcoin(vector<vector<int> > &v,int m,int n){
	return ttl(v,0,0,n-1,m,n);
}
int main(){
	vector<vector<int> > v;
	int m,n;
	cin>>m>>n;
	for(int i=0;i<m;i++){
		vector<int> a;
		for(int j=0;j<n;j++){
			int x;
			cin>>x;
			a.push_back(x);
		}
		v.push_back(a);
	}
	cout<<getcoin(v,m,n);
}