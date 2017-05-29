#include<bits/stdc++.h>
using namespace std;
int n,*a;

int partition(int l,int h){
	int i=l,u=l,p=h;
	for(;i<=h;i++){
		if(a[i]<=a[p]){
			swap(a[i],a[u]);
			u++;
		}
	}
	swap(p,u);
	return p-1;
}

void quickSort(int l,int h){
	stack< pair<int,int> >S;
	h--;
	S.push({l,h});
	pair<int,int>p;
	while(!S.empty()){
		p=S.top();S.pop();
		l=p.first,h=p.second;
		int q=partition(l,h);
		if(q>l){
			S.push({l,q-1});
		}
		if(q<h){
			S.push({q+1,h});
		}
	}
}

int main(){
	cout<<"Enter size:";cin>>n;
	while(n<=0){
		cout<<"INVALID INPUT\nEnter size:";cin>>n;
	}
	a=new int[n+5];
	for(int i=0;i<n;i++){cin>>a[i];}
	quickSort(0,n);
	cout<<"sorted:";
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}



