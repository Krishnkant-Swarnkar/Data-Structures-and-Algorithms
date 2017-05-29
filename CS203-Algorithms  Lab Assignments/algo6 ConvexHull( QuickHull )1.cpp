#include<bits/stdc++.h>
#include<graphics.h>
#include<conio.h>
using namespace std;
#define X           			first
#define Y           			second
#define point 					pair<int,int>
#define trace1(x)               cerr << #x << ": " << x << endl;
#define trace2(x, y)            cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)         cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)      cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)   cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f)cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

int n;
point *P,Z;
vector<point> C_HULL;

bool cmp(point A, point B)
{
    return (A.Y-Z.Y)*(B.X-Z.X)<(B.Y-Z.Y)*(A.X-Z.X);
}

float area(point A,point B,point C){
	return ( (float)(A.X)*( (float)B.Y - (float)C.Y ) + (float)(B.X)*( (float)C.Y - (float)A.Y ) + (float)(C.X)*( (float)A.Y - (float)B.Y ) );
}

void hull(point A,point B,int sign){
	float H,mH=INT_MIN;
	int idx=0;
	for(int i=0;i<n;i++){
		H=( area(A,B,P[i]) * (float)sign );
		if(H>mH){
			mH = H;
			idx=i;
		}
	}
	if(mH<=0.0){	return ;}
	point C=P[idx];
	C_HULL.push_back(C);
	if(area(A,C,B)>0){	sign=-1;	}else{	sign=+1;	}
	hull(A,C,sign);
	hull(B,C,sign*(-1));
}

main(){
    cout<<"Enter the no. of points:";
	cin>>n;
	while(n<=0){
		cout<<"\nPlease enter a valid number of points:";
		cin>>n;
	}
	P=new point[n+2];
	cout<<"Enter the points <a> <b> without any angular brackets:\n";
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		P[i].X=a,P[i].Y=b;
	}
	sort(P,P+n);
	C_HULL.push_back(P[0]);
	Z=P[0];
	C_HULL.push_back(P[n-1]);
	hull(P[0],P[n-1],+1);
	hull(P[0],P[n-1],-1);
	sort(C_HULL.begin(),C_HULL.end(),cmp);
	int lx=C_HULL[n-1].X,ly=C_HULL[n-1].Y;



	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int x = getmaxx(),y = getmaxy();

    //line(0,0,x,y);
    //putpixel(5,5,BLUE);
    for(int i=0;i<n;i++){
		putpixel(P[i].X*(x/10),y-(P[i].Y)*(x/10),WHITE);
	}
	setcolor(BLACK);
	for(vector<point>::iterator it=C_HULL.begin();it!=C_HULL.end();it++){
		point i=(*it);
		cout<<i.X<<" "<<i.Y<<endl;
		line(lx*(x/10),y-(ly)*(x/10),i.X*(x/10),y-(i.Y)*(x/10));
        setcolor(BLUE);
        delay(1000);
		lx=i.X,ly=i.Y;
	}
	line(lx*(x/10),y-(ly)*(x/10),C_HULL[0].X*(x/10),y-(C_HULL[0].Y)*(x/10));

	for(int i=0;i<n;i++){
		putpixel(P[i].X*(x/10),y-(P[i].Y)*(x/10),WHITE);
	}

	getch();
	getch();
    closegraph();
    return 0;
}
//-lbgi -lgdi32 -luser32
//Testcases
/*
5
1 1
3 2
2 3
2 4
0 2
*/

/*21
1 1
1 2
3 1
4 1
5 1
2 2
3 2
4 2
5 2
6 2
3 3
4 3
6 3
1 4
2 4
3 4
4 4
5 4
6 4
3 5
4 5
*/
