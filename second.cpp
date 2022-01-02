#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	string s3;
	s3 += s2+s2;
	int i=1,c=0;
	while(i<s3.size()-s1.size()-1){
		c=0;
		for(int j=i;j<i+s1.size();j++){
			if(s3[j]!=s1[j-i]){
				c++;
				break;
			}
		}
		if(c==0){
			cout<<"Yes";
			break;
		}
		i++;
	}
	if(c>0){
		cout<<"No";
	}
}