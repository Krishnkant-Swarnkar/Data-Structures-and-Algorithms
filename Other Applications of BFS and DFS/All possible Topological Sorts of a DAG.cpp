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

//finding all possible topological sorts of a given DAG.
//this program makes use of Kahn's algorithm for Topological sort

vector<vector<int> >L,ANS;
vector<int>v,R;
int n,m,indegree[100005];
bool vis[100005];

void allTopoSorts(vector<int>res){//all topological sorts of a DAG
	bool flag=0;//flag->all are visited,now you can append res to ANS
	for(int i=1;i<=n;i++){
		if(indegree[i]==0 && vis[i]==0){
			vis[i]=1;
			for(auto u:L[i]){
				indegree[u]--;
			}
			res.pb(i);
			allTopoSorts(res);

			vis[i]=0;
			res.erase(res.end()-1);
			for(auto u:L[i]){
				indegree[u]++;
			}
			flag=1;
		}
	}
	if(!flag){
		ANS.pb(res);
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cout<<"Enter the no of vertices and the no. of Edges:\n";
    cin>>n>>m;
	for(int i=0;i<=n;i++){
		L.pb(v);
		vis[i]=0;indegree[i]=0;
	}
	cout<<"Enter the Edges <a> <b>:";
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		L[a].push_back(b);
		indegree[b]++;
	}
	allTopoSorts(R);
	cout<<"\nAll possible Topological Sorts are:\n";
	for(auto u:ANS){
		debug(u);
	}
    return 0;
}


