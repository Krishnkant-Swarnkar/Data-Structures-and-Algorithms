#include<bits/stdc++.h>
using namespace std;

class Heap{
	int *a;
	int SIZE,max_size=1000;
	
	void BuildHeap(){
		for(int i=SIZE/2;i>=1;i--){
			minHeapify(i);
		}
	}
	void minHeapify(int i){
		int l=2*i,r=2*i+1,lesser=i;
		if(l<=SIZE && a[l]<a[lesser]){
			lesser=l;	
		}
		if(r<=SIZE && a[r]<a[lesser]){
			lesser=r;
		}
		if(lesser!=i){
			swap(a[i],a[lesser]);
			minHeapify(lesser);
		}
	}
	void update(int i){
		if(i==1)return;
		if(a[i/2]>a[i]){
			swap(a[i/2],a[i]);
			update(i/2);
		}
	} 
	
	public:
	Heap(){
		a=new int[max_size];
		SIZE=0;
	}
	Heap(int *arr,int l,int r){
		SIZE=0;
		a=new int[max_size];
		for(int i=l;i<r;i++){
			Insert(arr[i]);	
		}
	}
	Heap(int n){
		SIZE=0;
		max_size=n;
		a=new int[max_size];
	}	

	
	int Delete(){
		swap(a[1],a[SIZE]);
		SIZE--;
		minHeapify(1);
		return a[SIZE+1];
	}
	bool Insert(int x){
		a[++SIZE]=x;
		update(SIZE);
		return 1;
	}
	bool IsEmpty(){
		return (SIZE>0)?0:1;
	}
	int getMin(){
		if(SIZE>0){
			return a[1];
		}
		return INT_MAX;
	}
	void Sort(int arr[]){
		int i=0;
		while(!IsEmpty()){
			int temp=Delete();
			arr[i++]=temp;
		}
	}
	void show(){
		cout<<"\nshow:"<<'\n';
		for(int i=1;i<=SIZE;i++){
			cout<<a[i]<<" ";
		}
		cout<<'\n';
	}
	void inorder(int i){
		
		int L=2*i,R=2*i+1;
		if(i>SIZE){return ;}
		inorder(L);
		cout<<"::"<<a[i];
		inorder(R);
	}
};

int Sort(int arr[],int l,int r){
	Heap H(arr,l,r);
	H.show();
	cout<<"Inorder:\n";
	H.inorder(1);
	cout<<'\n';
	H.Sort(arr);
}


int main(){
	int n;
	cout<<"Enter Size : ";
	cin>>n;
	if(n<0){cout<<"!! Mischievious Activity Detected \nTerminating On the Order of @King\n";return 0;}
	cout<<"Enter Elements : ";
	int arr[n+5];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	Sort(arr,0,n);
	cout<<"Sorter Order   : "; 
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	
	return 0;
}
