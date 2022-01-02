#include <bits/stdc++.h>
using namespace std;
#define N 3
void kary(int n,int k,int a[]){
	if(n==N){
		for(int i=0;i<N;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=k;i++){
		a[n]=i;
		kary(n+1,k,a);
		a[n]=0;
	}
}
int main(){
	int a[N]={0};
	kary(0,2,a);
	return 0;
}