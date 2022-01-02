#include <bits/stdc++.h>
using namespace std;
bool find(int k,vector<int> &v){
	int l=0,h=v.size()-1,mid;
	bool res=false;
	while(l<=h){
		mid=(l+h)/2;
		if(v[mid]>k){
			h=mid-1;
		}else if(v[mid]<k){
			l=mid+1;
		}else{
			res=true;break;
		}
	}
	return res;
}

int main() {
	// your code goes here
	while(true){
		int n,m;
		cin>>n;
		if(n>0){
			vector<int> a;
			for(int i=0;i<n;i++){
				int x;cin>>x;
				a.push_back(x);
			}
			cin>>m;
			vector<int> b;
			for(int i=0;i<m;i++){
				int x;cin>>x;
				b.push_back(x);
			}
			int i=0,j=0,sa=0,sb=0,sf=0;
			while(i<n && j<m){
				if(find(a[i],b) && find(b[j],a)){
					// cout<<i<<" "<<j<<endl;
					sb+=b[j];j++;
					sa+=a[i];i++;
					sf+=max(sa,sb);
					// cout<<i<<" "<<j<<endl;
					sa=0;sb=0;
				}else if(!find(a[i],b) && find(b[j],a)){
					// cout<<i<<" "<<j<<endl;
					sa+=a[i];i++;
				}else if(find(a[i],b) && !find(b[j],a)){
					// cout<<i<<" "<<j<<endl;
					sb+=b[j];j++;
				}else{
					// cout<<i<<" "<<j<<endl;
					sa+=a[i];i++;
					sb+=b[j];j++;
				}
			}
			if(i<n && j>=m){
				// cout<<1;
				while(i<n){
					sa+=a[i];i++;
				}
				sf+=max(sb,sa);
			}
			else if(j<m && i>=n){
				// cout<<2;
				while(j<m){
					sb+=b[j];j++;
				}
				sf+=max(sb,sa);
			}else if(i>=n && j>=m){
				// cout<<3;
				// cout<<sb<<" "<<sa<<" "<<sf;
				sf+=max(sb,sa);
			}
			cout<<sf<<endl;
		}else{
			break;
		}
	}
	return 0;
}