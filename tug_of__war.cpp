#include <bits/stdc++.h>
using namespace std;
int dif=INT_MAX;
void check(int a[],bool el[],int sum,int currsum,int n,int j,int ttl,bool sol[]){
	if(j==0){
		return;
	}
	if((n/2-ttl)>j){
		return;
	}
	check(a,el,sum,currsum,n,j-1,ttl,sol);
	el[j-1]=true;
	ttl++;
	currsum=currsum+a[j-1];
	if(ttl==n/2){
		if(dif>abs(sum/2-currsum)){
			dif=abs(sum/2-currsum);
			for(int i=0;i<n;i++){
				sol[i]=el[i];
			}
		}
	}else{
		check(a,el,sum,currsum,n,j-1,ttl,sol);
	}
	el[j-1]=false;
}
int main(){
	int n;
	cin>>n;
	int a[n];
	int s=0;
	int mn=INT_MAX;
	for(int i=0;i<n;i++){
		cin>>a[i];
		// if(a[i]>0){
			s+=a[i];
		// }
		// mn=min(mn,a[i])
	}
	bool el[n];
	memset(el,false,sizeof(el));
	bool sol[n];
	memset(sol,false,sizeof(sol));
	check(a,el,s,0,n,n,0,sol);
	for(int i=0;i<n;i++){
		if(sol[i]){
			cout<<a[i]<<" ";
		}
	}cout<<endl;
	for(int i=0;i<n;i++){
		if(!sol[i]){
			cout<<a[i]<<" ";
		}
	}
}