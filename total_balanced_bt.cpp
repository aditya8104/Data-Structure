#include <bits/stdc++.h>
using namespace std;

//#include "solution.h"
int fun(int i,int s,int x){
    if(i==0){
        return 1;
    }
    if(x>=s){
        return 0;
    }
    int res=fun(i-1,s,x+1)+fun(i,s,x+1);
    return res;
}
int balancedBTs(int n) {
    // Write your code here
    int s=pow(2,n-1);
    int res=0;
    for(int i=1;i<=s;i++){
        res+=fun(i,s,0);
        cout<<res<<" "<<i<<endl;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
