#include<bits/stdc++.h>
using namespace std;
#define pb(i) 		push_back(i)
#define debug(a)    cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define mp(i,j) 	make_pair(i,j)
#define S second
#define F first
/*
	Euler tour / Euler cycle / Euler circuit

NOTE : This code is for Eulerin graphs (Graphs having euler path or euler cycle) only.
PREREQUISITES : A graph must be connected and all its vertices should have even degree.
HINT : Code for Euler Tour/cycle is a modified version of DFS.

*/
vector<vector<pair<int,bool> > >L;//int edgeToVertex,bool isEdgeVisited
vector<int>tour;
vector<pair<int,bool> >v;
int n,m;

void EulerTour(int idx,int Src){//index,start
	for(int i=0;i<L[Src].size();i++){
		if(!L[Src][i].S){//if edge not visited
			L[Src][i].S=1;
			for(int j=0;j<L[ L[Src][i].F ].size();j++){ //mark the reverse Edge visited
				if(    L[ L[Src][i].F ][j].F==Src &&     ! L[ L[Src][i].F ][j].S){
					L[ L[Src][i].F ][j].S=1;
					break;
				}
			}
			tour.insert(tour.begin()+idx,L[Src][i].F);
			EulerTour(idx+1,L[Src][i].F);
		}
	}
}

int main(){
	cout<<"Enter the no of vertices and the no. of Edges:\n";
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		L.pb(v);
	}
	cout<<"Enter the Edges <a> <b>:";
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		L[a].push_back( {b,0} );
		L[b].push_back( {a,0} );
	}
	cout<<"Enter Source:";
	int Source;
	cin>>Source;
	tour.pb(Source);
	EulerTour(1,1);
	cout<<"\nEuler Cycle:";
	debug(tour);
	return 0;
}
/*
EXAMPLE:
12 18
1 2
1 3
1 5
1 4
3 4
2 5
4 6
5 6
4 7
5 8
7 9
6 9
6 10
8 10
9 11
9 12
10 11
10 12
1
*/
