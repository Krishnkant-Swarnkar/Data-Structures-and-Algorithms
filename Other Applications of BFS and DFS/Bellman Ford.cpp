#include<bits/stdc++.h>
using namespace std;
#define pb(i) 		push_back(i)
#define debug(a)    cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define mp(i,j) 	make_pair(i,j)
#define S second
#define F first

vector<vector<pair<int,int>> >L;//int edgeToVertex,int EdgeWeight
vector<pair<int,int> >v;
vector<int>sp;
int n,m;

bool BellmanFord(int Src){
	sp[Src]=0;
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<L.size();j++){
			for(auto u :L[j]){
				sp[u.F]=min(sp[u.F],sp[j]+u.S);
			}
		}
	}
	for(int j=1;j<L.size();j++){
		for(auto u :L[j]){
			if(sp[u.F]>sp[j]+u.S){
				return 0;
			}
		}
	}
	return 1;
}


int main(){
    cout<<"Enter the no of vertices and the no. of Edges:\n";
    cin>>n>>m;
	for(int i=0;i<=n;i++){
		L.pb(v);
		sp.pb(INT_MAX);
	}
	cout<<"Enter the Edges <a> <b> <weight>:";
	for(int i=0;i<m;i++){
		int a,b,w;
		cin>>a>>b>>w;
		L[a].push_back( {b,w} );
		L[b].push_back( {a,w} );
	}
	cout<<"Enter the source:";
	int Source;
	cin>>Source;
	bool b=BellmanFord(Source);
	if(b){
		cout<<"Successfull Bellman Ford, shortest distances:\n";
		for(int i=1;i<=n;i++){
			cout<<i<<" "<<sp[i]<<endl;
		}
	}
	else
		cout<<"Negative Edge Cycles";
	return 0;
}
