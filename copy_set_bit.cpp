#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	int l,r;
	cin>>l>>r;
	int msk=1<<(r-l+1)-1;
	msk=msk<<l-1;
	msk=msk&y;
	x=x|msk;
	cout<<x;
}