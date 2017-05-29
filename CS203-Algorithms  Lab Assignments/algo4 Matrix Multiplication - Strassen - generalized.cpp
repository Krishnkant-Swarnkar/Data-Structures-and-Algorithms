#include<bits/stdc++.h>
using namespace std;
#define debug(a)    			cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define show1(a,n) 			cout<<endl;for(int i=0;i<n;i++){cout<<a[i]<<" ";}
#define show2(a,n,m) 			cerr<<#a<<":"<<endl;for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<" ";}cout<<endl;}
vector<vector<int> > add(vector<vector<int> >A,vector<vector<int> >B,int n){
	vector<vector<int> > C(n+1,vector<int>(n+1));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			C[i][j]=A[i][j]+B[i][j];
		}
	}
	return C;
}

vector<vector<int> > sub(vector<vector<int> >A,vector<vector<int> >B,int n){
	vector<vector<int> > C(n+1,vector<int>(n+1));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			C[i][j]=A[i][j]-B[i][j];
		}
	}
	return C;
}

vector<vector<int> > mul(vector<vector<int> >A,vector<vector<int> >B,int n){
	vector<vector<int> >C(n+1,vector<int>(n+1));
	if(n==1){
		C[0][0]=A[0][0]*B[0][0];//cout<<"returned : n = "<<n;show2(C,n,n);
		return C;
	}
	vector<vector<int> > a(n/2+1,vector<int>(n/2+1)), b(n/2+1,vector<int>(n/2+1)), c(n/2+1,vector<int>(n/2+1)), d(n/2+1,vector<int>(n/2+1));vector<vector<int> > e(n/2+1,vector<int>(n/2+1)), f(n/2+1,vector<int>(n/2+1)), g(n/2+1,vector<int>(n/2+1)), h(n/2+1,vector<int>(n/2+1));vector<vector<int> > P1(n/2+1,vector<int>(n/2+1)), P2(n/2+1,vector<int>(n/2+1)), P3(n/2+1,vector<int>(n/2+1)), P4(n/2+1,vector<int>(n/2+1));vector<vector<int> > P5(n/2+1,vector<int>(n/2+1)), P6(n/2+1,vector<int>(n/2+1)), P7(n/2+1,vector<int>(n/2+1));
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			a[i][j]=A[i][j];			e[i][j]=B[i][j];
			b[i][j]=A[i][j+n/2];		f[i][j]=B[i][j+n/2];
			c[i][j]=A[i+n/2][j];		g[i][j]=B[i+n/2][j];
			d[i][j]=A[i+n/2][j+n/2];	h[i][j]=B[i+n/2][j+n/2];
		}
	}
	//cout<<"******Jumping for P1***\n";
	P1=mul(a,			sub(f,h,n/2),n/2);//a(f-h)		
	P2=mul(add(a,b,n/2),h,			n/2);//(a+b)h		
	P3=mul(add(c,d,n/2),e,			n/2);//(c+d)e		
	P4=mul(d,			sub(g,e,n/2),n/2);//d(g-e)		
	P5=mul(add(a,d,n/2),add(e,h,n/2),n/2);//(a+d)(e+h)	
	P6=mul(sub(b,d,n/2),add(g,h,n/2),n/2);//(b-d)(g+h)
	P7=mul(sub(a,c,n/2),add(e,f,n/2),n/2);//(a-c)(e+f)
	for(int i=0;i<n/2;i++){
		for(int j=0;j<n/2;j++){
			C[i][j]   =			P4[i][j]+	P5[i][j]+	P6[i][j]-	P2[i][j];//p4+p5+p6-p2
			C[i][j+n/2]=		P1[i][j]+	P2[i][j];						//p1+p2
			C[i+n/2][j]=		P3[i][j]+	P4[i][j];						//p3+p4
			C[i+n/2][j+n/2]=	P1[i][j]+	P5[i][j]-	P3[i][j]-	P7[i][j];//p1+p5-p3-p7
		}
	}
	return C;
}
/*
4
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
1 2 3 4
5 6 7 8
1 5 9 8
2 4 6 8
*/
int main(){
	int n1,n2,m1,m2,SIZE;
	cout<<"Enter size(n1,m1),(n2,m2):";
	cin>>n1>>m1>>n2>>m2;
	SIZE=( pow(2 , (ceil(log2((float)  max(n1,max(m1,max(n2,m2)))  ))) ) ) ;
	vector<vector<int> > A(SIZE+1,vector<int>(SIZE+1)), B(SIZE+1,vector<int>(SIZE+1)), C(SIZE+1,vector<int>(SIZE+1));
	cout<<"Enter A :\n";
	for(int i=0;i<n1;i++){
		for(int j=0;j<m1;j++){
			cin>>A[i][j];
		}
	}
	cout<<"Enter B :\n";
	for(int i=0;i<n2;i++){
		for(int j=0;j<m2;j++){
			cin>>B[i][j];
		}
	}
	for(int i=n1;i<SIZE;i++){
		for(int j=m1;j<SIZE;j++){
			A[i][j]=0;
		}
	}
	for(int i=n2;i<SIZE;i++){
		for(int j=m2;j<SIZE;j++){
			B[i][j]=0;
		}
	}
	C = mul(A,B,SIZE);//C = add(A,B,n);
	//cout<<"mul:"<<n<<endl;show2(A,n,n);show2(B,n,n);
	//show2(C,n,n);
	cout<<"\n*****FINAL ANS:*****\n";
	for(int i=0;i<n1;i++){
		for(int j=0;j<m2;j++){
			cout<<C[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
