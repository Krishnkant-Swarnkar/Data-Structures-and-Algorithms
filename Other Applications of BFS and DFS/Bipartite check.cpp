#include<bits/stdc++.h>
using namespace std;
#define debug(a)    			cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define show1(a,n) 			cout<<endl;for(int i=0;i<n;i++){cout<<a[i]<<" ";}
#define show2(a,n,m) 			cout<<endl;for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<" ";}cout<<endl;}

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#define pb(i) 				push_back(i)
#define mp(i,j) 			make_pair(i,j)
#define mod 				1000000007
#define F           			first
#define S           			second
#define endl        			'\n'
#define ll 				long long

//checking that a graph is bipartite or not using BFS.

vector<vector<int> >L,ANS;
vector<int>v,R;
int n,m,col[100005];

bool isBipartite(int S=1){
	queue<int>Q;
	Q.push(S);
	int c=1;
	col[S]=c;
	while(!Q.empty()){
		S=Q.front();Q.pop();
		for(auto u:L[S]){
			if(col[u]==0){
				col[u]=3-col[S];
				Q.push(u);
			}
			else if(col[u]==col[S]){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout<<"Enter the no of vertices and the no. of Edges:\n";
    L.clear();
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		L.pb(v);
		col[i]=0;
	}
	cout<<"Enter the Edges <a> <b>:";
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		L[a].push_back(b);
	}
	bool b=isBipartite();
	if(b)cout<<"BICOLORABLE."<<endl;
	else cout<<"NOT BICOLORABLE."<<endl;

    return 0;
}


