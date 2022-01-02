#include<bits/stdc++.h>
using namespace std;
int partition(string &s,int l,int r){
	char p=s[r];
	int i=l-1;
	for(int j=l;j<r;j++){
		if(s[j]<p){
			i++;
			if(j!=i){
				char x=s[i];
				s[i]=s[j];
				s[j]=x;
			}
		}
	}
	char x=s[i+1];
	s[i+1]=s[r];
	s[r]=x;
	return i+1;
}
void sort(string &s,int l,int r){
	// cout<<1;
	if(l<r){
		// cout<<l;
		int j=partition(s,l,r);
		sort(s,l,j-1);
		sort(s,j+1,r);
	}
}
int main(){
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	sort(s1,0,s1.size()-1);
	sort(s2,0,s2.size()-1);
	sort(s3,0,s3.size()-1);
	// cout<<s1<<s2<<s3;
	if(s3.size()!=s1.size()+s2.size()){
		cout<<"No";
	}else{
		int j=0,c=0;
		for(int i=0;i<s3.size();i++){
			if(s3[i]==s1[j]){
				c++;
				j++;
			}
		}
		j=0;
		for(int i=0;i<s3.size();i++){
			if(s3[i]==s2[j]){
				c++;
				j++;
			}
		}
		if(c==s1.size()+s2.size()){
			cout<<"YES";
		}else{
			cout<<"No";
		}
	}
}