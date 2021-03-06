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

#define X                   first
#define Y                   second
#define pb(i) 				push_back(i)
#define mp(i,j) 			make_pair(i,j)
#define mod 				1000000007
#define F           		first
#define S           		second
#define endl        		'\n'
#define ll 					long long
#define point               pair<int,int>
//Prims algorithm for MST:--->O(ElogV)
//edges and vertices are negated becoz by default Priority Queue is maxHeap and we want it to act as minHeap.

map<point,int>dict;
map<int,point>rdict;
vector< vector<pair<double,int > > >L; //(ll weight,(int ToVertex,int parent_of_ToVertex))
vector< pair<double,int > >v;
int n,m,par[100005];
bool vis[100005];

double Prim(int Src=0){
	priority_queue<pair<double,pair<int,int>> >pq;
	for(auto u:L[Src])	pq.push({-u.F, {-u.S,Src} }),cout<<-u.F<<" "<<-u.S<<endl;
	double mstc=0;
	par[Src]=0;
	setfillstyle(EMPTY_FILL+1, GREEN);
    fillellipse(rdict[0].X,rdict[0].Y,5,5);
	vis[Src]=1;
	cout<<"HILLO\n";
	while(!pq.empty()){
        cout<<"BLLO\n";
		pair<double,pair<int,int> > Src=pq.top();	pq.pop();
		if(vis[-Src.S.F]==0){
			par[-Src.S.F]=Src.S.S;
			setcolor(GREEN);
            line(rdict[-Src.S.F].X,rdict[-Src.S.F].Y,rdict[Src.S.S].X,rdict[Src.S.S].Y);
			delay(1000);
			mstc=mstc-Src.F;//-because edge weight taken negative.
			vis[-Src.S.F]=1;
			setfillstyle(EMPTY_FILL+1, GREEN);
            fillellipse(rdict[-Src.S.F].X,rdict[-Src.S.F].Y,5,5);
		}
		for(auto u:L[-Src.S.F]){
			if(vis[u.S]==0){
				pq.push({-u.F,mp(-u.S,-Src.S.F)});
			}
		}
	}
	return mstc;
}

double dist(point a,point b){
    return fabs(a.X-b.X)+fabs(a.Y-b.Y);//return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}
double edist(point a,point b){
    return (a.X-b.X)*(a.X-b.X)+(a.Y-b.Y)*(a.Y-b.Y);
}

int main(){
    int gd=DETECT,gm;
    initwindow(450, 300);
    SetBkColor(WHITE);
    int x=getmaxx(),y=getmaxy();
    setcolor(RED);//setfillstyle(USER_FILL-1, GREEN);
    setfillstyle(EMPTY_FILL+1, GREEN);
    fillellipse(4*x/5,4*y/5,25,25);setcolor(RED);
    outtextxy (4*x/5-25,4*y/5-5,"SUBMIT POINTS");
    L.clear();
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
        //setfillstyle(EMPTY_FILL+1, BLUE);fillellipse(X,Y,5,5);


        if((X-4*x/5)*(X-4*x/5)+(Y-4*y/5)*(Y-4*y/5)<=625){
            setcolor(RED);//setfillstyle(USER_FILL-1, GREEN);
            setfillstyle(EMPTY_FILL+1, RED);
            delay(1000);
            fillellipse(4*x/5,4*y/5,20,20);setcolor(RED);
            break;
        }
        dict[mp(X,Y)]=i;
        rdict[i++]=mp(X,Y);
        A.push_back(mp(X,Y));
    }
    int n=A.size(),m=(n*n);
    for(int i=0;i<=n;i++){
		L.pb(v);
		vis[i]=0;
		par[i]=0;
	}
    /*for(int i=0;i<n;i++){
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
            L[b].push_back({w,a});
            L[a].push_back({w,b});
        }
    }*/
    while(1){
        while (!ismouseclick(WM_LBUTTONDOWN))
        {
            delay(10);
        }
        getmouseclick(WM_LBUTTONDOWN, X, Y);
        for(int i=0;i<n;i++){
            if(edist(A[i].X,A[i].Y,X,Y)<=25.00){

            }
        }
        setcolor(BLUE);
        //circle(X,Y,5);

        setfillstyle(EMPTY_FILL+1, BLUE);fillellipse(X,Y,5,5);


        if((X-4*x/5)*(X-4*x/5)+(Y-4*y/5)*(Y-4*y/5)<=625){
            setcolor(RED);//setfillstyle(USER_FILL-1, GREEN);
            setfillstyle(EMPTY_FILL+1, RED);
            delay(1000);
            fillellipse(4*x/5,4*y/5,20,20);setcolor(RED);
            break;
        }
        dict[mp(X,Y)]=i;
        rdict[i++]=mp(X,Y);
        A.push_back(mp(X,Y));
    }
    setfillstyle(EMPTY_FILL+1, GREEN);
    fillellipse(4*x/5-400,4*y/5,25,25);setcolor(RED);
    outtextxy (4*x/5-425,4*y/5-5,"SUBMIT EDGES");

	double mst_cost=Prim();
	cout<<endl<<mst_cost<<",MST:\n";
	for(int i=1;i<=n;i++){
		trace2(i,par[i]);
	}
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
