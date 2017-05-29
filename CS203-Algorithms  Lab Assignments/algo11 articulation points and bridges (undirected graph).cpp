#include<bits/stdc++.h>
using namespace std;
#define pb(i) 		push_back(i)
#define debug(a)    cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define mp(i,j) 	make_pair(i,j)
#define S second
#define F first
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

vector<vector<int> >L;
vector<int>v,low_t,vis_t;
vector<pair<int,int> >B;
bool AP[100005];
int n,m,Time=0,root,rootchild=0,par[100005];
/*
articulation point:a point which when removed from a connected graph along with its edges, it makes the graph disconnected.
Bridge:an edge which when removed from a connected graph, it makes the graph disconnected.
*/
void APnB(int S=1){//Articulation points and Bridges(actually modified dfs)
	vis_t[S]=low_t[S]=Time++;
	for(auto u: L[S]){
		if(vis_t[u]==-1){//unvisited
			par[u]=S;
			if(S==root)rootchild++;
			APnB(u);
			if(vis_t[S]<=low_t[u] && S!=root)AP[S]=1;
			if(vis_t[S]<low_t[u])B.push_back( {S,u} );
			low_t[S]=min(low_t[S],low_t[u]);
		}
		else if(u!=par[S]) {// do not update low_time S , if u is the direct parent of S
			low_t[S]=min(low_t[S],vis_t[u]);
		}
	}
}

int main(){

	L.clear();vis_t.clear();low_t.clear();
	cout<<"Enter no of Vertices and no of Edges:";
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		L.pb(v);
		vis_t.pb(-1);
		low_t.pb(-1);
		par[i]=-1;AP[i]=0;
	}
	par[1]=0;
	cout<<"Enter Edges <a> <b>:\n"
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		L[a].push_back(b);
		L[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(vis_t[i]==-1){
			root=i,rootchild=0;//independent children
			APnB(i);
			AP[root]=(rootchild>1);
		}
	}
	cout<<"Articulation Points:";
	for(int i=1;i<=n;i++){
		if(AP[i])cout<<i<<" ";
	}
	cout<<"\nBridges:\n";
	for(int i=0;i<B.size();i++){
		cout<<B[i].F<<" "<<B[i].S<<endl;
	}
	return 0;
}
/*EXAMPLE:
8 10
1 2
1 8
8 7
8 5
7 5
2 4
2 3
3 4
4 5
5 6
*/
