#include<bits/stdc++.h>
using namespace std;
#define weight first
#define price second

#define debug(a)    			cerr<<#a<<": ";for(auto i:a)cerr<<i<<" ";cerr<<'\n';
#define show1(a,n) 			cout<<endl;for(int i=0;i<n;i++){cout<<a[i]<<" ";}
#define show2(a,n,m) 			cout<<endl;for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<" ";}cout<<endl;}

#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

int bottom_up_knapsack(int W,vector<pair<int,int> >item){
    int n=item.size();
    int dp[W+1][n+1];
    pair<int,int>t_back[W+1][n+1];
    for(int i=0;i<=n;i++)for(int j=0;j<=W;j++)dp[j][i]=0,t_back[j][i]=make_pair(0,0);
    for(int i=0;i<=n;i++){
        for(int w=0;w<=W;w++){
            if(w==0 || i==0)dp[w][i]=0;
            else if(w-item[i].weight>=0){
                int a=dp[w][i-1],b=(dp[w-item[i].weight][i-1])+(item[i].price);
                if(a < b){ dp[w][i]=b; t_back[w][i]=make_pair(w-item[i].weight,i-1); }
                else{ dp[w][i]=a; }
            }
            else{ dp[w][i]=dp[w][i-1]; }
        }
    }
    /*pair<int,int>p=make_pair(W,n);
    while(p.first!=0 && p.second !=0){
        trace2(p.first,p.second)
        if(p.second==t_back[p.first][p.second].first)
            cout<<"item taken with cost:"<<p.first-t_back[p.first][p.second].first<<endl;
        p=t_back[p.first][p.second];
        trace2(p.first,p.second);
    }
    cout<<"item taken with cost:"<<p.first-t_back[p.first][p.second].first<<endl;*/
    return dp[W][n];
}
/*sample input:
3
10 60
20 100
30 120
50
*/
int main(){
    int W,w,p,n;
    cout<<"Enter no. of items:";
    cin>>n;
    vector<pair<int,int> >item;
    item.push_back({0,0});
    cout<<"Enter <weight> <price> for each item:\n";
    for(int i=0;i<n;i++){
        cin>>w>>p;
        item.push_back({w,p});
    }
    cout<<"Enter the weight capacity of Knapsack:";
    cin>>W;
    vector<bool>taken(n+1,0);
    cout<<"Max price :"<<bottom_up_knapsack(W,item);
    return 0;
}
