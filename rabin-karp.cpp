#include <bits/stdc++.h>
using namespace std;
bool rk(string &t,string &p,int max){
	long long int sum=0;
	for(int i=0;i<p.size();i++){
		sum=sum*max;
		sum+=p[i]-' ';
	}
	long long int mul=pow(max,p.size()-1)+1;
	cout<<mul<<endl;
	cout<<sum<<endl;
	long long int s2=0;
	int len=0,st=0;bool ans=false;
	for(int i=0;i<t.size();i++){
		if(len<p.size()){
			cout<<s2<<" ";
			s2=s2*max;
			cout<<s2<<" ";
			s2+=t[i]-' ';
			cout<<t[i]-' '<<" ";
			len++;
			// cout<<s2<<endl;
		}
		if(len==p.size()){
			// cout<<s2<<endl;
			if(s2==sum){
				ans=true;
				break;
			}else{
				// cout<<s2<<" ";
				// cout<<t[st]<<" "<<t[i]<<endl;
				int x=t[st]-' ';
				cout<<x<<" "<<mul<<" ";
				x=x*mul;

				s2-=x;
				cout<<s2<<" "<<x<<" ";
				st++;
				len--;
			}
		}cout<<endl;
	}
	return ans;
}
int main(){
	string txt,pttr;
	getline(cin,txt);
	// cin.ignore();
	getline(cin,pttr);
	// cout<<txt;
	int mx=0;
	for(int i=0;i<txt.size();i++){
		mx=max(mx,int(txt[i])-' ');
	}

	for(int i=0;i<pttr.size();i++){
		mx=max(mx,int(pttr[i])-' ');
	}
	bool ans=rk(txt,pttr,mx);
	if(ans){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}