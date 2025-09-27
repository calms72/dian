#include<bits/stdc++.h>
using namespace std;

string line;
map<string,string> work;
map<string,bool> vis;
string a;
string b;
int i,x;
int main(){
    ifstream file("data.txt");
    while(getline(file,line)){
        a.clear();
        b.clear();
        i=0;
        x=line.length();
        if(x==0){
            continue;
        }
        for(i=0;i<x;i++){
            if(line[i]==':'){
                i++;
                break;
            }else{
                a=a+line[i];
            }
        }
        if(i>=x-1){
            continue;
        }
        for(i;i<x;i++){
            b=b+line[i];
        }
        //cout<<a<<" "<<b<<"\n";
        work[a]=b;
        vis[a]=1;
    }
    file.close();
    while(1){
        cin>>a;
        if(a=="Quit"){
            return 0;
        }else if(vis[a]){
            cout<<work[a]<<"\n";
        }else{
            cout<<"Error\n";
        }
    }
    return 0;
}