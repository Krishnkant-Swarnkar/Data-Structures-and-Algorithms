#include<bits/stdc++.h>
using namespace std;
int *a,SIZE;

void merge(int L,int M,int H){
	cout<<"call for merge:"<<L<<" "<<M<<" "<<H<<endl;
	int k=0,i=L,j=M,B[H-L+5];
	while(i<M && j<H){
		if(a[i]<a[j])B[k++]=a[i++];
		else B[k++]=a[j++];
	}
	while(i<M){
		B[k++]=a[i++];
	}
	while(j<H){
		B[k++]=a[j++];
	}
	for(int i=0;i<k;i++){
		a[L+i]=B[i];
	}
	cout<<"array:";
	for(int i=L;i<H;i++){
		if(a[i]==INT_MAX)break;
		cout<<a[i]<<" ";
	}
	cout<<endl;
}

void mergesort(){
	for(int l=0;l<log2(SIZE);l++){
		int jump=pow(2,l),i=0,j=jump,I=i,J=j;
		while(I<SIZE){
			merge(I,J,J+jump);
			I=J+jump;
			J=J+jump*2;
		}
	}
}

int main(){
	int i,n;
	cout<<"Enter size:";cin>>n;
	while(n<=0){
		cout<<"INVALID INPUT\nEnter size:";cin>>n;
	}
	cout<<"Enter Array:";
	SIZE=pow(2,ceil(log2((double)n)) );
	a=new int[SIZE+1];
	for(i=0;i<n;i++){cin>>a[i];}
	for(i=n;i<=SIZE;i++){a[i]=INT_MAX;}
	mergesort();
	cout<<"\nSORTED ORDER:\n";
	i=0;
	while(i<SIZE && a[i]!=INT_MAX){
		cout<<a[i++]<<" ";
	}
	return 0;
}
/*8
8 4 5 7 9 2 6 3*/


