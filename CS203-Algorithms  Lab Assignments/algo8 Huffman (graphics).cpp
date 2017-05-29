#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int x,y;
struct NODE{
    NODE*l;
    NODE*r;
    pair<int,char>val;
    NODE(pair<int,char> value){
        val=value;
    }
}*P1,*P2,*C1,*C2,*ROOT;

map<char,int>cnt;
vector<pair<int,NODE*> > v;
map<char,string>code;
map<string,char>decode;

ostream& operator<<(ostream &out,map<char,string>m){
    out<<"Code\n";
    for(auto u:m){
        out<<u.first<<"  -->  "<<u.second<<endl;
    }
    return out;
}

ostream& operator<<(ostream &out,map<string,char>m){
    out<<"Decode\n";
    for(auto u:m){
        out<<u.first<<" <-- "<<u.second<<endl;
    }
    return out;
}

void util(NODE *par,string s="",int X=x/2,int Y=y/5){
    //cout<<s<<endl;
	if(par==NULL){
		return;
	}
	setfillstyle(EMPTY_FILL+1, BLUE);fillellipse(X,Y,10,10);
	if(s==""){
        outtextxy (X,Y,"");
    }
	//cout<<"info : "<<par->val.second<<endl;
	if(par->l==NULL && par->r==NULL){
		code[par->val.second]=s;
		decode[s]=par->val.second;
		//cout<<"CODE : "<<s<<", value: "<<par->val.second<<", count:"<<-par->val.first<<endl;
		char str[]={par->val.second,'\0'};
        outtextxy (X,Y,str);
		return ;
	}
	//cout<<"\nleft\n";
	util(par->l,s+"0",X-50,Y+50);
	setcolor(RED);
	line(X,Y,X-50,Y+50);
	//cout<<"right\n";
	util(par->r,s+"1",X+50,Y+50);
	setcolor(RED);
	line(X,Y,X+50,Y+50);
	//cout<<"\nback\n";
}

void get_code_and_decode(){
	util(ROOT);
}

int main(){

    int gd=DETECT,gm;
    initwindow(1400, 1000);
    setbkcolor(WHITE);
    x=getmaxx(),y=getmaxy();
    setcolor(WHITE);
    line(0,100,x,100);
    int arr[]={0,100,x,100,x,y,0,y,0,100},arr1[]={1,1,x-1,1,x-1,100,1,100,1,1};
    setfillstyle(EMPTY_FILL+1, WHITE);fillpoly(5,arr);
    setfillstyle(EMPTY_FILL+1, CYAN);fillpoly(5,arr1);
    setcolor(RED);
    outtextxy(20,20,"!! HUFFMAN CODING !!");
    cout<<"Press 1 to check the working on the default string stored in file 'text.txt'\nPress 0 to enter a string\n";
    int flagfile=0;
    cin>>flagfile;
    fflush(stdin);
    if(flagfile==1)freopen("text.txt","rb+",stdin);
    cout<<"Enter string:";
    string a;
    getline(cin,a);
    cout<<a<<endl;
    for(int i=0;i<a.length();i++){
        cnt[a[i]]++;
    }
    for(auto u:cnt){
        //cout<<"COUNT:"<<u.second<<"="<<u.first<<endl;
        NODE *n=new NODE(make_pair(-u.second,u.first));
        n->r = n->l = NULL;
        v.push_back({-u.second,n});
    }
    priority_queue< pair<int,NODE*>  > pq;
    for(auto u:v){
        pq.push(u);
    }
    C1 = pq.top().second;pq.pop();
    //cout<<"Key:"<<(C1->val.first)<<endl;
    while(!pq.empty()){
        pair<int,NODE*> y=pq.top();pq.pop();
        C2 = y.second;
        //cout<<"Key:"<<(C2->val.first)<<endl;

        int fz=(C2->val.first)+(C1->val.first);
        NODE*n=new NODE(make_pair(fz,'\0'));n->l=C1;n->r=C2;
        pair<int,NODE*> z=make_pair(fz,n);
        pq.push(z);
        //cout<<"Key Inserted:"<<(fz)<<endl;

        pair<int,NODE*> x=pq.top();pq.pop();
        C1 = x.second;
        //cout<<"Key:"<<(C2->val.first)<<endl;
    }
    ROOT = C1;
    get_code_and_decode();
    cout<<code;
    cout<<decode;
    cout<<"*********** ENCODED STRING:\n";
    string coded="";
    for(int i=0;i<a.length();i++){
        coded=coded+code[a[i]];
    }
    cout<<coded<<endl;

    cout<<"\n*********** DECODED STRING:\n";
    int i=0;
    while(i<coded.length()){
        int k=0;bool flag=0;
        while(!flag){
            k++;
            if(i+k>coded.size()){
                cout<<"\nTERMINATING @ THE ORDER OF KRISHNKANT ";
                return 0;
            }
            string sub=coded.substr(i,k);
            if(decode[sub]!='\0'){
                flag=1;
                cout<<decode[sub];
                break;
            }
        }
        i=i+k;
    }
    outtextxy (x/2-25,50,"!! COMPLETED !!");
    getch();
	closegraph();
    return 0;
}
