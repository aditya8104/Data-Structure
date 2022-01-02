#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int n){
    int res=0,l=0,r=0;
    for(int i=0;i<n;i++){
        int j=i,k=i,sumf=0,sumh=0;
        while(j<n){
            sumf=sumf+a[j];
            j++;
            sumf=sumf+a[j];
            sumh=sumh+a[k];
            if(sumf%2==0){
                if(sumf/2==sumh){
                    res=max(res,j-i+1);
                    l=i;r=j;
                }
            }
            j++;k++;
        }
    }
    cout<<a[l]<<" "<<a[r];
    return res;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<solve(a,n);
}