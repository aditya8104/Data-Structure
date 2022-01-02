#include <bits/stdc++.h>
using namespace std;
bool check(string &t,string &p){
	unordered_map<char,int> m;
	bool ans=false;
	m['*']=p.size();
	for(int i=0;i<p.size();i++){
		if(i==p.size()-1){
			m[p[i]]=p.size();
		}else{
			m[p[i]]=p.size()-i-1;
		}
	}
	int i=p.size()-1;
	int st=0;
	while(i<t.size()){
		// cout<<st<<" "<<i;
		int j=p.size()-1,c=0;
		while(j>=0 && p[j]==t[i]){
			c++;i--;j--;
			// cout<<c<<" ";
			// if(c==p.size()){
			// 	break;
			// }
		}
		// cout<<st<<" "<<i<<" "<<c<<endl;
		if(c<p.size()){
			if(m.find(t[i])!=m.end()){
				// st++;
				st=st+m[t[i]];
				i=st+p.size()-1;
			}else{
				// st++;
				st=st+m['*'];
				i=st+p.size()-1;
			}
		}else{
			// cout<<1;
			cout<<i+1<<" "<<i+p.size();
			ans=true;
			break;
		}
	}
	// cout<<ans;
	return ans;
}
int main(){
	string txt,pttr;
	getline(cin,txt);
	getline(cin,pttr);
	// cout<<txt<<" "<<pttr;
	bool ans=check(txt,pttr);
	if(ans){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}