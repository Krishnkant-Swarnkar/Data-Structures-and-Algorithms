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
clock_t start;

string fill(string s,int mxn){
	while(s.length()<mxn){
		s="0"+s;
	}
	return s;
}

string add_ab(string a,string b){
	//trace3("ADD",a,b);
	int la,lb;
	la=a.length();
	lb=b.length();
	int mx=max(la,lb);
	int n=(2*mx+1)/2;
	a=fill(a,mx);
	b=fill(b,mx);
	int carry=0;
	string res="";
	for(int i=mx-1;i>=0;i--){
		int aa=a[i]-48,bb=b[i]-48;
		int r=(aa+bb+carry)%2;
		carry=(aa+bb+carry)/2;
		res=(char)(r+48)+res;
	}
	res=(char)(carry+48)+res;
	return res;
}

string mul(char a,string b){
	if(a=='1')return b;
	string s="";
	for(int i=0;i<b.length();i++){
		s=s+"0";
	}
	return s;
}

string zero(int l){
	string s="";
	for(int i=0;i<l;i++){
		s=s+"0";
	}
	return s;
}

void ready(string &a,string &b)
{
	int la,lb;
	la=a.length();
	lb=b.length();
	int mx=max(la,lb);
	int n=(2*mx+1)/2;
	a=fill(a,mx);
	b=fill(b,mx);	
}

long long bintodec(string b){
	ll f=1;
	ll ans=0;
	for(int i=b.length()-1;i>=0;i--){
		ans=ans+f*(b[i]-48);
		f=f*2;
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(false);cout.tie(false);
	string a,b;
	cin>>a>>b;
	ready(a,b);
	int la=a.length(),lb=b.length();
	string res="";
	for(int i=0;i<lb;i++){
		res=res+"0";
	}
	for(int i=la-1;i>=0;i--){
		string temp=mul(a[i],b)+zero(la-1-i);
		ready(res,temp);
		res=add_ab(res,temp);
	}	
	cout<<res;
	cout<<"\nans:"<<bintodec(res);
	return 0;
}



