#include<bits/stdc++.h>
using namespace std;
#define pb(i) 		push_back(i)
#define debug(a)    cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define mp(i,j) 	make_pair(i,j)
#define S second
#define F first
#define trace1(x)                cerr << #x << ": " << x << endl
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl

vector<vector<int> >L,Lt,SCC;//adjLise,Transepose of AdjList
vector<int>v,S,scc;//S-Stack
int n,m;
bool vis[100005];
/*See tushars video for explaination*/
void Kosaraju(int Src,int pass){//1st pass for topological sort Stack,2nd for SCC //actually DFS
	vis[Src]=1;
	vector<int>nbr=((pass==1)?L[Src]:Lt[Src]);
	if(pass==2){scc.pb(Src);}
	for(auto u:nbr){
		if(vis[u]==0){
			Kosaraju(u,pass);
		}
	}
	if(pass==1)S.pb(Src);
}

int main(){
    cout<<"Enter the no of vertices and the no. of Edges:\n";
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		L.pb(v);Lt.pb(v);
		vis[i]=0;
	}
	cout<<"Enter the Edges <a> <b>:";
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		L[a].push_back(b);Lt[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){Kosaraju(i,1);}
	}
	memset(vis,0,sizeof(vis));
	for(int i=n-1;i>=0;i--){
		if(vis[S[i]]==0){
			scc.clear();
			Kosaraju(S[i],2);
			SCC.pb(scc);
		}
	}
	cout<<"No of connected components are:"<<SCC.size()<<endl;
	for(auto j:SCC){
		debug(j);
	}
	return 0;
}
/*EXAMPLE:
11 13
1 3
3 2
2 1
4 3
6 4
4 5
5 6
5 7
7 8
8 9
9 10
10 7
10 11
*/
