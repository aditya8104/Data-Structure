// #include <bits/stdc++.h>
// using namespace std;
// int count(vector<vector<int> > &v,int hs,int he,int vs,int ve){
// 	int sum=0;
// 	if(he<=hs || ve<=vs){
// 		sum=0;
// 	}else if(he>hs && ve>vs){
// 		// int sum=0;
// 		// cout<<1;
// 		if((he-hs+1)%2!=0 && (ve-vs+1)%2!=0){
// 			int mid1=(he+hs)/2;
// 			int mid2=(ve+vs)/2;int c=0;
// 			for(int i=vs;i<=ve;i++){
// 				for(int j=hs;j<=he;j++){
// 					if((j==mid1 && v[i][mid1]!=1) || (i==mid2 && v[mid2][j]!=1)){
// 						c++;break;
// 					}
// 				}
// 			}
// 			if(c==0){
// 				cout<<hs<<" "<<he<<" "<<vs<<" "<<ve<<endl;
// 				sum=(he-hs+1)/2;
// 			}else{
// 				sum=count(v,hs+1,he,vs+1,ve)+count(v,hs,he-1,vs,ve-1)+count(v,hs+1,he,vs,ve-1)+count(v,hs,he-1,vs+1,ve);
// 			}
// 		}else if((he-hs+1)%2==0 && (ve-vs+1)%2==0){
// 			// cout<<1;
// 			sum=count(v,hs+1,he,vs+1,ve)+count(v,hs,he-1,vs,ve-1)+count(v,hs+1,he,vs,ve-1)+count(v,hs,he-1,vs+1,ve);
// 		}
		
// 	}
// 	return sum;
// }
// int main(){
// 	vector<vector<int> > v;
// 	int n;
// 	cin>>n;
// 	// cout<<1;
// 	for(int i=0;i<n;i++){
// 		vector<int> x;
// 		for(int j=0;j<n;j++){
// 			int c;cin>>c;x.push_back(c);
// 		}
// 		v.push_back(x);
// 	}
// 	cout<<count(v,0,n-1,0,n-1);
// }
#include<bits/stdc++.h>
using namespace std;

typedef long long int inti;

bool exists(vector<vector<int>> & mat,int row, int col, int subt){
    int n=mat.size();
    if(row-subt>=0 && col-subt>=0 && row+subt<n && col+subt<n){
        for(int i=col-subt;i<=col+subt;i++){
            if(i==col && mat[row-subt][i]==0)
                return false;
            if(i!=col && mat[row-subt][i]==1)
                return false;
            if(i==col && mat[row+subt][i]==0)
                return false;
            if(i!=col && mat[row+subt][i]==1)
                return false;

        }

        for(int i=row-subt;i<=row+subt;i++){
            if(i==row && mat[i][col+subt]==0)
                return false;
            if(i!=row && mat[i][col+subt]==1)
                return false;
            if(i==row && mat[i][col-subt]==0)
                return false;
            if(i!=row && mat[i][col-subt]==1)
                return false;
        }

        return true;
    }

    return false;

}

int count(vector<vector<int>> & mat){
    int n=mat.size();
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==1){
                int subt=1;
                while(exists(mat,i,j,subt)){
                    subt++;
                    ans++;
                }
            }
        }
    }

    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
    	vector<vector<int> > v;
		int n;
		cin>>n;
		// cout<<1;
		for(int i=0;i<n;i++){
			vector<int> x;
			for(int j=0;j<n;j++){
				int c;cin>>c;x.push_back(c);
			}
			v.push_back(x);
		}

    cout<<count(v)<<"\n";
    return 0;
}