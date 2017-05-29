#include<bits/stdc++.h>
using namespace std;
#define show2d(n) for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){printf("%13d(%3d) ",dp[i][j],sol[i][j]);}cout<<'\n';}
int dp[1000][1000],sol[1000][1000];

void print_cmm(int l,int r){//l,r inclusive
    if(l==r){
        cout<<"A"<<l;
        return;
    }
    cout<<"(";
    print_cmm(l,sol[l][r]);
    cout<<")(";
    print_cmm(sol[l][r]+1,r);
    cout<<")";
}

void cmm(int n,int p[]){
    for(int i=0;i<=n;i++)for(int j=0;j<=n;j++){dp[i][j]=INT_MAX;sol[i][j]=0;if(i>=j)dp[i][j]=0;}
    //for(int i=0;i<=n;i++)dp[i][i]=0;
    for(int z=2;z<=n;z++){
        for(int i=1;i<=(n-z+1);i++){
            int j=(i+z-1),Q=INT_MAX,Qk=0;
            cout<<"\ncosts: ";
            for(int k=i;k<=j-1;k++){
                int cost=(dp[i][k]+dp[k+1][j]+p[i-1]*p[k]*p[j]);
                cout<<cost;
                if(cost<Q){
                    Q=cost;
                    Qk=k;cout<<'('<<k<<")";
                }
                cout<<" ";
            }
            dp[i][j]=Q;
            sol[i][j]=Qk;
            cout<<"\ndp(sol):-"<<endl;show2d(n);cout<<endl;
        }
    }
    cout<<"\nSEQUENCE:\n";
    print_cmm(1,n);
}
//vector<vector<int>>V(n,vector<int>a(n));
int main(){
    cout<<"Enter the no. of matrices:";
    int n;cin>>n;
    int p[n+2];
    cout<<"Enter <p0> <p1> <p2> ..... <pn> if there are n matrices and \nith matric has order <p(i-1)> <p(i)>.\n";
    for(int i=0;i<=n;i++){
        cin>>p[i];
    }
    cmm(n,p);
    cout<<"\ncost: "<<dp[1][n];
    return 0;
}
