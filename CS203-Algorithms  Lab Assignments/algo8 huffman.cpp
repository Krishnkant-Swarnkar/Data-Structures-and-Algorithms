#include<bits/stdc++.h>
using namespace std;

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
        out<<u.first<<" "<<u.second<<endl;
    }
    return out;
}

ostream& operator<<(ostream &out,map<string,char>m){
    out<<"Decode\n";
    for(auto u:m){
        out<<u.first<<" "<<u.second<<endl;
    }
    return out;
}

void util(NODE *par,string s=""){
    //cout<<s<<endl;
	if(par==NULL){
		return;
	}
	//cout<<"info : "<<par->val.second<<endl;
	if(par->l==NULL && par->r==NULL){
		code[par->val.second]=s;
		decode[s]=par->val.second;
		//cout<<"CODE : "<<s<<", value: "<<par->val.second<<", count:"<<-par->val.first<<endl;
		return ;
	}
	//cout<<"\nleft\n";
	util(par->l,s+"0");
	//cout<<"right\n";
	util(par->r,s+"1");
	//cout<<"\nback\n";
}

void get_code_and_decode(){
	util(ROOT);
}

int main(){
    freopen("text.txt","rb+",stdin);
    string a;
    getline(cin,a);
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
    //cout<<"Key:"<<(C1->val.first)<<", value:"<<(C1->val.second)<<endl;
    while(!pq.empty()){
        pair<int,NODE*> y=pq.top();pq.pop();
        C2 = y.second;
        //cout<<"Key:"<<(C2->val.first)<<", value:"<<(C2->val.second)<<endl;

        int fz=(C2->val.first)+(C1->val.first);
        NODE*n=new NODE(make_pair(fz,'\0'));n->l=C1;n->r=C2;
        pair<int,NODE*> z=make_pair(fz,n);
        pq.push(z);
        //cout<<"Key Inserted:"<<(fz)<<endl;

        pair<int,NODE*> x=pq.top();pq.pop();
        C1 = x.second;
        //cout<<"Key:"<<(C1->val.first)<<", value:"<<(C1->val.second)<<endl;
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


    return 0;
}
