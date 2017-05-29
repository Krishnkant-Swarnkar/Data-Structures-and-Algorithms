#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
#define debug(a)    			cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define show1(a,n) 				cout<<endl;for(int i=0;i<n;i++){cout<<a[i]<<" ";}
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
#define F           		first
#define S           		second
#define X           		first
#define Y           		second
#define endl        		'\n'
#define ll 					long long
#define point               pair<int,int>
//Kruskals algorithm for MST:--->O(ElogV)
vector< vector<pair<ll,int > > >L; //(ll weight,(int ToVertex,int parent_of_ToVertex))
vector< pair<ll,int > >v;
vector< pair<ll,pair<int,int> > >E;
int n,m,par[100005];
map<point,int>dict;
map<int,point>rdict;

class DISJ{
	vector<int> rank, parent;
	int SIZE;
public:
	DISJ(int N) :SIZE(N), rank(N, 0), parent(N)
	{
		for (int i = 0; i<N; i++)
			parent[i] = i, rank[i] = 0;
	}
	int find_set(int x)
	{
		if (parent[x] == x)    // root node check
			return x;
		parent[x] = find_set(parent[x]); // path compression
		return parent[x];
	}
	void link(int x, int y)
	{
		if (rank[x] == rank[y])
		{
			rank[x]++;
			parent[y] = x;
			return;
		}
		if (rank[x]<rank[y])
			parent[x] = y;
		else
			parent[y] = x;
	}
	void unite(int x, int y)
	{
		x = find_set(x);
		y = find_set(y);
		if (x != y)
			link(x, y);
	}
	bool same_set(int x, int y)
	{
		return (find_set(x) == find_set(y));
	}
};

ll Kruskal(int Src=0){
	double mstc=0;
	DISJ D(n+1);
	vector<pair<int,int > >MST;
	cout<<"HELLO\n";
	sort(E.begin(),E.end());
	for(auto u:E){
        //cout<<"BELLO\n";
		double w=u.F;
		int a=u.S.F,b=u.S.S;
		if(!D.same_set(a,b)){
            //cout<<"BLO\n";
			mstc=mstc+w;
			setcolor(GREEN);
            line(rdict[a].X,rdict[a].Y,rdict[b].X,rdict[b].Y);
			D.unite(a,b);MST.pb(mp(a,b));
			setfillstyle(EMPTY_FILL+1, GREEN);
            fillellipse(rdict[b].X,rdict[b].Y,5,5);fillellipse(rdict[a].X,rdict[a].Y,5,5);
            delay(500);
		}
	}
	cout<<endl<<mstc<<",MST:\n";
	for(auto u:MST){
		cout<<u.F<<" "<<u.S<<endl;
	}
	return mstc;
}

double dist(point a,point b){
    return fabs(a.X-b.X)+fabs(a.Y-b.Y);//return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}

int main(){
    int gd=DETECT,gm;
    //initwindow(1450, 1000);
    initgraph(&gd,&gm,"");
    int x=getmaxx(),y=getmaxy();
    setbkcolor(WHITE);
    setcolor(RED);//setfillstyle(USER_FILL-1, GREEN);
    setfillstyle(EMPTY_FILL+1, GREEN);
    fillellipse(4*x/5,4*y/5,25,25);setcolor(RED);
    outtextxy (4*x/5-25,4*y/5-5,"SUBMIT");
    vector<point>A;
    int X,Y,i=0;
    while(1){
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(10);
        }
        getmouseclick(WM_LBUTTONDOWN, X, Y);
        setcolor(BLUE);
        circle(X,Y,5);
        if((X-4*x/5)*(X-4*x/5)+(Y-4*y/5)*(Y-4*y/5)<=625){
            setcolor(RED);//setfillstyle(USER_FILL-1, GREEN);
            setfillstyle(EMPTY_FILL+1, RED);
            delay(500);
            fillellipse(4*x/5,4*y/5,20,20);setcolor(RED);
            break;
        }
        dict[mp(X,Y)]=i;
        rdict[i++]=mp(X,Y);
        A.push_back(mp(X,Y));
    }
    L.clear();
    n=A.size();
	for(int i=0;i<=n;i++){
		L.pb(v);
		par[i]=0;
	}
    for(int i=0;i<n;i++){
        int a=dict[A[i]],b;
        double w;
        for(int j=0;j<n;j++){
            if(i==j)continue;
            setcolor(RED);
            line(A[i].X,A[i].Y,A[j].X,A[j].Y);
            b=dict[A[j]];
            w=dist(A[i],A[j]);
            trace2(a,b);
            cout<<"Edge:"<<A[i].X<<","<<A[i].Y<<" -- "<<A[j].X<<","<<A[j].Y<<"weight:"<<w<<endl;
            E.push_back({w,{a,b}});
            L[b].push_back({w,a});
            L[a].push_back({w,b});
        }
    }
	ll mst_cost=Kruskal();
    getch();
    closegraph();
    return 0;
}
/*
8 10
1 2 7
1 3 15
1 7 10
7 8 3
8 6 14
7 6 8
6 2 5
6 5 6
5 2 12
2 4 9
*/
